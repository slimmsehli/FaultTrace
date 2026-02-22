#!/bin/csh -f 

rm -rf simdir
mkdir simdir
cd simdir
setenv UVM_HOME $VCS_HOME/etc/uvm-1.2

#vcs -sverilog -kdb -debug_access+all -full64 ../regbank.sv ../top.sv -diag timescale -timescale=1ns/1ns
#simv -l simv.log +vcs+dumpvars+test.vcd -ucli -do ../ucli.cmd

#+incdir+$UVM_HOME/src $UVM_HOME/src/uvm.sv $UVM_HOME/src/dpi/uvm_dpi.cc -CFLAGS -DVCS '
vcs -full64 -licqueue -timescale=1ns/1ns +vcs+flush+all +warn=all -sverilog ../design.sv ../testbench.sv -l simv.log -ntb_opts uvm-1.2 +incdir+$UVM_HOME \
	-kdb -debug_access+all
	
./simv +vcs+lic+wait +UVM_NO_RELNOTES -l sim.log
