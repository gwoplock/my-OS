#objdump: -d -mm9s12x --prefix-addresses --reloc
#as: -mm9s12x
#name: 9s12x specific instructions (insns9s12x)

dump.o:     file format elf32-m68hc12


Disassembly of section .text:
0x00000000 addx	#0x00005678
0x00000004 addy	2,X\+
0x00000007 aded	0x0,X
0x0000000a adex	2,-Y
0x0000000d adey	\[D,X\]
0x00000010 andx	#0x00009988
0x00000014 andy	0x000055aa
0x00000018 aslw	0x00002004
0x0000001c aslx
0x0000001e asly
0x00000020 asrw	0x3000,Y
0x00000025 asrx
0x00000027 asry
0x00000029 bitx	\[0x3456,SP\]
0x0000002e bity	\[D,SP\]
0x00000031 btas	0x00002345, #0x04
0x00000036 clrw	0x2008,Y
0x0000003b clrx
0x0000003d clry
0x0000003f comw	0x0,X
0x00000042 comx
0x00000044 comy
0x00000046 cped	#0x0000fdeb
0x0000004a cpes	0x0000fedc
0x0000004e cpex	0x2,SP
0x00000051 cpey	2,SP\+
0x00000054 decw	0x0,X
0x00000057 decx
0x00000059 decy
0x0000005b eorx	0x00000034
0x0000005f eory	0x00001234
0x00000063 gldaa	0x00005678
0x00000067 gldab	0x0,X
0x0000006a gldd	2,Y\+
0x0000006d glds	0x0,Y
0x00000070 gldx	\[D,Y\]
0x00000073 gldy	\[D,X\]
0x00000076 gstaa	0x00005001
0x0000007a gstab	0x00005189
0x0000007e gstd	0x5000,X
0x00000083 gsts	0x00007008
0x00000087 gstx	0x6001,Y
0x0000008c gsty	\[D,X\]
0x0000008f incw	\[0x100,SP\]
0x00000094 incx
0x00000096 incy
0x00000098 aslw	0x00003005
0x0000009c aslx
0x0000009e asly
0x000000a0 lsrw	0x00003890
0x000000a4 lsrx
0x000000a6 lsry
0x000000a8 negw	2,-Y
0x000000ab negx
0x000000ad negy
0x000000af orx	#0x00009876
0x000000b3 ory	0x00009876
0x000000b7 pshcw
0x000000b9 pulcw
0x000000bb rolw	0x00005544
0x000000bf rolx
0x000000c1 roly
0x000000c3 rorw	0x0,X
0x000000c6 rorx
0x000000c8 rory
0x000000ca sbed	0x2,Y
0x000000cd sbex	0x00003458
0x000000d1 sbey	0x00008543
0x000000d5 subx	\[D,Y\]
0x000000d8 suby	\[D,X\]
0x000000db sys
0x000000dd tstw	0x3,X
0x000000e0 tstx
0x000000e2 tsty
