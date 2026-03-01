SHELL := /bin/bash

default: clean
all : clean comp run

clean:
	echo "\n\n\n Cleaning ... \n\n\n"
	rm -rf simdir *.log *.vcd *.hex simoutput

comp:
	echo "\n\n\n Compiling ... \n\n\n"
	mkdir simoutput
	verilator --binary -j 0 --trace -Wall \
	rtl/design.sv tb/i2c_interface.sv tb/i2c_package.sv tb/tb_top.sv \
	--top tb_top  +define+old --Mdir simdir -o simv \
	-Wno-UNDRIVEN -Wno-UNUSEDSIGNAL -Wno-WIDTHEXPAND -Wno-IMPLICIT \
	-Wno-PINCONNECTEMPTY -Wno-DECLFILENAME -Wno-BLKSEQ \
	-Wno-UNUSEDPARAM -Wno-WIDTHTRUNC -Wno-VARHIDDEN -Wno-REDEFMACRO -Wno-TIMESCALEMOD \
	-Wno-CASEINCOMPLETE |& tee ./simoutput/compile.log 

run:
	mkdir simresult
	echo "\n\n\n Simulation ... \n\n\n"
	./simdir/simv |& tee ./simoutput/sim.log 

wave:
	echo "\n\n\n Openining Waves ... \n\n\n"
	./simoutput/gtkwave waves.vcd &
