; Generated by holtek-gcc v3.19, Sat Oct 12 14:56:50 2019
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
___pac equ [21]
___sledc0 equ [79]
___pawu equ [23]
___pa equ [20]
public _key_wakeup_check
#pragma debug scope 2 1
#line 8 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\workmode.c"
_key_wakeup_check .section 'code'
_key_wakeup_check proc
#line 9 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\workmode.c"
	set [21].7
#line 10 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\workmode.c"
	clr [79].2
#line 11 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\workmode.c"
	clr [79].3
#line 12 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\workmode.c"
	clr [23].7
_L3:
_L2:
#line 14 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\workmode.c"
	snz [20].7
	jmp _L2
#line 15 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\workmode.c"
;# 15 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\workmode.c" 1
	IF 20000>263690
;# 15 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\workmode.c" 1
	ERRMESSAGE 'the value 20000of the argument exceeds the maxinum 263690'
	ENDIF
;# 15 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\workmode.c" 1
	IF 20000<0
;# 15 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\workmode.c" 1
	ERRMESSAGE 'the value 20000 of the argument exceeds the mininum 0'
	ENDIF
;# 15 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\workmode.c" 1
	IF 20000==0
;# 15 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\workmode.c" 1
	JMP $
	ENDIF
;# 15 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\workmode.c" 1
	IF 20000==1
;# 15 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\workmode.c" 1
	NOP
	ENDIF
;# 15 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\workmode.c" 1
	IF 20000==2
;# 15 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\workmode.c" 1
	NOP
;# 15 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\workmode.c" 1
	NOP
	ENDIF
;# 15 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\workmode.c" 1
	IF 20000==3
;# 15 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\workmode.c" 1
	NOP
;# 15 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\workmode.c" 1
	NOP
;# 15 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\workmode.c" 1
	NOP
	ENDIF
;# 15 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\workmode.c" 1
	IF (20000<8) AND (20000>3)
;# 15 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\workmode.c" 1
	CALL __DELAY3 + 7 -20000
	ENDIF
;# 15 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\workmode.c" 1
	IF (20000< 0404h) AND (20000>7)
;# 15 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\workmode.c" 1
	MOV A,20000/4-1
;# 15 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\workmode.c" 1
	CALL __DELAYX3 + 3 -(20000 MOD 4)
	ENDIF
;# 15 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\workmode.c" 1
	IF (20000< 0x40B) AND (20000> 0403h)
;# 15 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\workmode.c" 1
	MOV A,0 
;# 15 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\workmode.c" 1
	CALL __DELAYX6 + 0x40a -20000
	ENDIF
;# 15 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\workmode.c" 1
	IF (20000 >= 0x40b) AND ((((20000-9)%0402h)/4+1)>256)
;# 15 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\workmode.c" 1
	MOV A,(20000-9)/0402h
;# 15 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\workmode.c" 1
	MOV _builtin_holtek_delay_2,A
;# 15 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\workmode.c" 1
	MOV A,0
;# 15 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\workmode.c" 1
	CALL __DELAYY5 +5- (((20000-9)%0402h)%6)
	ENDIF
;# 15 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\workmode.c" 1
	IF (20000 >= 0x40b) AND ((((20000-9)%0402h)/4+1)<=256)
;# 15 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\workmode.c" 1
	MOV A,(20000-9)/0402h
;# 15 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\workmode.c" 1
	MOV _builtin_holtek_delay_2,A
;# 15 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\workmode.c" 1
	MOV A,((20000-9)%0402h)/4+1
;# 15 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\workmode.c" 1
	CALL __DELAYY3 +3-(((20000-9)%0402h)%4)
	ENDIF
#line 16 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\workmode.c"
	snz [20].7
	jmp _L2
	ret
_key_wakeup_check endp
#line 16 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\workmode.c"
#pragma debug scope 1 1
___intc0 equ [14]
___pb equ [37]
___pc equ [65]
___pd equ [82]
___papu equ [22]
public _entry_sleep
#pragma debug scope 3 1
#line 20 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\workmode.c"
_entry_sleep .section 'code'
_entry_sleep proc
#line 21 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\workmode.c"
	clr [14].0
#line 23 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\workmode.c"
	mov a,229
	andm a,[20]
#line 24 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\workmode.c"
	mov a,153
	andm a,[37]
#line 25 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\workmode.c"
	mov a,216
	andm a,[65]
#line 26 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\workmode.c"
	clr [82].2
#line 28 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\workmode.c"
	set [23].7
#line 29 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\workmode.c"
	clr [65].4
#line 30 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\workmode.c"
	clr [20].6
#line 31 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\workmode.c"
;# 31 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\workmode.c" 1
	halt
#line 32 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\workmode.c"
	clr [22].7
#line 33 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\workmode.c"
	call _key_wakeup_check
#line 34 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\workmode.c"
	call _sys_init
	ret
