#toy-readelf
for learning purpose

## sample output
```
$ make test64                          
bin/readelf test/hello64
ELF Header:
  Magic:   7f 45 4c 46 02 01 01 00 00 00 00 00 00 00 00 00 
  Class: ELF64
  Data: little endian
  OS/ABI: System V
  Type: EXEC (Executable file)
  Machine: Advanced Micro Devices X86-64
  Entry point address: 0x400410
  Start of program headers: 0x40
  Start of section headers: 0x2168
  Size of this header: 64 (bytes)
  Size of program headers: 56 (bytes)
  Number of program headers: 9
  Size of section headers: 64 (bytes)
  Number of section headers: 35
  Section header string table index: 32
 
Section headers:
index : 0 	 name:  	 addr 0x0 	 offset 0x0  	 size 0
index : 1 	 name: .interp 	 addr 0x400238 	 offset 0x238  	 size 28
index : 2 	 name: .note.ABI-tag 	 addr 0x400254 	 offset 0x254  	 size 32
index : 3 	 name: .note.gnu.build-id 	 addr 0x400274 	 offset 0x274   size 36
index : 4 	 name: .gnu.hash 	 addr 0x400298 	 offset 0x298  	 size 28
index : 5 	 name: .dynsym 	 addr 0x4002b8 	 offset 0x2b8  	 size 96
index : 6 	 name: .dynstr 	 addr 0x400318 	 offset 0x318  	 size 73
index : 7 	 name: .gnu.version 	 addr 0x400362 	 offset 0x362  	 size 8
index : 8 	 name: .gnu.version_r 	 addr 0x400370 	 offset 0x370  	 size 32
index : 9 	 name: .rela.dyn 	 addr 0x400390 	 offset 0x390  	 size 48
index : 10 	 name: .rela.plt 	 addr 0x4003c0 	 offset 0x3c0  	 size 24
index : 11 	 name: .init 	 addr 0x4003d8 	 offset 0x3d8  	 size 23
index : 12 	 name: .plt 	 addr 0x4003f0 	 offset 0x3f0  	 size 32
index : 13 	 name: .text 	 addr 0x400410 	 offset 0x410  	 size 386
index : 14 	 name: .fini 	 addr 0x400594 	 offset 0x594  	 size 9
index : 15 	 name: .rodata 	 addr 0x4005a0 	 offset 0x5a0  	 size 17
index : 16 	 name: .eh_frame_hdr 	 addr 0x4005b4 	 offset 0x5b4  	 size 52
index : 17 	 name: .eh_frame 	 addr 0x4005e8 	 offset 0x5e8  	 size 244
index : 18 	 name: .init_array 	 addr 0x600df8 	 offset 0xdf8  	 size 8
index : 19 	 name: .fini_array 	 addr 0x600e00 	 offset 0xe00  	 size 8
index : 20 	 name: .jcr 	 addr 0x600e08 	 offset 0xe08  	 size 8
index : 21 	 name: .dynamic 	 addr 0x600e10 	 offset 0xe10  	 size 480
index : 22 	 name: .got 	 addr 0x600ff0 	 offset 0xff0  	 size 16
index : 23 	 name: .got.plt 	 addr 0x601000 	 offset 0x1000  	 size 32
index : 24 	 name: .data 	 addr 0x601020 	 offset 0x1020  	 size 16
index : 25 	 name: .bss 	 addr 0x601030 	 offset 0x1030  	 size 8
index : 26 	 name: .comment 	 addr 0x0 	 offset 0x1030  	 size 26
index : 27 	 name: .debug_aranges 	 addr 0x0 	 offset 0x104a  	 size 48
index : 28 	 name: .debug_info 	 addr 0x0 	 offset 0x107a  	 size 801
index : 29 	 name: .debug_abbrev 	 addr 0x0 	 offset 0x139b  	 size 224
index : 30 	 name: .debug_line 	 addr 0x0 	 offset 0x147b  	 size 205
index : 31 	 name: .debug_str 	 addr 0x0 	 offset 0x1548  	 size 648
index : 32 	 name: .shstrtab 	 addr 0x0 	 offset 0x201b  	 size 328
index : 33 	 name: .symtab 	 addr 0x0 	 offset 0x17d0  	 size 1656
index : 34 	 name: .strtab 	 addr 0x0 	 offset 0x1e48  	 size 467

Symbol table '.symtab' contains 69 entries: 
Num:	Value		Size	Type	Bind	Vis		Name
0:	0	0	UNKNOWN	LOCAL	DEFAULT		
1:	400238	0	UNKNOWN	LOCAL	DEFAULT		
2:	400254	0	UNKNOWN	LOCAL	DEFAULT		
3:	400274	0	UNKNOWN	LOCAL	DEFAULT		
4:	400298	0	UNKNOWN	LOCAL	DEFAULT		
5:	4002b8	0	UNKNOWN	LOCAL	DEFAULT		
6:	400318	0	UNKNOWN	LOCAL	DEFAULT		
7:	400362	0	UNKNOWN	LOCAL	DEFAULT		
8:	400370	0	UNKNOWN	LOCAL	DEFAULT		
9:	400390	0	UNKNOWN	LOCAL	DEFAULT		
10:	4003c0	0	UNKNOWN	LOCAL	DEFAULT		
11:	4003d8	0	UNKNOWN	LOCAL	DEFAULT		
12:	4003f0	0	UNKNOWN	LOCAL	DEFAULT		
13:	400410	0	UNKNOWN	LOCAL	DEFAULT		
14:	400594	0	UNKNOWN	LOCAL	DEFAULT		
15:	4005a0	0	UNKNOWN	LOCAL	DEFAULT		
16:	4005b4	0	UNKNOWN	LOCAL	DEFAULT		
17:	4005e8	0	UNKNOWN	LOCAL	DEFAULT		
18:	600df8	0	UNKNOWN	LOCAL	DEFAULT		
19:	600e00	0	UNKNOWN	LOCAL	DEFAULT		
20:	600e08	0	UNKNOWN	LOCAL	DEFAULT		
21:	600e10	0	UNKNOWN	LOCAL	DEFAULT		
22:	600ff0	0	UNKNOWN	LOCAL	DEFAULT		
23:	601000	0	UNKNOWN	LOCAL	DEFAULT		
24:	601020	0	UNKNOWN	LOCAL	DEFAULT		
25:	601030	0	UNKNOWN	LOCAL	DEFAULT		
26:	0	0	UNKNOWN	LOCAL	DEFAULT		
27:	0	0	UNKNOWN	LOCAL	DEFAULT		
28:	0	0	UNKNOWN	LOCAL	DEFAULT		
29:	0	0	UNKNOWN	LOCAL	DEFAULT		
30:	0	0	UNKNOWN	LOCAL	DEFAULT		
31:	0	0	UNKNOWN	LOCAL	DEFAULT		
32:	0	0	FILE	LOCAL	DEFAULT		init.c
33:	0	0	FILE	LOCAL	DEFAULT		crtstuff.c
34:	600e08	0	OBJECT	LOCAL	DEFAULT		__JCR_LIST__
35:	400440	0	FUNC	LOCAL	DEFAULT		deregister_tm_clones
36:	400480	0	FUNC	LOCAL	DEFAULT		register_tm_clones
37:	4004c0	0	FUNC	LOCAL	DEFAULT		__do_global_dtors_aux
38:	601030	1	OBJECT	LOCAL	DEFAULT		completed.6916
39:	600e00	0	OBJECT	LOCAL	DEFAULT		__do_global_dtors_aux_fini_array_entry
40:	4004e0	0	FUNC	LOCAL	DEFAULT		frame_dummy
41:	600df8	0	OBJECT	LOCAL	DEFAULT		__frame_dummy_init_array_entry
42:	0	0	FILE	LOCAL	DEFAULT		hello.c
43:	0	0	FILE	LOCAL	DEFAULT		crtstuff.c
44:	4006d8	0	OBJECT	LOCAL	DEFAULT		__FRAME_END__
45:	600e08	0	OBJECT	LOCAL	DEFAULT		__JCR_END__
46:	0	0	FILE	LOCAL	DEFAULT		
47:	600e00	0	UNKNOWN	LOCAL	DEFAULT		__init_array_end
48:	600e10	0	OBJECT	LOCAL	DEFAULT		_DYNAMIC
49:	600df8	0	UNKNOWN	LOCAL	DEFAULT		__init_array_start
50:	4005b4	0	UNKNOWN	LOCAL	DEFAULT		__GNU_EH_FRAME_HDR
51:	601000	0	OBJECT	LOCAL	DEFAULT		_GLOBAL_OFFSET_TABLE_
52:	400590	2	FUNC	GLOBAL	DEFAULT		__libc_csu_fini
53:	601020	0	UNKNOWN	WEAK	DEFAULT		data_start
54:	601030	0	UNKNOWN	GLOBAL	DEFAULT		_edata
55:	400594	0	FUNC	GLOBAL	DEFAULT		_fini
56:	0	0	FUNC	GLOBAL	DEFAULT		printf@@GLIBC_2.2.5
57:	0	0	FUNC	GLOBAL	DEFAULT		__libc_start_main@@GLIBC_2.2.5
58:	601020	0	UNKNOWN	GLOBAL	DEFAULT		__data_start
59:	0	0	UNKNOWN	WEAK	DEFAULT		__gmon_start__
60:	601028	0	OBJECT	GLOBAL	HIDDEN		__dso_handle
61:	4005a0	4	OBJECT	GLOBAL	DEFAULT		_IO_stdin_used
62:	400520	101	FUNC	GLOBAL	DEFAULT		__libc_csu_init
63:	601038	0	UNKNOWN	GLOBAL	DEFAULT		_end
64:	400410	43	FUNC	GLOBAL	DEFAULT		_start
65:	601030	0	UNKNOWN	GLOBAL	DEFAULT		__bss_start
66:	400506	26	FUNC	GLOBAL	DEFAULT		main
67:	601030	0	OBJECT	GLOBAL	HIDDEN		__TMC_END__
68:	4003d8	0	FUNC	GLOBAL	DEFAULT		_init
```
## refrences
* [readelf.c](http://www.opensource.apple.com/source/gdb/gdb-1515/src/binutils/readelf.c)
* [csapp](http://www.amazon.com/Computer-Systems-Programmers-Perspective-Edition/dp/0136108040)
* [wikipedia](https://en.wikipedia.org/wiki/Executable_and_Linkable_Format)
* [osdev](http://wiki.osdev.org/ELF_Tutorial)
* <https://refspecs.linuxbase.org/elf/gabi4+/ch4.symtab.html>
