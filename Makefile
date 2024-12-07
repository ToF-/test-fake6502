
spike: spike.s run.c
	mkdir -p bin
	xa spike.s -o bin/spike.bin
	bin2c bin/spike.bin -o run_memory.h
	cc run.c -o bin/run 