_entry_sleep endp
#line 34 "C:\Users\think\Desktop\ph\phTestPen\phTestPen Code V02\Scr\workmode.c"
#pragma debug scope 1 1
#pragma debug struct_begin 42 "__intc0_bits"
#pragma debug field 21 8 0 1 "__emi" ;0,1
#pragma debug field 21 8 0 1 "__int0e" ;1,1
#pragma debug field 21 8 0 1 "__cpe" ;2,1
#pragma debug field 21 8 0 1 "__mf0e" ;3,1
#pragma debug field 21 8 0 1 "__int0f" ;4,1
#pragma debug field 21 8 0 1 "__cpf" ;5,1
#pragma debug field 21 8 0 1 "__mf0f" ;6,1
#pragma debug field 21 8 0 1 ;7,1
#pragma debug struct_end
#pragma debug union_begin 43 ""
#pragma debug field 2 42 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 43 1 ___intc0 "__intc0" 1
#pragma debug struct_begin 44 "__pa_bits"
#pragma debug field 21 8 0 1 "__pa0" ;0,1
#pragma debug field 21 8 0 1 "__pa1" ;1,1
#pragma debug field 21 8 0 1 "__pa2" ;2,1
#pragma debug field 21 8 0 1 "__pa3" ;3,1
#pragma debug field 21 8 0 1 "__pa4" ;4,1
#pragma debug field 21 8 0 1 "__pa5" ;5,1
#pragma debug field 21 8 0 1 "__pa6" ;6,1
#pragma debug field 21 8 0 1 "__pa7" ;7,1
#pragma debug struct_end
#pragma debug union_begin 45 ""
#pragma debug field 2 44 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 45 1 ___pa "__pa" 1
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
#pragma debug struct_begin 48 "__papu_bits"
#pragma debug field 21 8 0 1 "__papu0" ;0,1
#pragma debug field 21 8 0 1 "__papu1" ;1,1
#pragma debug field 21 8 0 1 "__papu2" ;2,1
#pragma debug field 21 8 0 1 "__papu3" ;3,1
#pragma debug field 21 8 0 1 "__papu4" ;4,1
#pragma debug field 21 8 0 1 "__papu5" ;5,1
#pragma debug field 21 8 0 1 "__papu6" ;6,1
#pragma debug field 21 8 0 1 "__papu7" ;7,1
#pragma debug struct_end
#pragma debug union_begin 49 ""
#pragma debug field 2 48 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 49 1 ___papu "__papu" 1
#pragma debug struct_begin 50 "__pawu_bits"
#pragma debug field 21 8 0 1 "__pawu0" ;0,1
#pragma debug field 21 8 0 1 "__pawu1" ;1,1
#pragma debug field 21 8 0 1 "__pawu2" ;2,1
#pragma debug field 21 8 0 1 "__pawu3" ;3,1
#pragma debug field 21 8 0 1 "__pawu4" ;4,1
#pragma debug field 21 8 0 1 "__pawu5" ;5,1
#pragma debug field 21 8 0 1 "__pawu6" ;6,1
#pragma debug field 21 8 0 1 "__pawu7" ;7,1
#pragma debug struct_end
#pragma debug union_begin 51 ""
#pragma debug field 2 50 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 51 1 ___pawu "__pawu" 1
#pragma debug struct_begin 52 "__pb_bits"
#pragma debug field 21 8 0 1 "__pb0" ;0,1
#pragma debug field 21 8 0 1 "__pb1" ;1,1
#pragma debug field 21 8 0 1 "__pb2" ;2,1
#pragma debug field 21 8 0 1 "__pb3" ;3,1
#pragma debug field 21 8 0 1 "__pb4" ;4,1
#pragma debug field 21 8 0 1 "__pb5" ;5,1
#pragma debug field 21 8 0 1 "__pb6" ;6,1
#pragma debug field 21 8 0 1 ;7,1
#pragma debug struct_end
#pragma debug union_begin 53 ""
#pragma debug field 2 52 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 53 1 ___pb "__pb" 1
#pragma debug struct_begin 54 "__pc_bits"
#pragma debug field 21 8 0 1 "__pc0" ;0,1
#pragma debug field 21 8 0 1 "__pc1" ;1,1
#pragma debug field 21 8 0 1 "__pc2" ;2,1
#pragma debug field 21 8 0 1 "__pc3" ;3,1
#pragma debug field 21 8 0 1 "__pc4" ;4,1
#pragma debug field 21 8 0 1 "__pc5" ;5,1
#pragma debug field 21 8 0 1 "__pc6" ;6,1
#pragma debug field 21 8 0 1 ;7,1
#pragma debug struct_end
#pragma debug union_begin 55 ""
#pragma debug field 2 54 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 55 1 ___pc "__pc" 1
#pragma debug struct_begin 56 "__sledc0_bits"
#pragma debug field 21 8 0 1 "__paps0" ;0,1
#pragma debug field 21 8 0 1 "__paps1" ;1,1
#pragma debug field 21 8 0 1 "__paps2" ;2,1
#pragma debug field 21 8 0 1 "__paps3" ;3,1
#pragma debug field 21 8 0 1 "__pbps0" ;4,1
#pragma debug field 21 8 0 1 "__pbps1" ;5,1
#pragma debug field 21 8 0 1 "__pbps2" ;6,1
#pragma debug field 21 8 0 1 "__pbps3" ;7,1
#pragma debug struct_end
#pragma debug union_begin 57 ""
#pragma debug field 2 56 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 57 1 ___sledc0 "__sledc0" 1
#pragma debug struct_begin 58 "__pd_bits"
#pragma debug field 21 8 0 1 "__pd0" ;0,1
#pragma debug field 21 8 0 1 "__pd1" ;1,1
#pragma debug field 21 8 0 1 "__pd2" ;2,1
#pragma debug field 21 8 0 1 "__pd3" ;3,1
#pragma debug field 21 8 0 4 ;4,4
#pragma debug struct_end
#pragma debug union_begin 59 ""
#pragma debug field 2 58 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 59 1 ___pd "__pd" 1
extern _sys_init:near

; 
; Generated by holtek-gcc v3.19, Sat Oct 12 14:56:50 2019
; Rebuild 718
; end of file
