; Generated by holtek-gcc v3.19, Sat Oct 12 14:56:48 2019
; 
; Configuration:
;       without long instruction
;       Single ROM, Multi-RAM
;       bits_per_rom_unit:16
;       with mp1
;       with tbhp, address(0x9)
;          Use tabrd-const
;       
;       
;       
; use 'tabrdc' instead of 'tabrd'
;       

#pragma translator "holtek-gcc 4.6.4" "3.19" "build 20130711"
; Rebuild 718

ir equ [2]
mp equ [3]
sbp equ [1]
acc equ [5]
bp equ [4]
tblp equ [7]
tbhp equ [9]
status equ [10]
c equ [10].0
ac equ [10].1
z equ [10].2
ov equ [10].3
intc equ [11]

extern ra:byte
extern rb:byte
extern rc:byte
extern rd:byte
extern re:byte
extern rf:byte
extern rg:byte
extern rh:byte
extern _Crom2Prom:near
extern _Crom2PromNext:near

RAMBANK 0 @HCCINIT, @HCCINIT0

RAMBANK 0 @BITDATASEC, @BITDATASEC1
@HCCINIT	.section 'data'
@HCCINIT0	.section 'data'
@BITDATASEC	 .section 'data'
@BITDATASEC1	 .section 'data'

#pragma debug scope 1 1
	extern __DELAY3:near
	extern __DELAYX3:near
	extern __DELAYX6:near
	extern __DELAYY5:near
	extern __DELAYY3:near
	extern _builtin_holtek_delay_2:byte
___bp equ [4]
___mp1 equ [3]
___tblp equ [7]
___iar1 equ [2]
public _ClrRam
#pragma debug scope 2 1
#line 10 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\System_Init.c"
_ClrRam .section 'code'
_ClrRam proc
#line 11 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\System_Init.c"
	clr [4]
#line 12 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\System_Init.c"
	mov a,128
	mov [3],a
#line 13 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\System_Init.c"
	clr [7]
_L2:
#line 13 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\System_Init.c"
	sz [7].7
	jmp _L7
#line 15 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\System_Init.c"
	clr [2]
#line 16 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\System_Init.c"
	inc [3]
#line 13 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\System_Init.c"
	inc [7]
	jmp _L2
_L7:
#line 18 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\System_Init.c"
	mov a,1
	mov [4],a
#line 19 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\System_Init.c"
	mov a,128
	mov [3],a
#line 20 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\System_Init.c"
	clr [7]
_L4:
	sz [7].7
	jmp _L8
#line 22 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\System_Init.c"
	clr [2]
#line 23 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\System_Init.c"
	inc [3]
#line 20 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\System_Init.c"
	inc [7]
	jmp _L4
_L8:
#line 25 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\System_Init.c"
	clr [4]
	ret
_ClrRam endp
#line 25 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\System_Init.c"
#pragma debug scope 1 1
___smod equ [11]
___ctrl equ [28]
___wdtc equ [26]
___cpc equ [63]
___sledc0 equ [79]
___sledc1 equ [80]
___ifs equ [81]
___tmpc equ [25]
___simc0 equ [69]
___simc1 equ [70]
___acerl equ [68]
___pac equ [21]
___pbc equ [38]
___pcc equ [66]
___pdc equ [83]
public _SysInit
#pragma debug scope 3 1
#line 35 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\System_Init.c"
_SysInit .section 'code'
_SysInit proc
#line 36 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\System_Init.c"
	mov a,3
	mov [11],a
#line 37 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\System_Init.c"
	clr [28]
#line 39 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\System_Init.c"
	mov a,168
	mov [26],a
#line 40 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\System_Init.c"
	mov a,8
	mov [63],a
#line 42 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\System_Init.c"
	set [79]
#line 43 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\System_Init.c"
	mov a,63
	mov [80],a
#line 44 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\System_Init.c"
	clr [81]
#line 45 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\System_Init.c"
	clr [25]
#line 46 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\System_Init.c"
	mov a,224
	mov [69],a
