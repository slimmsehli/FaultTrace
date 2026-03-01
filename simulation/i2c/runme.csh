#!/bin/csh -f 

setenv FSDB_ENABLE_CLASS 1
setenv VERDI_ENHANCE_DYNAMIC_OBJECT
setenv FSDB_ENABLE_EXPAND_CLASS 
setenv FSDB_MAX_DYNAMIC_ARRAY_SIZE 100
setenv TRANSACTION_IN_WAVE_WINDOW 1
setenv TRANS_TOOLTIP_TEXT_LEN 100
setenv FSDB_VARIANT_SIZE_ARRAY 1

rm -rf simdir
mkdir simdir
cd simdir
setenv UVM_HOME $VCS_HOME/etc/uvm-1.2

vlogan -nc -full64 -sverilog -kdb -debug_access+all -ntb_opts uvm-1.2 -q
vlogan -nc -full64 -sverilog -kdb -debug_access+all ../../rtl/design.sv 
vlogan -nc -full64 -sverilog -kdb -debug_access+all ../../tb/i2c_interface.sv
vlogan -nc -full64 -sverilog -kdb -debug_access+all ../../tb/i2c_package.sv +incdir+../../tb+$VCS_HOME/etc/uvm-1.2
vlogan -nc -full64 -sverilog -kdb -debug_access+all ../../tb/tb_top.sv

vcs -nc -full64 -sverilog -kdb -debug_access+all -ntb_opts uvm-1.2 -timescale=1ns/1ns +vcs+flush+all +warn=all -l simv.log -top tb_top
	
./simv +vcs+lic+wait +UVM_NO_RELNOTES -l sim.log +UVM_VERDI_TRACE=UVM_AWARE+HIER+PRINT+RAL+TLM+MSG+COMPWAVE  +UVM_LOG_RECORD  +UVM_VPD_RECORD  +UVM_TR_RECORD -ucli -do ../ucli.tcl -verdi_opts "-sswr ../signal.rc"  +UVM_OBJ_DUMP_LEVEL=5 +UVM_VERDI_TRACE=RALWAVE -lca

