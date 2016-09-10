
all: init readelf

init :
	mkdir -p bin test

readelf: elf.h readelf.c readelf.h
	gcc -Wall -o bin/readelf readelf.c -g -lm

maketest: test/hello.c
	gcc -Wall -o test/hello64 test/hello.c -g -lm 
	gcc -Wall -o test/hello32 test/hello.c -g -lm -m32

test32: test/hello32
	bin/readelf test/hello32

test64: test/hello64
	bin/readelf test/hello64

