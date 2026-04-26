SHELL := /bin/bash

default: clean
all : clean comp run

clean:
	echo "\n\n\n Cleaning ... \n\n\n"
	rm -rf simdir *.log *.vcd *.hex simresult

comp:
	echo "\n\n\n Compiling ... \n\n\n"
	mkdir -p simresult
	verilator --binary -j 0 --trace -Wall \
	./rtl/mesi_cache.v  ./rtl/memory.v ./rtl/mesi_bus_arbiter.v ./rtl/mesi_system.v ./tb/tb_mesi_system.v \
	--top tb_top  +define+old --Mdir simresult -o simv \
	-Wno-UNDRIVEN -Wno-UNUSEDSIGNAL -Wno-WIDTHEXPAND -Wno-IMPLICIT \
	-Wno-PINCONNECTEMPTY -Wno-DECLFILENAME -Wno-BLKSEQ \
	-Wno-UNUSEDPARAM -Wno-WIDTHTRUNC -Wno-VARHIDDEN -Wno-REDEFMACRO -Wno-TIMESCALEMOD -Wno-PROCASSINIT \
	-Wno-CASEINCOMPLETE |& tee ./simresult/compile.log 

run:
	mkdir -p simresult
	echo "\n\n\n Simulation ... \n\n\n"
	./simresult/simv |& tee ./simresult/sim.log 
	mv sim.vcd ./simresult

wave:
	echo "\n\n\n Openining Waves ... \n\n\n"
	gtkwave ./simresult/sim.vcd &
