// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtb_top__Syms.h"


VL_ATTR_COLD void Vtb_top___024root__trace_init_sub__TOP__0(Vtb_top___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("tb_top", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+207,0,"CACHE_LINES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+208,0,"LINE_WORDS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+207,0,"ADDR_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+209,0,"CLK_PERIOD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+203,0,"clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"rst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+2,0,"errors",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBit(c+3,0,"c0_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"c1_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+5,0,"c0_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+6,0,"c1_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+7,0,"c0_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+8,0,"c1_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+9,0,"c0_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+10,0,"c1_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+26,0,"c0_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+27,0,"c1_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+28,0,"c0_ack",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+29,0,"c1_ack",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+30,0,"bus_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+31,0,"bus_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+32,0,"bus_cmd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+33,0,"cnt_busrd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+34,0,"cnt_busInv",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+35,0,"cnt_buswb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+11,0,"cpu_read__Vstatic__timeout",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+12,0,"cpu_write__Vstatic__timeout",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+13,0,"check_mesi__Vstatic__actual",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+14,0,"rdata0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+15,0,"rdata1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+16,0,"bus_rd_before",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+17,0,"bus_inv_before",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+18,0,"bus_wb_before",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->pushPrefix("dut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+207,0,"CACHE_LINES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+208,0,"LINE_WORDS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+207,0,"ADDR_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+210,0,"N_CORES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+203,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+3,0,"c0_req",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+5,0,"c0_we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+7,0,"c0_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+9,0,"c0_wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+26,0,"c0_rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+28,0,"c0_ack",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"c1_req",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+6,0,"c1_we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+8,0,"c1_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+10,0,"c1_wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+27,0,"c1_rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+29,0,"c1_ack",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+36,0,"bus_grant",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+37,0,"bus_req_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+38,0,"bus_addr_c0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+39,0,"bus_addr_c1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+40,0,"bus_cmd_c0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+41,0,"bus_cmd_c1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declArray(c+42,0,"bus_data_c0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declArray(c+46,0,"bus_data_c1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declBit(c+50,0,"bus_drive_c0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+51,0,"bus_drive_c1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+30,0,"bus_valid_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+31,0,"bus_addr_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+32,0,"bus_cmd_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declArray(c+52,0,"bus_wdata_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declArray(c+56,0,"snoop_rdata_c0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declArray(c+60,0,"snoop_rdata_c1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declBit(c+64,0,"snoop_shared_c0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+65,0,"snoop_shared_c1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+66,0,"snoop_dirty_c0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+67,0,"snoop_dirty_c1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+68,0,"snoop_shared_any",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+69,0,"snoop_dirty_any",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+70,0,"snoop_rdata_any",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declArray(c+74,0,"mem_rdata_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declBit(c+78,0,"mem_valid_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+79,0,"fill_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->pushPrefix("u_arb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+210,0,"N",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+203,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+37,0,"req",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+36,0,"grant",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+83,0,"last",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->pushPrefix("arb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+84,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+85,0,"j",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_cache0", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+207,0,"CACHE_LINES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+208,0,"LINE_WORDS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+207,0,"ADDR_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+211,0,"ID",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+203,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+3,0,"cpu_req",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+5,0,"cpu_we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+7,0,"cpu_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+9,0,"cpu_wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+26,0,"cpu_rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+28,0,"cpu_ack",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+86,0,"bus_req",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+87,0,"bus_grant",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+30,0,"bus_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+31,0,"bus_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+32,0,"bus_cmd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declArray(c+79,0,"bus_wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declArray(c+56,0,"bus_rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declBit(c+64,0,"bus_shared",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+66,0,"bus_dirty",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+50,0,"bus_drive",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+38,0,"bus_out_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+40,0,"bus_out_cmd",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declArray(c+42,0,"bus_out_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declBus(c+212,0,"INDEX_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+210,0,"OFFSET_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+212,0,"TAG_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("tag", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 8; ++i) {
        tracep->declBus(c+88+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 2,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("mesi", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 8; ++i) {
        tracep->declBus(c+96+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 1,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("data", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 8; ++i) {
        tracep->declArray(c+104+i*4,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 127,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+20,0,"cpu_offset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+21,0,"cpu_index",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+22,0,"cpu_tag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+204,0,"hit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+136,0,"snoop_index",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+137,0,"snoop_tag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+138,0,"snoop_hit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+213,0,"ST_IDLE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+214,0,"ST_HIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+215,0,"ST_MISS_ARB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+216,0,"ST_MISS_TX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+217,0,"ST_MISS_WAIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+218,0,"ST_WB_ARB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+219,0,"ST_WB_TX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+139,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+140,0,"pending_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+141,0,"pending_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+142,0,"pending_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+143,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_cache1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+207,0,"CACHE_LINES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+208,0,"LINE_WORDS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+207,0,"ADDR_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+220,0,"ID",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+203,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"cpu_req",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+6,0,"cpu_we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+8,0,"cpu_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+10,0,"cpu_wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+27,0,"cpu_rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+29,0,"cpu_ack",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+144,0,"bus_req",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+145,0,"bus_grant",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+30,0,"bus_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+31,0,"bus_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+32,0,"bus_cmd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declArray(c+79,0,"bus_wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declArray(c+60,0,"bus_rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declBit(c+65,0,"bus_shared",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+67,0,"bus_dirty",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+51,0,"bus_drive",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+39,0,"bus_out_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+41,0,"bus_out_cmd",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declArray(c+46,0,"bus_out_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declBus(c+212,0,"INDEX_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+210,0,"OFFSET_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+212,0,"TAG_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("tag", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 8; ++i) {
        tracep->declBus(c+146+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 2,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("mesi", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 8; ++i) {
        tracep->declBus(c+154+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 1,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("data", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 8; ++i) {
        tracep->declArray(c+162+i*4,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 127,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+23,0,"cpu_offset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+24,0,"cpu_index",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+25,0,"cpu_tag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+205,0,"hit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+194,0,"snoop_index",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+195,0,"snoop_tag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+196,0,"snoop_hit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+213,0,"ST_IDLE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+214,0,"ST_HIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+215,0,"ST_MISS_ARB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+216,0,"ST_MISS_TX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+217,0,"ST_MISS_WAIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+218,0,"ST_WB_ARB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+219,0,"ST_WB_TX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+197,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+198,0,"pending_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+199,0,"pending_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+200,0,"pending_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+201,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_mem", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+207,0,"ADDR_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+208,0,"LINE_WORDS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+221,0,"DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+203,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+30,0,"bus_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+31,0,"bus_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+32,0,"bus_cmd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declArray(c+52,0,"bus_wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declBit(c+69,0,"bus_dirty",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+74,0,"mem_rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declBit(c+78,0,"mem_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+222,0,"LINE_BYTES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+223,0,"LINES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+206,0,"k",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+202,0,"base",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("stress", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+19,0,"iter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+224,0,"expected_val",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtb_top___024root__trace_init_top(Vtb_top___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root__trace_init_top\n"); );
    // Body
    Vtb_top___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtb_top___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vtb_top___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtb_top___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtb_top___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtb_top___024root__trace_register(Vtb_top___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root__trace_register\n"); );
    // Body
    tracep->addConstCb(&Vtb_top___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vtb_top___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vtb_top___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vtb_top___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtb_top___024root__trace_const_0_sub_0(Vtb_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtb_top___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root__trace_const_0\n"); );
    // Init
    Vtb_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_top___024root*>(voidSelf);
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtb_top___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtb_top___024root__trace_const_0_sub_0(Vtb_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root__trace_const_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+207,(8U),32);
    bufp->fullIData(oldp+208,(4U),32);
    bufp->fullIData(oldp+209,(0xaU),32);
    bufp->fullIData(oldp+210,(2U),32);
    bufp->fullIData(oldp+211,(0U),32);
    bufp->fullIData(oldp+212,(3U),32);
    bufp->fullCData(oldp+213,(0U),3);
    bufp->fullCData(oldp+214,(1U),3);
    bufp->fullCData(oldp+215,(2U),3);
    bufp->fullCData(oldp+216,(3U),3);
    bufp->fullCData(oldp+217,(4U),3);
    bufp->fullCData(oldp+218,(5U),3);
    bufp->fullCData(oldp+219,(6U),3);
    bufp->fullIData(oldp+220,(1U),32);
    bufp->fullIData(oldp+221,(0x100U),32);
    bufp->fullIData(oldp+222,(0x10U),32);
    bufp->fullIData(oldp+223,(0x40U),32);
    bufp->fullIData(oldp+224,(vlSelf->tb_top__DOT__stress__DOT__expected_val),32);
}

VL_ATTR_COLD void Vtb_top___024root__trace_full_0_sub_0(Vtb_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtb_top___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root__trace_full_0\n"); );
    // Init
    Vtb_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_top___024root*>(voidSelf);
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtb_top___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtb_top___024root__trace_full_0_sub_0(Vtb_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root__trace_full_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    VlWide<4>/*127:0*/ __Vtemp_3;
    // Body
    bufp->fullBit(oldp+1,(vlSelf->tb_top__DOT__rst));
    bufp->fullIData(oldp+2,(vlSelf->tb_top__DOT__errors),32);
    bufp->fullBit(oldp+3,(vlSelf->tb_top__DOT__c0_req));
    bufp->fullBit(oldp+4,(vlSelf->tb_top__DOT__c1_req));
    bufp->fullBit(oldp+5,(vlSelf->tb_top__DOT__c0_we));
    bufp->fullBit(oldp+6,(vlSelf->tb_top__DOT__c1_we));
    bufp->fullCData(oldp+7,(vlSelf->tb_top__DOT__c0_addr),8);
    bufp->fullCData(oldp+8,(vlSelf->tb_top__DOT__c1_addr),8);
    bufp->fullIData(oldp+9,(vlSelf->tb_top__DOT__c0_wdata),32);
    bufp->fullIData(oldp+10,(vlSelf->tb_top__DOT__c1_wdata),32);
    bufp->fullIData(oldp+11,(vlSelf->tb_top__DOT__cpu_read__Vstatic__timeout),32);
    bufp->fullIData(oldp+12,(vlSelf->tb_top__DOT__cpu_write__Vstatic__timeout),32);
    bufp->fullCData(oldp+13,(vlSelf->tb_top__DOT__check_mesi__Vstatic__actual),2);
    bufp->fullIData(oldp+14,(vlSelf->tb_top__DOT__rdata0),32);
    bufp->fullIData(oldp+15,(vlSelf->tb_top__DOT__rdata1),32);
    bufp->fullIData(oldp+16,(vlSelf->tb_top__DOT__bus_rd_before),32);
    bufp->fullIData(oldp+17,(vlSelf->tb_top__DOT__bus_inv_before),32);
    bufp->fullIData(oldp+18,(vlSelf->tb_top__DOT__bus_wb_before),32);
    bufp->fullIData(oldp+19,(vlSelf->tb_top__DOT__stress__DOT__iter),32);
    bufp->fullCData(oldp+20,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__cpu_offset),2);
    bufp->fullCData(oldp+21,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__cpu_index),3);
    bufp->fullCData(oldp+22,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__cpu_tag),3);
    bufp->fullCData(oldp+23,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__cpu_offset),2);
    bufp->fullCData(oldp+24,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__cpu_index),3);
    bufp->fullCData(oldp+25,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__cpu_tag),3);
    bufp->fullIData(oldp+26,(vlSelf->tb_top__DOT__c0_rdata),32);
    bufp->fullIData(oldp+27,(vlSelf->tb_top__DOT__c1_rdata),32);
    bufp->fullBit(oldp+28,(vlSelf->tb_top__DOT__c0_ack));
    bufp->fullBit(oldp+29,(vlSelf->tb_top__DOT__c1_ack));
    bufp->fullBit(oldp+30,(vlSelf->tb_top__DOT__dut__DOT__bus_valid_w));
    bufp->fullCData(oldp+31,(vlSelf->tb_top__DOT__dut__DOT__bus_addr_w),8);
    bufp->fullCData(oldp+32,(vlSelf->tb_top__DOT__dut__DOT__bus_cmd_w),2);
    bufp->fullIData(oldp+33,(vlSelf->tb_top__DOT__cnt_busrd),32);
    bufp->fullIData(oldp+34,(vlSelf->tb_top__DOT__cnt_busInv),32);
    bufp->fullIData(oldp+35,(vlSelf->tb_top__DOT__cnt_buswb),32);
    bufp->fullCData(oldp+36,(vlSelf->tb_top__DOT__dut__DOT__bus_grant),2);
    bufp->fullCData(oldp+37,(vlSelf->tb_top__DOT__dut__DOT__bus_req_w),2);
    bufp->fullCData(oldp+38,(vlSelf->tb_top__DOT__dut__DOT__bus_addr_c0),8);
    bufp->fullCData(oldp+39,(vlSelf->tb_top__DOT__dut__DOT__bus_addr_c1),8);
    bufp->fullCData(oldp+40,(vlSelf->tb_top__DOT__dut__DOT__bus_cmd_c0),2);
    bufp->fullCData(oldp+41,(vlSelf->tb_top__DOT__dut__DOT__bus_cmd_c1),2);
    bufp->fullWData(oldp+42,(vlSelf->tb_top__DOT__dut__DOT__bus_data_c0),128);
    bufp->fullWData(oldp+46,(vlSelf->tb_top__DOT__dut__DOT__bus_data_c1),128);
    bufp->fullBit(oldp+50,(vlSelf->tb_top__DOT__dut__DOT__bus_drive_c0));
    bufp->fullBit(oldp+51,(vlSelf->tb_top__DOT__dut__DOT__bus_drive_c1));
    bufp->fullWData(oldp+52,(vlSelf->tb_top__DOT__dut__DOT__bus_wdata_w),128);
    bufp->fullWData(oldp+56,(vlSelf->tb_top__DOT__dut__DOT__snoop_rdata_c0),128);
    bufp->fullWData(oldp+60,(vlSelf->tb_top__DOT__dut__DOT__snoop_rdata_c1),128);
    bufp->fullBit(oldp+64,(vlSelf->tb_top__DOT__dut__DOT__snoop_shared_c0));
    bufp->fullBit(oldp+65,(vlSelf->tb_top__DOT__dut__DOT__snoop_shared_c1));
    bufp->fullBit(oldp+66,(vlSelf->tb_top__DOT__dut__DOT__snoop_dirty_c0));
    bufp->fullBit(oldp+67,(vlSelf->tb_top__DOT__dut__DOT__snoop_dirty_c1));
    bufp->fullBit(oldp+68,(((IData)(vlSelf->tb_top__DOT__dut__DOT__snoop_shared_c0) 
                            | (IData)(vlSelf->tb_top__DOT__dut__DOT__snoop_shared_c1))));
    bufp->fullBit(oldp+69,(vlSelf->tb_top__DOT__dut__DOT__snoop_dirty_any));
    if (vlSelf->tb_top__DOT__dut__DOT__snoop_dirty_c0) {
        __Vtemp_3[0U] = vlSelf->tb_top__DOT__dut__DOT__snoop_rdata_c0[0U];
        __Vtemp_3[1U] = vlSelf->tb_top__DOT__dut__DOT__snoop_rdata_c0[1U];
        __Vtemp_3[2U] = vlSelf->tb_top__DOT__dut__DOT__snoop_rdata_c0[2U];
        __Vtemp_3[3U] = vlSelf->tb_top__DOT__dut__DOT__snoop_rdata_c0[3U];
    } else if (vlSelf->tb_top__DOT__dut__DOT__snoop_dirty_c1) {
        __Vtemp_3[0U] = vlSelf->tb_top__DOT__dut__DOT__snoop_rdata_c1[0U];
        __Vtemp_3[1U] = vlSelf->tb_top__DOT__dut__DOT__snoop_rdata_c1[1U];
        __Vtemp_3[2U] = vlSelf->tb_top__DOT__dut__DOT__snoop_rdata_c1[2U];
        __Vtemp_3[3U] = vlSelf->tb_top__DOT__dut__DOT__snoop_rdata_c1[3U];
    } else {
        __Vtemp_3[0U] = 0U;
        __Vtemp_3[1U] = 0U;
        __Vtemp_3[2U] = 0U;
        __Vtemp_3[3U] = 0U;
    }
    bufp->fullWData(oldp+70,(__Vtemp_3),128);
    bufp->fullWData(oldp+74,(vlSelf->tb_top__DOT__dut__DOT__mem_rdata_w),128);
    bufp->fullBit(oldp+78,(vlSelf->tb_top__DOT__dut__DOT__mem_valid_w));
    bufp->fullWData(oldp+79,(vlSelf->tb_top__DOT__dut__DOT__fill_data),128);
    bufp->fullBit(oldp+83,(vlSelf->tb_top__DOT__dut__DOT__u_arb__DOT__last));
    bufp->fullIData(oldp+84,(vlSelf->tb_top__DOT__dut__DOT__u_arb__DOT__arb__DOT__i),32);
    bufp->fullIData(oldp+85,(vlSelf->tb_top__DOT__dut__DOT__u_arb__DOT__arb__DOT__j),32);
    bufp->fullBit(oldp+86,(vlSelf->tb_top__DOT__dut__DOT____Vcellout__u_cache0__bus_req));
    bufp->fullBit(oldp+87,((1U & (IData)(vlSelf->tb_top__DOT__dut__DOT__bus_grant))));
    bufp->fullCData(oldp+88,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__tag[0]),3);
    bufp->fullCData(oldp+89,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__tag[1]),3);
    bufp->fullCData(oldp+90,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__tag[2]),3);
    bufp->fullCData(oldp+91,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__tag[3]),3);
    bufp->fullCData(oldp+92,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__tag[4]),3);
    bufp->fullCData(oldp+93,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__tag[5]),3);
    bufp->fullCData(oldp+94,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__tag[6]),3);
    bufp->fullCData(oldp+95,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__tag[7]),3);
    bufp->fullCData(oldp+96,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi[0]),2);
    bufp->fullCData(oldp+97,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi[1]),2);
    bufp->fullCData(oldp+98,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi[2]),2);
    bufp->fullCData(oldp+99,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi[3]),2);
    bufp->fullCData(oldp+100,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi[4]),2);
    bufp->fullCData(oldp+101,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi[5]),2);
    bufp->fullCData(oldp+102,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi[6]),2);
    bufp->fullCData(oldp+103,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi[7]),2);
    bufp->fullWData(oldp+104,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data[0]),128);
    bufp->fullWData(oldp+108,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data[1]),128);
    bufp->fullWData(oldp+112,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data[2]),128);
    bufp->fullWData(oldp+116,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data[3]),128);
    bufp->fullWData(oldp+120,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data[4]),128);
    bufp->fullWData(oldp+124,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data[5]),128);
    bufp->fullWData(oldp+128,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data[6]),128);
    bufp->fullWData(oldp+132,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__data[7]),128);
    bufp->fullCData(oldp+136,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__snoop_index),3);
    bufp->fullCData(oldp+137,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__snoop_tag),3);
    bufp->fullBit(oldp+138,(((IData)(vlSelf->tb_top__DOT__dut__DOT__bus_valid_w) 
                             & ((~ (IData)(vlSelf->tb_top__DOT__dut__DOT__bus_drive_c0)) 
                                & ((0U != vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi
                                    [vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__snoop_index]) 
                                   & (vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__tag
                                      [vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__snoop_index] 
                                      == (IData)(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__snoop_tag)))))));
    bufp->fullCData(oldp+139,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__state),3);
    bufp->fullBit(oldp+140,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__pending_we));
    bufp->fullCData(oldp+141,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__pending_addr),8);
    bufp->fullIData(oldp+142,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__pending_wdata),32);
    bufp->fullIData(oldp+143,(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__i),32);
    bufp->fullBit(oldp+144,(vlSelf->tb_top__DOT__dut__DOT____Vcellout__u_cache1__bus_req));
    bufp->fullBit(oldp+145,((1U & ((IData)(vlSelf->tb_top__DOT__dut__DOT__bus_grant) 
                                   >> 1U))));
    bufp->fullCData(oldp+146,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__tag[0]),3);
    bufp->fullCData(oldp+147,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__tag[1]),3);
    bufp->fullCData(oldp+148,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__tag[2]),3);
    bufp->fullCData(oldp+149,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__tag[3]),3);
    bufp->fullCData(oldp+150,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__tag[4]),3);
    bufp->fullCData(oldp+151,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__tag[5]),3);
    bufp->fullCData(oldp+152,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__tag[6]),3);
    bufp->fullCData(oldp+153,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__tag[7]),3);
    bufp->fullCData(oldp+154,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi[0]),2);
    bufp->fullCData(oldp+155,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi[1]),2);
    bufp->fullCData(oldp+156,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi[2]),2);
    bufp->fullCData(oldp+157,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi[3]),2);
    bufp->fullCData(oldp+158,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi[4]),2);
    bufp->fullCData(oldp+159,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi[5]),2);
    bufp->fullCData(oldp+160,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi[6]),2);
    bufp->fullCData(oldp+161,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi[7]),2);
    bufp->fullWData(oldp+162,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data[0]),128);
    bufp->fullWData(oldp+166,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data[1]),128);
    bufp->fullWData(oldp+170,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data[2]),128);
    bufp->fullWData(oldp+174,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data[3]),128);
    bufp->fullWData(oldp+178,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data[4]),128);
    bufp->fullWData(oldp+182,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data[5]),128);
    bufp->fullWData(oldp+186,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data[6]),128);
    bufp->fullWData(oldp+190,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__data[7]),128);
    bufp->fullCData(oldp+194,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__snoop_index),3);
    bufp->fullCData(oldp+195,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__snoop_tag),3);
    bufp->fullBit(oldp+196,(((IData)(vlSelf->tb_top__DOT__dut__DOT__bus_valid_w) 
                             & ((~ (IData)(vlSelf->tb_top__DOT__dut__DOT__bus_drive_c1)) 
                                & ((0U != vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi
                                    [vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__snoop_index]) 
                                   & (vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__tag
                                      [vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__snoop_index] 
                                      == (IData)(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__snoop_tag)))))));
    bufp->fullCData(oldp+197,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__state),3);
    bufp->fullBit(oldp+198,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__pending_we));
    bufp->fullCData(oldp+199,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__pending_addr),8);
    bufp->fullIData(oldp+200,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__pending_wdata),32);
    bufp->fullIData(oldp+201,(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__i),32);
    bufp->fullCData(oldp+202,((0xfcU & VL_SHIFTR_III(8,8,32, (IData)(vlSelf->tb_top__DOT__dut__DOT__bus_addr_w), 2U))),8);
    bufp->fullBit(oldp+203,(vlSelf->tb_top__DOT__clk));
    bufp->fullBit(oldp+204,(((IData)(vlSelf->tb_top__DOT__c0_req) 
                             & ((0U != vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__mesi
                                 [vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__cpu_index]) 
                                & (vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__tag
                                   [vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__cpu_index] 
                                   == (IData)(vlSelf->tb_top__DOT__dut__DOT__u_cache0__DOT__cpu_tag))))));
    bufp->fullBit(oldp+205,(((IData)(vlSelf->tb_top__DOT__c1_req) 
                             & ((0U != vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__mesi
                                 [vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__cpu_index]) 
                                & (vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__tag
                                   [vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__cpu_index] 
                                   == (IData)(vlSelf->tb_top__DOT__dut__DOT__u_cache1__DOT__cpu_tag))))));
    bufp->fullIData(oldp+206,(vlSelf->tb_top__DOT__dut__DOT__u_mem__DOT__k),32);
}
