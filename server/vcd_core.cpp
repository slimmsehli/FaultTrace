#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

namespace py = pybind11;

struct TimeValue {
    long long time;
    std::string value;
};

class VCDParser {
public:
    std::map<std::string, std::vector<TimeValue>> signals;
    std::string timescale_unit = "ns";
    int timescale_mag = 1;
    long long max_time = 0;

    VCDParser(const std::string& path) {
        parse(path);
    }

    void parse(const std::string& path) {
        std::ifstream file(path);
        std::string line, word;
        std::map<std::string, std::string> id_to_name;
        long long current_time = 0;

        while (std::getline(file, line)) {
            if (line.empty()) continue;
            
            if (line[0] == '$') {
                if (line.find("$timescale") != std::string::npos) {
                    // Simplified timescale parsing
                } else if (line.find("$var") != std::string::npos) {
                    std::stringstream ss(line);
                    std::string tmp, type, size, id, name;
                    ss >> tmp >> type >> size >> id >> name;
                    id_to_name[id] = name;
                }
                continue;
            }

            if (line[0] == '#') {
                current_time = std::stoll(line.substr(1));
                if (current_time > max_time) max_time = current_time;
            } else {
                // Handle value changes (e.g., "1!", "b1010 a")
                parse_value_change(line, current_time, id_to_name);
            }
        }
    }

    void parse_value_change(const std::string& line, long long t, std::map<std::string, std::string>& ids) {
        if (line[0] == 'b' || line[0] == 'B') {
            size_t space = line.find(' ');
            std::string val = line.substr(0, space);
            std::string id = line.substr(space + 1);
            if (ids.count(id)) signals[ids[id]].push_back({t, val});
        } else {
            std::string val = line.substr(0, 1);
            std::string id = line.substr(1);
            if (ids.count(id)) signals[ids[id]].push_back({t, val});
        }
    }

    std::string get_value_at(const std::string& sig, long long t) {
        if (signals.find(sig) == signals.end()) return "Error: Signal not found";
        const auto& tvs = signals[sig];
        auto it = std::upper_bound(tvs.begin(), tvs.end(), t, [](long long val, const TimeValue& tv) {
            return val < tv.time;
        });
        if (it == tvs.begin()) return tvs[0].value;
        return std::prev(it)->value;
    }
};

PYBIND11_MODULE(vcd_cpp, m) {
    py::class_<VCDParser>(m, "VCDParser")
        .def(py::init<const std::string&>())
        .def("get_value_at", &VCDParser::get_value_at)
        .def_readonly("max_time", &VCDParser::max_time)
        .def_readonly("timescale_unit", &VCDParser::timescale_unit)
        .def_readonly("signals", &VCDParser::signals);
}
