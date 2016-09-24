#toy-readelf
for learning purpose

## sample output
```
$ make test64                          
$ bin/readelf test/hello64            [12:54:56]
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
Num:   Value		Size	Type	Bind	Vis	Ndx	Name
  0:0000000000000000   0  NOTYPE   LOCAL   DEFAULT   UND	
  1:0000000000400238   0 SECTION   LOCAL   DEFAULT     1	
  2:0000000000400254   0 SECTION   LOCAL   DEFAULT     2	
  3:0000000000400274   0 SECTION   LOCAL   DEFAULT     3	
  4:0000000000400298   0 SECTION   LOCAL   DEFAULT     4	
  5:00000000004002b8   0 SECTION   LOCAL   DEFAULT     5	
  6:0000000000400318   0 SECTION   LOCAL   DEFAULT     6	
  7:0000000000400362   0 SECTION   LOCAL   DEFAULT     7	
  8:0000000000400370   0 SECTION   LOCAL   DEFAULT     8	
  9:0000000000400390   0 SECTION   LOCAL   DEFAULT     9	
 10:00000000004003c0   0 SECTION   LOCAL   DEFAULT    10	
 11:00000000004003d8   0 SECTION   LOCAL   DEFAULT    11	
 12:00000000004003f0   0 SECTION   LOCAL   DEFAULT    12	
 13:0000000000400410   0 SECTION   LOCAL   DEFAULT    13	
 14:0000000000400594   0 SECTION   LOCAL   DEFAULT    14	
 15:00000000004005a0   0 SECTION   LOCAL   DEFAULT    15	
 16:00000000004005b4   0 SECTION   LOCAL   DEFAULT    16	
 17:00000000004005e8   0 SECTION   LOCAL   DEFAULT    17	
 18:0000000000600df8   0 SECTION   LOCAL   DEFAULT    18	
 19:0000000000600e00   0 SECTION   LOCAL   DEFAULT    19	
 20:0000000000600e08   0 SECTION   LOCAL   DEFAULT    20	
 21:0000000000600e10   0 SECTION   LOCAL   DEFAULT    21	
 22:0000000000600ff0   0 SECTION   LOCAL   DEFAULT    22	
 23:0000000000601000   0 SECTION   LOCAL   DEFAULT    23	
 24:0000000000601020   0 SECTION   LOCAL   DEFAULT    24	
 25:0000000000601030   0 SECTION   LOCAL   DEFAULT    25	
 26:0000000000000000   0 SECTION   LOCAL   DEFAULT    26	
 27:0000000000000000   0 SECTION   LOCAL   DEFAULT    27	
 28:0000000000000000   0 SECTION   LOCAL   DEFAULT    28	
 29:0000000000000000   0 SECTION   LOCAL   DEFAULT    29	
 30:0000000000000000   0 SECTION   LOCAL   DEFAULT    30	
 31:0000000000000000   0 SECTION   LOCAL   DEFAULT    31	
 32:0000000000000000   0    FILE   LOCAL   DEFAULT   ABS	init.c
 33:0000000000000000   0    FILE   LOCAL   DEFAULT   ABS	crtstuff.c
 34:0000000000600e08   0  OBJECT   LOCAL   DEFAULT    20	__JCR_LIST__
 35:0000000000400440   0    FUNC   LOCAL   DEFAULT    13	deregister_tm_clones
 36:0000000000400480   0    FUNC   LOCAL   DEFAULT    13	register_tm_clones
 37:00000000004004c0   0    FUNC   LOCAL   DEFAULT    13	__do_global_dtors_aux
 38:0000000000601030   1  OBJECT   LOCAL   DEFAULT    25	completed.6916
 39:0000000000600e00   0  OBJECT   LOCAL   DEFAULT    19	__do_global_dtors_aux_fini_array_entry
 40:00000000004004e0   0    FUNC   LOCAL   DEFAULT    13	frame_dummy
 41:0000000000600df8   0  OBJECT   LOCAL   DEFAULT    18	__frame_dummy_init_array_entry
 42:0000000000000000   0    FILE   LOCAL   DEFAULT   ABS	hello.c
 43:0000000000000000   0    FILE   LOCAL   DEFAULT   ABS	crtstuff.c
 44:00000000004006d8   0  OBJECT   LOCAL   DEFAULT    17	__FRAME_END__
 45:0000000000600e08   0  OBJECT   LOCAL   DEFAULT    20	__JCR_END__
 46:0000000000000000   0    FILE   LOCAL   DEFAULT   ABS	
 47:0000000000600e00   0  NOTYPE   LOCAL   DEFAULT    18	__init_array_end
 48:0000000000600e10   0  OBJECT   LOCAL   DEFAULT    21	_DYNAMIC
 49:0000000000600df8   0  NOTYPE   LOCAL   DEFAULT    18	__init_array_start
 50:00000000004005b4   0  NOTYPE   LOCAL   DEFAULT    16	__GNU_EH_FRAME_HDR
 51:0000000000601000   0  OBJECT   LOCAL   DEFAULT    23	_GLOBAL_OFFSET_TABLE_
 52:0000000000400590   2    FUNC  GLOBAL   DEFAULT    13	__libc_csu_fini
 53:0000000000601020   0  NOTYPE    WEAK   DEFAULT    24	data_start
 54:0000000000601030   0  NOTYPE  GLOBAL   DEFAULT    24	_edata
 55:0000000000400594   0    FUNC  GLOBAL   DEFAULT    14	_fini
 56:0000000000000000   0    FUNC  GLOBAL   DEFAULT   UND	printf@@GLIBC_2.2.5
 57:0000000000000000   0    FUNC  GLOBAL   DEFAULT   UND	__libc_start_main@@GLIBC_2.2.5
 58:0000000000601020   0  NOTYPE  GLOBAL   DEFAULT    24	__data_start
 59:0000000000000000   0  NOTYPE    WEAK   DEFAULT   UND	__gmon_start__
 60:0000000000601028   0  OBJECT  GLOBAL    HIDDEN    24	__dso_handle
 61:00000000004005a0   4  OBJECT  GLOBAL   DEFAULT    15	_IO_stdin_used
 62:0000000000400520 101    FUNC  GLOBAL   DEFAULT    13	__libc_csu_init
 63:0000000000601038   0  NOTYPE  GLOBAL   DEFAULT    25	_end
 64:0000000000400410  43    FUNC  GLOBAL   DEFAULT    13	_start
 65:0000000000601030   0  NOTYPE  GLOBAL   DEFAULT    25	__bss_start
 66:0000000000400506  26    FUNC  GLOBAL   DEFAULT    13	main
 67:0000000000601030   0  OBJECT  GLOBAL    HIDDEN    24	__TMC_END__
 68:00000000004003d8   0    FUNC  GLOBAL   DEFAULT    11	_init
