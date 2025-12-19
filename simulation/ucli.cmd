dump -file fsdb.fsdb -type fsdb -msv 
dump -add . -fsdb_opt "+all" -fid FSDB0 
#dump -file evcd.evcd -type EVCD
#dump -add {test_top, test_top.Master0, test_top.slave_i2c} -fid EVCD0
run 