#line 47 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\System_Init.c"
	mov a,129
	mov [70],a
#line 48 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\System_Init.c"
	clr [68]
#line 51 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\System_Init.c"
	set [21]
#line 52 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\System_Init.c"
	set [38]
#line 53 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\System_Init.c"
	set [66]
#line 54 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\System_Init.c"
	set [83]
	ret
_SysInit endp
#line 54 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\System_Init.c"
#pragma debug scope 1 1
#pragma debug variable 8 1 ___mp1 "__mp1" 1
#pragma debug struct_begin 42 "__bp_bits"
#pragma debug field 21 8 0 1 "__dmbp0" ;0,1
#pragma debug field 21 8 0 7 ;1,7
#pragma debug struct_end
#pragma debug union_begin 43 ""
#pragma debug field 2 42 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 43 1 ___bp "__bp" 1
#pragma debug variable 8 1 ___tblp "__tblp" 1
#pragma debug struct_begin 44 "__smod_bits"
#pragma debug field 21 8 0 1 "__hlclk" ;0,1
#pragma debug field 21 8 0 1 "__idlen" ;1,1
#pragma debug field 21 8 0 1 "__hto" ;2,1
#pragma debug field 21 8 0 1 "__lto" ;3,1
#pragma debug field 21 8 0 1 "__fsten" ;4,1
#pragma debug field 21 8 0 1 "__cks0" ;5,1
#pragma debug field 21 8 0 1 "__cks1" ;6,1
#pragma debug field 21 8 0 1 "__cks2" ;7,1
#pragma debug struct_end
#pragma debug union_begin 45 ""
#pragma debug field 2 44 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 45 1 ___smod "__smod" 1
#pragma debug struct_begin 46 "__pac_bits"
#pragma debug field 21 8 0 1 "__pac0" ;0,1
#pragma debug field 21 8 0 1 "__pac1" ;1,1
#pragma debug field 21 8 0 1 "__pac2" ;2,1
#pragma debug field 21 8 0 1 "__pac3" ;3,1
#pragma debug field 21 8 0 1 "__pac4" ;4,1
#pragma debug field 21 8 0 1 "__pac5" ;5,1
#pragma debug field 21 8 0 1 "__pac6" ;6,1
#pragma debug field 21 8 0 1 "__pac7" ;7,1
#pragma debug struct_end
#pragma debug union_begin 47 ""
#pragma debug field 2 46 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 47 1 ___pac "__pac" 1
#pragma debug struct_begin 48 "__tmpc_bits"
#pragma debug field 21 8 0 1 "__t0cp" ;0,1
#pragma debug field 21 8 0 1 "__t1cp" ;1,1
#pragma debug field 21 8 0 1 "__t2cp" ;2,1
#pragma debug field 21 8 0 4 ;3,4
#pragma debug field 21 8 0 1 "__clop" ;7,1
#pragma debug struct_end
#pragma debug union_begin 49 ""
#pragma debug field 2 48 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 49 1 ___tmpc "__tmpc" 1
#pragma debug struct_begin 50 "__wdtc_bits"
#pragma debug field 21 8 0 1 "__ws0" ;0,1
#pragma debug field 21 8 0 1 "__ws1" ;1,1
#pragma debug field 21 8 0 1 "__ws2" ;2,1
#pragma debug field 21 8 0 1 "__we0" ;3,1
#pragma debug field 21 8 0 1 "__we1" ;4,1
#pragma debug field 21 8 0 1 "__we2" ;5,1
#pragma debug field 21 8 0 1 "__we3" ;6,1
#pragma debug field 21 8 0 1 "__we4" ;7,1
#pragma debug struct_end
#pragma debug union_begin 51 ""
#pragma debug field 2 50 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 51 1 ___wdtc "__wdtc" 1
#pragma debug struct_begin 52 "__ctrl_bits"
#pragma debug field 21 8 0 1 "__wrf" ;0,1
#pragma debug field 21 8 0 1 "__lrf" ;1,1
#pragma debug field 21 8 0 1 "__lvrf" ;2,1
#pragma debug field 21 8 0 4 ;3,4
#pragma debug field 21 8 0 1 "__fsyson" ;7,1
#pragma debug struct_end
#pragma debug union_begin 53 ""
#pragma debug field 2 52 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 53 1 ___ctrl "__ctrl" 1
#pragma debug struct_begin 54 "__pbc_bits"
#pragma debug field 21 8 0 1 "__pbc0" ;0,1
#pragma debug field 21 8 0 1 "__pbc1" ;1,1
#pragma debug field 21 8 0 1 "__pbc2" ;2,1
#pragma debug field 21 8 0 1 "__pbc3" ;3,1
#pragma debug field 21 8 0 1 "__pbc4" ;4,1
#pragma debug field 21 8 0 1 "__pbc5" ;5,1
#pragma debug field 21 8 0 1 "__pbc6" ;6,1
#pragma debug field 21 8 0 1 ;7,1
#pragma debug struct_end
#pragma debug union_begin 55 ""
#pragma debug field 2 54 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 55 1 ___pbc "__pbc" 1
#pragma debug struct_begin 56 "__cpc_bits"
#pragma debug field 21 8 0 1 "__chyen" ;0,1
#pragma debug field 21 8 0 1 "__cmpeg0" ;1,1
#pragma debug field 21 8 0 1 "__cmpeg1" ;2,1
#pragma debug field 21 8 0 1 "__cos" ;3,1
#pragma debug field 21 8 0 1 "__cout" ;4,1
#pragma debug field 21 8 0 1 "__cpol" ;5,1
#pragma debug field 21 8 0 1 "__cen" ;6,1
#pragma debug field 21 8 0 1 "__csel" ;7,1
#pragma debug struct_end
#pragma debug union_begin 57 ""
#pragma debug field 2 56 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 57 1 ___cpc "__cpc" 1
#pragma debug struct_begin 58 "__pcc_bits"
#pragma debug field 21 8 0 1 "__pcc0" ;0,1
#pragma debug field 21 8 0 1 "__pcc1" ;1,1
#pragma debug field 21 8 0 1 "__pcc2" ;2,1
#pragma debug field 21 8 0 1 "__pcc3" ;3,1
#pragma debug field 21 8 0 1 "__pcc4" ;4,1
#pragma debug field 21 8 0 1 "__pcc5" ;5,1
#pragma debug field 21 8 0 1 "__pcc6" ;6,1
#pragma debug field 21 8 0 1 ;7,1
#pragma debug struct_end
#pragma debug union_begin 59 ""
#pragma debug field 2 58 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 59 1 ___pcc "__pcc" 1
#pragma debug struct_begin 60 "__acerl_bits"
#pragma debug field 21 8 0 1 "__ace0" ;0,1
#pragma debug field 21 8 0 1 "__ace1" ;1,1
#pragma debug field 21 8 0 1 "__ace2" ;2,1
#pragma debug field 21 8 0 1 "__ace3" ;3,1
#pragma debug field 21 8 0 1 "__ace4" ;4,1
#pragma debug field 21 8 0 1 "__ace5" ;5,1
#pragma debug field 21 8 0 1 "__ace6" ;6,1
#pragma debug field 21 8 0 1 "__ace7" ;7,1
#pragma debug struct_end
#pragma debug union_begin 61 ""
#pragma debug field 2 60 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 61 1 ___acerl "__acerl" 1
#pragma debug struct_begin 62 "__simc0_bits"
#pragma debug field 21 8 0 1 "__simicf" ;0,1
#pragma debug field 21 8 0 1 "__simen" ;1,1
#pragma debug field 21 8 0 1 "__simdeb0" ;2,1
#pragma debug field 21 8 0 1 "__simdeb1" ;3,1
#pragma debug field 21 8 0 1 ;4,1
#pragma debug field 21 8 0 1 "__sim0" ;5,1
#pragma debug field 21 8 0 1 "__sim1" ;6,1
#pragma debug field 21 8 0 1 "__sim2" ;7,1
#pragma debug struct_end
#pragma debug union_begin 63 ""
#pragma debug field 2 62 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 63 1 ___simc0 "__simc0" 1
#pragma debug struct_begin 64 "__simc1_bits"
#pragma debug field 21 8 0 1 "__rxak" ;0,1
#pragma debug field 21 8 0 1 "__iamwu" ;1,1
#pragma debug field 21 8 0 1 "__srw" ;2,1
#pragma debug field 21 8 0 1 "__txak" ;3,1
#pragma debug field 21 8 0 1 "__htx" ;4,1
#pragma debug field 21 8 0 1 "__hbb" ;5,1
#pragma debug field 21 8 0 1 "__haas" ;6,1
#pragma debug field 21 8 0 1 "__hcf" ;7,1
#pragma debug struct_end
#pragma debug union_begin 65 ""
#pragma debug field 2 64 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 65 1 ___simc1 "__simc1" 1
#pragma debug struct_begin 66 "__sledc0_bits"
#pragma debug field 21 8 0 1 "__paps0" ;0,1
#pragma debug field 21 8 0 1 "__paps1" ;1,1
#pragma debug field 21 8 0 1 "__paps2" ;2,1
#pragma debug field 21 8 0 1 "__paps3" ;3,1
#pragma debug field 21 8 0 1 "__pbps0" ;4,1
#pragma debug field 21 8 0 1 "__pbps1" ;5,1
#pragma debug field 21 8 0 1 "__pbps2" ;6,1
#pragma debug field 21 8 0 1 "__pbps3" ;7,1
#pragma debug struct_end
#pragma debug union_begin 67 ""
#pragma debug field 2 66 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 67 1 ___sledc0 "__sledc0" 1
#pragma debug struct_begin 68 "__sledc1_bits"
#pragma debug field 21 8 0 1 "__pcps0" ;0,1
#pragma debug field 21 8 0 1 "__pcps1" ;1,1
#pragma debug field 21 8 0 1 "__pcps2" ;2,1
#pragma debug field 21 8 0 1 "__pcps3" ;3,1
#pragma debug field 21 8 0 1 "__pdps0" ;4,1
#pragma debug field 21 8 0 1 "__pdps1" ;5,1
#pragma debug field 21 8 0 2 ;6,2
#pragma debug struct_end
#pragma debug union_begin 69 ""
#pragma debug field 2 68 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 69 1 ___sledc1 "__sledc1" 1
#pragma debug struct_begin 70 "__ifs_bits"
#pragma debug field 21 8 0 1 "__rxps" ;0,1
#pragma debug field 21 8 0 1 "__txps" ;1,1
#pragma debug field 21 8 0 1 "__scsbps" ;2,1
#pragma debug field 21 8 0 1 "__sck_sclps" ;3,1
#pragma debug field 21 8 0 1 "__sdi_sdaps" ;4,1
#pragma debug field 21 8 0 1 "__sdops0" ;5,1
#pragma debug field 21 8 0 1 "__sdops1" ;6,1
#pragma debug field 21 8 0 1 ;7,1
#pragma debug struct_end
#pragma debug union_begin 71 ""
#pragma debug field 2 70 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 71 1 ___ifs "__ifs" 1
#pragma debug struct_begin 72 "__pdc_bits"
#pragma debug field 21 8 0 1 "__pdc0" ;0,1
#pragma debug field 21 8 0 1 "__pdc1" ;1,1
#pragma debug field 21 8 0 1 "__pdc2" ;2,1
#pragma debug field 21 8 0 1 "__pdc3" ;3,1
#pragma debug field 21 8 0 4 ;4,4
#pragma debug struct_end
#pragma debug union_begin 73 ""
#pragma debug field 2 72 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 73 1 ___pdc "__pdc" 1
#pragma debug variable 8 1 ___iar1 "__iar1" 1

; 
; Generated by holtek-gcc v3.19, Sat Oct 12 14:56:48 2019
; Rebuild 718
; end of file
