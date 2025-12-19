#!/bin/csh -f 

rm -rf simdir
mkdir simdir
cd simdir

vcs -sverilog -kdb -debug_access+all -full64 ../regbank.sv ../top.sv -diag timescale -timescale=1ns/1ns

simv -l simv.log +vcs+dumpvars+test.vcd -ucli -do ../ucli.cmd
