;;; Segment .text (0000000000400940)

;; _start: 0000000000400940
_start proc
	xor	ebp,ebp
	mov	r9,rdx
	pop	rsi
	mov	rdx,rsp
	and	rsp,0F0h
	push	rax
	push	rsp
	mov	r8,+402E40h
	mov	rcx,+402DD0h
	mov	rdi,+400B10h
	call	[0000000000404FD8]                                    ; [rip+0000466E]
	hlt
000000000040096B                                  0F 1F 44 00 00            ..D..

;; deregister_tm_clones: 0000000000400970
;;   Called from:
;;     00000000004009ED (in __do_global_dtors_aux)
deregister_tm_clones proc
	mov	eax,405090h
	cmp	rax,+405090h
	jz	400990h

l000000000040097D:
	mov	eax,0h
	test	rax,rax
	jz	400990h

l0000000000400987:
	mov	edi,405090h
	jmp	rax
000000000040098E                                           66 90               f.

l0000000000400990:
	ret
0000000000400991    0F 1F 44 00 00 66 2E 0F 1F 84 00 00 00 00 00  ..D..f.........

;; register_tm_clones: 00000000004009A0
;;   Called from:
;;     0000000000400A10 (in frame_dummy)
register_tm_clones proc
	mov	esi,405090h
	sub	rsi,+405090h
	sar	rsi,3h
	mov	rax,rsi
	shr	rax,3Fh
	add	rsi,rax
	sar	rsi,1h
	jz	4009D0h

l00000000004009BF:
	mov	eax,0h
	test	rax,rax
	jz	4009D0h

l00000000004009C9:
	mov	edi,405090h
	jmp	rax

l00000000004009D0:
	ret
00000000004009D1    0F 1F 44 00 00 66 2E 0F 1F 84 00 00 00 00 00  ..D..f.........

;; __do_global_dtors_aux: 00000000004009E0
__do_global_dtors_aux proc
	cmp	[00000000004050A0],0h                                  ; [rip+000046B9]
	jnz	400A00h

l00000000004009E9:
	push	rbp
	mov	rbp,rsp
	call	deregister_tm_clones
	mov	[00000000004050A0],1h                                  ; [rip+000046A7]
	pop	rbp
	ret
00000000004009FB                                  0F 1F 44 00 00            ..D..

l0000000000400A00:
	ret
0000000000400A01    0F 1F 44 00 00 66 2E 0F 1F 84 00 00 00 00 00  ..D..f.........

;; frame_dummy: 0000000000400A10
frame_dummy proc
	jmp	register_tm_clones
0000000000400A12       66 66 66 66 66 2E 0F 1F 84 00 00 00 00 00   fffff.........

;; global_opt: 0000000000400A20
;;   Called from:
;;     0000000000400BC2 (in main)
global_opt proc
	push	r14
	push	rbx
	push	rax
	mov	r14,-6h
	nop	dword ptr [rax+rax+0h]

l0000000000400A30:
	mov	rsi,[0000000000407E58]                                 ; [rip+00007421]
	mov	edi,402E54h
	xor	eax,eax
	call	400840h
	mov	edi,407CB0h
	call	primal_net_simplex
	mov	rsi,[0000000000407F08]                                 ; [rip+000074B4]
	mov	edi,402E76h
	xor	eax,eax
	call	400840h
	mov	edi,407CB0h
	call	flow_cost
	mov	edi,402E98h
	mov	al,1h
	call	400840h
	add	r14,1h
	jz	400AEEh

l0000000000400A7C:
	cmp	[0000000000407E68],0h                                  ; [rip+000073E4]
	jz	400AB0h

l0000000000400A86:
	mov	edi,407CB0h
	mov	rsi,-1h
	xor	edx,edx
	call	suspend_impl
	mov	rcx,rax
	test	rcx,rcx
	jz	400AB0h

l0000000000400AA1:
	mov	edi,402EBCh
	xor	eax,eax
	mov	rsi,rcx
	call	400840h

l0000000000400AB0:
	mov	edi,407CB0h
	call	price_out_impl
	mov	rbx,rax
	test	rbx,rbx
	jz	400AEEh

l0000000000400AC2:
	mov	edi,402EDEh
	xor	eax,eax
	mov	rsi,rbx
	call	400840h
	test	rbx,rbx
	jns	400A30h

l0000000000400ADA:
	mov	edi,403030h
	call	400850h
	mov	edi,0FFFFFFFFh
	call	400860h

l0000000000400AEE:
	mov	rsi,[0000000000407F18]                                 ; [rip+00007423]
	mov	edi,402F00h
	xor	eax,eax
	call	400840h
	xor	eax,eax
	add	rsp,8h
	pop	rbx
	pop	r14
	ret
0000000000400B0B                                  0F 1F 44 00 00            ..D..

;; main: 0000000000400B10
main proc
	push	rbp
	push	rbx
	push	rax
	mov	rbx,rsi
	mov	ebp,0FFFFFFFFh
	cmp	edi,2h
	jl	400BF2h

l0000000000400B24:
	mov	edi,403060h
	call	400850h
	mov	edi,403080h
	call	400850h
	mov	edi,4030C0h
	call	400850h
	mov	edi,4030F0h
	call	400850h
	mov	edi,0Ah
	call	400870h
	mov	edi,407CB0h
	xor	esi,esi
	mov	edx,270h
	call	400880h
	mov	[0000000000407EC0],+989680h                            ; [rip+0000734E]
	mov	rsi,[rbx+8h]
	mov	edi,407CB0h
	call	400890h
	mov	edi,407CB0h
	call	read_min
	test	rax,rax
	jz	400BA5h

l0000000000400B8F:
	mov	edi,403120h
	call	400850h
	mov	edi,407CB0h
	call	getfree
	jmp	400BF2h

l0000000000400BA5:
	mov	rsi,[0000000000407E48]                                 ; [rip+0000729C]
	mov	edi,402F22h
	xor	eax,eax
	call	400840h
	mov	edi,407CB0h
	call	primal_start_artificial
	call	global_opt
	mov	edi,402F4Ch
	call	400850h
	mov	edi,402F44h
	mov	esi,407CB0h
	call	write_circulations
	mov	rbx,rax
	mov	edi,407CB0h
	call	getfree
	neg	rbx
	sbb	ebp,ebp

l0000000000400BF2:
	mov	eax,ebp
	add	rsp,8h
	pop	rbx
	pop	rbp
	ret
0000000000400BFB                                  0F 1F 44 00 00            ..D..

;; refresh_neighbour_lists: 0000000000400C00
;;   Called from:
;;     0000000000401AF5 (in price_out_impl)
;;     000000000040217A (in suspend_impl)
;;     000000000040237C (in write_circulations)
refresh_neighbour_lists proc
	mov	rax,[rdi+228h]
	mov	rcx,[rdi+230h]
	cmp	rax,rcx
	jnc	400C2Dh

l0000000000400C13:
	xorps	xmm0,xmm0
	nop	word ptr cs:[rax+rax+0h]

l0000000000400C20:
	movups	[rax+38h],xmm0
	add	rax,68h
	cmp	rax,rcx
	jc	400C20h

l0000000000400C2D:
	mov	rcx,[rdi+238h]
	mov	r8,[rdi+240h]
	cmp	rcx,r8
	jnc	400CE4h

l0000000000400C44:
	mov	rdx,rcx
	not	rdx
	add	rdx,r8
	test	dl,40h
	jnz	400C76h

l0000000000400C52:
	mov	rsi,[rcx+8h]
	mov	rdi,[rsi+38h]
	mov	[rcx+20h],rdi
	mov	[rsi+38h],rcx
	mov	rsi,[rcx+10h]
	mov	rdi,[rsi+40h]
	mov	[rcx+28h],rdi
	mov	[rsi+40h],rcx
	add	rcx,40h

l0000000000400C76:
	cmp	rdx,40h
	jc	400CE4h

l0000000000400C7C:
	add	rcx,40h
	mov	rdx,rcx
	nop	word ptr cs:[rax+rax+0h]

l0000000000400C90:
	lea	rsi,[rcx-40h]
	mov	rdi,[rcx-38h]
	mov	rax,[rdi+38h]
	mov	[rcx-20h],rax
	mov	[rdi+38h],rsi
	mov	rax,[rcx-30h]
	mov	rdi,[rax+40h]
	mov	[rcx-18h],rdi
	mov	[rax+40h],rsi
	mov	rax,[rcx+8h]
	mov	rsi,[rax+38h]
	mov	[rcx+20h],rsi
	mov	[rax+38h],rcx
	mov	rax,[rcx+10h]
	mov	rsi,[rax+40h]
	mov	[rcx+28h],rsi
	mov	[rax+40h],rcx
	sub	rdx,80h
	add	rcx,40h
	cmp	rcx,r8
	mov	rcx,rdx
	jc	400C90h

l0000000000400CE4:
	ret
0000000000400CE5                66 66 2E 0F 1F 84 00 00 00 00 00      ff.........

;; refresh_potential: 0000000000400CF0
;;   Called from:
;;     0000000000402924 (in primal_net_simplex)
;;     0000000000402981 (in primal_net_simplex)
refresh_potential proc
	mov	r8,[rdi+228h]
	mov	qword ptr [r8],-5F5E100h
	mov	rdi,[r8+10h]
	xor	eax,eax
	cmp	rdi,r8
	jz	400D96h

l0000000000400D0D:
	mov	rdx,rdi

l0000000000400D10:
	test	rdi,rdi
	jz	400D60h

l0000000000400D15:
	nop	word ptr cs:[rax+rax+0h]

l0000000000400D20:
	mov	rdx,rdi
	cmp	dword ptr [rdx+8h],1h
	jnz	400D40h

l0000000000400D29:
	mov	rcx,[rdx+18h]
	mov	rdi,[rdx+30h]
	mov	rsi,[rcx]
	add	rsi,[rdi]
	jmp	400D52h
0000000000400D39                            0F 1F 80 00 00 00 00          .......

l0000000000400D40:
	mov	rcx,[rdx+18h]
	mov	rdi,[rdx+30h]
	mov	rsi,[rcx]
	sub	rsi,[rdi]
	add	rax,1h

l0000000000400D52:
	mov	[rdx],rsi
	mov	rdi,[rdx+10h]
	test	rdi,rdi
	jnz	400D20h

l0000000000400D5E:
	jmp	400D64h

l0000000000400D60:
	mov	rcx,[rdx+18h]

l0000000000400D64:
	mov	rsi,rdx
	mov	rdi,rdx
	test	rcx,rcx
	jz	400D8Dh

l0000000000400D6F:
	nop

l0000000000400D70:
	mov	rdx,[rsi+20h]
	mov	rsi,rcx
	mov	rdi,rdx
	test	rdx,rdx
	jnz	400D8Dh

l0000000000400D7F:
	mov	rcx,[rsi+18h]
	test	rcx,rcx
	jnz	400D70h

l0000000000400D88:
	xor	edx,edx
	mov	rdi,rsi

l0000000000400D8D:
	cmp	rdi,r8
	jnz	400D10h

l0000000000400D96:
	ret
0000000000400D97                      66 0F 1F 84 00 00 00 00 00        f........

;; flow_cost: 0000000000400DA0
;;   Called from:
;;     0000000000400A65 (in global_opt)
flow_cost proc
	mov	rax,[rdi+238h]
	mov	r9,[rdi+240h]
	cmp	rax,r9
	jz	400EB0h

l0000000000400DB7:
	lea	r8,[r9-40h]
	sub	r8,rax
	mov	esi,r8d
	shr	esi,6h
	add	esi,1h
	mov	rdx,rax
	and	rsi,7h
	jz	400DF7h

l0000000000400DD0:
	neg	rsi
	mov	rdx,rax
	nop	word ptr cs:[rax+rax+0h]

l0000000000400DE0:
	xor	ecx,ecx
	cmp	dword ptr [rdx+18h],2h
	setz	cl
	mov	[rdx+30h],rcx
	add	rdx,40h
	add	rsi,1h
	jnz	400DE0h

l0000000000400DF7:
	cmp	r8,+1C0h
	jc	400EB0h

l0000000000400E04:
	nop	word ptr cs:[rax+rax+0h]

l0000000000400E10:
	mov	ecx,[rdx+58h]
	xor	esi,esi
	cmp	dword ptr [rdx+18h],2h
	setz	sil
	mov	[rdx+30h],rsi
	xor	esi,esi
	cmp	ecx,2h
	setz	sil
	mov	[rdx+70h],rsi
	xor	ecx,ecx
	cmp	dword ptr [rdx+98h],2h
	setz	cl
	mov	[rdx+0B0h],rcx
	xor	ecx,ecx
	cmp	dword ptr [rdx+0D8h],2h
	setz	cl
	mov	[rdx+0F0h],rcx
	xor	ecx,ecx
	cmp	dword ptr [rdx+118h],2h
	setz	cl
	mov	[rdx+130h],rcx
	xor	ecx,ecx
	cmp	dword ptr [rdx+158h],2h
	setz	cl
	mov	[rdx+170h],rcx
	xor	ecx,ecx
	cmp	dword ptr [rdx+198h],2h
	setz	cl
	mov	[rdx+1B0h],rcx
	xor	ecx,ecx
	cmp	dword ptr [rdx+1D8h],2h
	setz	cl
	mov	[rdx+1F0h],rcx
	add	rdx,+200h
	cmp	r9,rdx
	jnz	400E10h

l0000000000400EB0:
	mov	rdx,[rdi+228h]
	mov	r8,[rdi+230h]
	add	rdx,68h
	cmp	rdx,r8
	jz	400EE5h

l0000000000400EC7:
	nop	word ptr [rax+rax+0h]

l0000000000400ED0:
	mov	rcx,[rdx+30h]
	mov	rsi,[rdx+50h]
	mov	[rcx+30h],rsi
	add	rdx,68h
	cmp	r8,rdx
	jnz	400ED0h

l0000000000400EE5:
	cmp	rax,r9
	jz	400F3Bh

l0000000000400EEA:
	xor	edx,edx
	xor	r8d,r8d
	nop

l0000000000400EF0:
	cmp	qword ptr [rax+30h],0h
	jz	400F30h

l0000000000400EF7:
	mov	rcx,[rax+8h]
	mov	ecx,[rcx+60h]
	test	ecx,ecx
	js	400F20h

l0000000000400F02:
	mov	rsi,[rax]
	jnz	400F2Dh

l0000000000400F07:
	add	rsi,rdx
	sub	rsi,[rdi+210h]
	add	r8,1h
	mov	rdx,rsi
	jmp	400F30h
0000000000400F1A                               66 0F 1F 44 00 00           f..D..

l0000000000400F20:
	mov	rcx,[rax+10h]
	cmp	dword ptr [rcx+60h],0h
	jg	400F30h

l0000000000400F2A:
	mov	rsi,[rax]

l0000000000400F2D:
	add	rdx,rsi

l0000000000400F30:
	add	rax,40h
	cmp	r9,rax
	jnz	400EF0h

l0000000000400F39:
	jmp	400F40h

l0000000000400F3B:
	xor	r8d,r8d
	xor	edx,edx

l0000000000400F40:
	cvtsi2sd	xmm0,r8
	cvtsi2sd	xmm1,qword ptr [rdi+210h]
	mulsd	xmm1,xmm0
	xorps	xmm0,xmm0
	cvtsi2sd	xmm0,rdx
	addsd	xmm0,xmm1
	ret
0000000000400F5F                                              90                .

;; flow_org_cost: 0000000000400F60
flow_org_cost proc
	mov	rax,[rdi+238h]
	mov	r9,[rdi+240h]
	cmp	rax,r9
	jz	401070h

l0000000000400F77:
	lea	r8,[r9-40h]
	sub	r8,rax
	mov	esi,r8d
	shr	esi,6h
	add	esi,1h
	mov	rdx,rax
	and	rsi,7h
	jz	400FB7h

l0000000000400F90:
	neg	rsi
	mov	rdx,rax
	nop	word ptr cs:[rax+rax+0h]

l0000000000400FA0:
	xor	ecx,ecx
	cmp	dword ptr [rdx+18h],2h
	setz	cl
	mov	[rdx+30h],rcx
	add	rdx,40h
	add	rsi,1h
	jnz	400FA0h

l0000000000400FB7:
	cmp	r8,+1C0h
	jc	401070h

l0000000000400FC4:
	nop	word ptr cs:[rax+rax+0h]

l0000000000400FD0:
	mov	ecx,[rdx+58h]
	xor	esi,esi
	cmp	dword ptr [rdx+18h],2h
	setz	sil
	mov	[rdx+30h],rsi
	xor	esi,esi
	cmp	ecx,2h
	setz	sil
	mov	[rdx+70h],rsi
	xor	ecx,ecx
	cmp	dword ptr [rdx+98h],2h
	setz	cl
	mov	[rdx+0B0h],rcx
	xor	ecx,ecx
	cmp	dword ptr [rdx+0D8h],2h
	setz	cl
	mov	[rdx+0F0h],rcx
	xor	ecx,ecx
	cmp	dword ptr [rdx+118h],2h
	setz	cl
	mov	[rdx+130h],rcx
	xor	ecx,ecx
	cmp	dword ptr [rdx+158h],2h
	setz	cl
	mov	[rdx+170h],rcx
	xor	ecx,ecx
	cmp	dword ptr [rdx+198h],2h
	setz	cl
	mov	[rdx+1B0h],rcx
	xor	ecx,ecx
	cmp	dword ptr [rdx+1D8h],2h
	setz	cl
	mov	[rdx+1F0h],rcx
	add	rdx,+200h
	cmp	r9,rdx
	jnz	400FD0h

l0000000000401070:
	mov	rdx,[rdi+228h]
	mov	r8,[rdi+230h]
	add	rdx,68h
	cmp	rdx,r8
	jz	4010A5h

l0000000000401087:
	nop	word ptr [rax+rax+0h]

l0000000000401090:
	mov	rcx,[rdx+30h]
	mov	rsi,[rdx+50h]
	mov	[rcx+30h],rsi
	add	rdx,68h
	cmp	r8,rdx
	jnz	401090h

l00000000004010A5:
	cmp	rax,r9
	jz	4010FCh

l00000000004010AA:
	xor	edx,edx
	xor	r8d,r8d
	nop

l00000000004010B0:
	cmp	qword ptr [rax+30h],0h
	jz	4010F1h

l00000000004010B7:
	mov	rcx,[rax+8h]
	mov	ecx,[rcx+60h]
	test	ecx,ecx
	js	4010E0h

l00000000004010C2:
	mov	rsi,[rax+38h]
	jnz	4010EEh

l00000000004010C8:
	add	rsi,rdx
	sub	rsi,[rdi+210h]
	add	r8,1h
	mov	rdx,rsi
	jmp	4010F1h
00000000004010DB                                  0F 1F 44 00 00            ..D..

l00000000004010E0:
	mov	rcx,[rax+10h]
	cmp	dword ptr [rcx+60h],0h
	jg	4010F1h

l00000000004010EA:
	mov	rsi,[rax+38h]

l00000000004010EE:
	add	rdx,rsi

l00000000004010F1:
	add	rax,40h
	cmp	r9,rax
	jnz	4010B0h

l00000000004010FA:
	jmp	401101h

l00000000004010FC:
	xor	r8d,r8d
	xor	edx,edx

l0000000000401101:
	cvtsi2sd	xmm0,r8
	cvtsi2sd	xmm1,qword ptr [rdi+210h]
	mulsd	xmm1,xmm0
	xorps	xmm0,xmm0
	cvtsi2sd	xmm0,rdx
	addsd	xmm0,xmm1
	ret

;; primal_feasible: 0000000000401120
;;   Called from:
;;     0000000000402990 (in primal_net_simplex)
primal_feasible proc
	push	rbp
	push	r15
	push	r14
	push	r13
	push	r12
	push	rbx
	push	rax
	mov	r15,rdi
	mov	rbx,[r15+228h]
	mov	rbp,[r15+230h]
	add	rbx,68h
	cmp	rbx,rbp
	jnc	4011DDh

l0000000000401149:
	mov	r12,[r15+248h]
	mov	r14,[r15+250h]
	nop	word ptr [rax+rax+0h]

l0000000000401160:
	mov	rax,[rbx+30h]
	mov	r13,[rbx+50h]
	cmp	rax,r12
	jc	4011B0h

l000000000040116D:
	cmp	rax,r14
	jnc	4011B0h

l0000000000401172:
	mov	rax,r13
	neg	rax
	cmovl	rax,r13

l000000000040117C:
	cmp	rax,[r15+200h]
	jle	4011CBh

l0000000000401185:
	mov	edi,402F51h
	xor	eax,eax
	call	400840h
	mov	esi,[rbx+60h]
	mov	edi,402F6Ah
	xor	eax,eax
	mov	rdx,r13
	call	400840h
	jmp	4011CBh
00000000004011A5                66 66 2E 0F 1F 84 00 00 00 00 00      ff.........

l00000000004011B0:
	mov	rax,[r15+200h]
	mov	rcx,rax
	neg	rcx
	cmp	r13,rcx
	jl	4011E6h

l00000000004011C2:
	lea	rcx,[r13-1h]
	cmp	rcx,rax
	jg	4011E6h

l00000000004011CB:
	add	rbx,68h
	cmp	rbx,rbp
	jc	401160h

l00000000004011D4:
	mov	ebx,1h
	xor	eax,eax
	jmp	401208h

l00000000004011DD:
	xor	eax,eax
	mov	ebx,1h
	jmp	401208h

l00000000004011E6:
	xor	ebx,ebx
	mov	edi,402F51h
	xor	eax,eax
	call	400840h
	mov	edi,402F9Bh
	xor	eax,eax
	mov	rsi,r13
	call	400840h
	mov	eax,1h

l0000000000401208:
	mov	[r15+1E8h],rbx
	add	rsp,8h
	pop	rbx
	pop	r12
	pop	r13
	pop	r14
	pop	r15
	pop	rbp
	ret
000000000040121E                                           66 90               f.

;; dual_feasible: 0000000000401220
;;   Called from:
;;     0000000000402998 (in primal_net_simplex)
dual_feasible proc
	push	rbx
	mov	rax,[rdi+238h]
	mov	rcx,[rdi+240h]
	xor	ebx,ebx
	cmp	rax,rcx
	jc	401249h

l0000000000401236:
	jmp	4012B6h
0000000000401238                         0F 1F 84 00 00 00 00 00         ........

l0000000000401240:
	add	rax,40h
	cmp	rax,rcx
	jnc	4012B6h

l0000000000401249:
	mov	rdx,[rax]
	mov	rsi,[rax+8h]
	sub	rdx,[rsi]
	mov	rsi,[rax+10h]
	add	rdx,[rsi]
	cmp	dword ptr [rax+18h],2h
	jnc	401270h

l0000000000401260:
	xor	esi,esi
	sub	rsi,[rdi+200h]
	cmp	rdx,rsi
	jge	401240h

l000000000040126E:
	jmp	40127Bh

l0000000000401270:
	jnz	401240h

l0000000000401272:
	cmp	rdx,[rdi+200h]
	jle	401240h

l000000000040127B:
	mov	rcx,[0000000000407F20]                                 ; [rip+00006C9E]
	mov	ebx,1h
	mov	edi,402FBAh
	mov	esi,16h
	mov	edx,1h
	call	4008A0h
	mov	rcx,[0000000000407F20]                                 ; [rip+00006C7E]
	mov	edi,402FD1h
	mov	esi,16h
	mov	edx,1h
	call	4008A0h

l00000000004012B6:
	mov	rax,rbx
	pop	rbx
	ret
00000000004012BB                                  0F 1F 44 00 00            ..D..

;; getfree: 00000000004012C0
;;   Called from:
;;     0000000000400B9E (in main)
;;     0000000000400BE8 (in main)
;;     000000000040162E (in read_min)
getfree proc
	push	rbx
	mov	rbx,rdi
	mov	rdi,[rbx+228h]
	test	rdi,rdi
	jz	4012D5h

l00000000004012D0:
	call	4008B0h

l00000000004012D5:
	mov	rdi,[rbx+238h]
	test	rdi,rdi
	jz	4012E6h

l00000000004012E1:
	call	4008B0h

l00000000004012E6:
	mov	rdi,[rbx+248h]
	add	rbx,+228h
	test	rdi,rdi
	jz	4012FEh

l00000000004012F9:
	call	4008B0h

l00000000004012FE:
	xorps	xmm0,xmm0
	movups	[rbx+20h],xmm0
	movups	[rbx+10h],xmm0
	movups	[rbx],xmm0
	xor	eax,eax
	pop	rbx
	ret

;; read_min: 0000000000401310
;;   Called from:
;;     0000000000400B85 (in main)
read_min proc
	push	rbp
	push	r15
	push	r14
	push	r13
	push	r12
	push	rbx
	sub	rsp,+108h
	mov	rbp,rdi
	mov	esi,402FE8h
	call	4008C0h
	mov	rbx,rax
	mov	r15,-1h
	test	rbx,rbx
	jz	40171Ch

l0000000000401341:
	lea	r14,[rsp+30h]
	mov	esi,0C8h
	mov	rdi,r14
	mov	rdx,rbx
	call	4008D0h
	lea	rdx,[rsp+8h]
	mov	rcx,rsp
	mov	esi,402FEAh
	xor	eax,eax
	mov	rdi,r14
	call	4008E0h
	cmp	eax,2h
	jnz	40171Ch

l0000000000401376:
	mov	[rsp+10h],rbx
	mov	rdx,[rsp+8h]
	mov	[rbp+198h],rdx
	mov	rax,[rsp]
	mov	[rbp+1B0h],rax
	lea	r12,[rdx+rdx]
	add	r12,1h
	mov	[rbp+190h],r12
	lea	r15,[rdx+rdx*2]
	add	r15,rax
	mov	[rbp+1A8h],r15
	cmp	rdx,+3A99h
	mov	ebx,1A10000h
	cmovl	rbx,r15

l00000000004013BF:
	mov	eax,2DC6C0h
	mov	ecx,1B8FAA0h
	cmovl	rcx,rax

l00000000004013CD:
	mov	[rbp+1A0h],rbx
	mov	[rbp+1C8h],rcx
	mov	rax,rbx
	sub	rax,r15
	mov	[rbp+1C0h],rax
	mov	[rsp+20h],rdx
	lea	rdi,[rdx+rdx]
	add	rdi,2h
	mov	esi,68h
	call	4008F0h
	mov	r13,rax
	mov	[rbp+228h],r13
	mov	esi,40h
	mov	rdi,r12
	call	4008F0h
	mov	r14,rax
	mov	[rbp+248h],r14
	mov	esi,40h
	mov	rdi,rbx
	call	4008F0h
	mov	rbx,rax
	mov	[rbp+238h],rbx
	test	rbx,rbx
	jz	401621h

l0000000000401440:
	test	r13,r13
	jz	401621h

l0000000000401449:
	test	r14,r14
	jz	401621h

l0000000000401452:
	imul	rax,r12,68h
	add	rax,r13
	add	rax,68h
	mov	[rbp+230h],rax
	shl	r15,6h
	add	r15,rbx
	mov	[rbp+240h],r15
	shl	r12,6h
	add	r14,r12
	mov	[rbp+250h],r14
	mov	r8,[rsp+20h]
	test	r8,r8
	mov	[rsp+18h],rbp
	jle	40163Fh

l0000000000401493:
	lea	r14,[r13+68h]
	mov	r12d,0FFFFFFFFh
	mov	r15d,1h
	nop	word ptr cs:[rax+rax+0h]

l00000000004014B0:
	mov	esi,0C8h
	lea	rbp,[rsp+30h]
	mov	rdi,rbp
	mov	rdx,[rsp+10h]
	call	4008D0h
	mov	esi,402FEAh
	xor	eax,eax
	mov	rdi,rbp
	lea	rdx,[rsp+8h]
	mov	rcx,rsp
	call	4008E0h
	cmp	eax,2h
	jnz	401715h

l00000000004014E7:
	mov	rdx,[rsp+8h]
	mov	rcx,[rsp]
	cmp	rdx,rcx
	jg	401715h

l00000000004014F9:
	mov	[r14+60h],r12d
	mov	qword ptr [r14+50h],-1h
	mov	rsi,[rsp+18h]
	mov	r8,[rsi+198h]
	lea	rax,[r15+r8]
	imul	rax,rax,68h
	mov	[r13+rax+60h],r15d
	mov	qword ptr [r13+rax+50h],+1h
	mov	[r14+64h],edx
	mov	[r13+rax+64h],ecx
	imul	rcx,[rsi+190h],68h
	lea	rdx,[rcx+r13]
	mov	[rbx+8h],rdx
	mov	[rbx+10h],r14
	mov	rsi,[rsi+210h]
	lea	rdi,[rsi+0Fh]
	mov	[rbx],rdi
	mov	[rbx+38h],rdi
	mov	rdi,[r13+rcx+38h]
	mov	[rbx+20h],rdi
	mov	[r13+rcx+38h],rbx
	lea	rdi,[r13+rax+0h]
	mov	rbp,[r14+40h]
	mov	[rbx+28h],rbp
	mov	[r14+40h],rbx
	mov	[rbx+48h],rdi
	mov	[rbx+50h],rdx
	mov	qword ptr [rbx+40h],+0Fh
	mov	qword ptr [rbx+78h],+0Fh
	mov	rdx,[r13+rax+38h]
	mov	[rbx+60h],rdx
	lea	rdx,[rbx+40h]
	mov	[r13+rax+38h],rdx
	mov	rbp,[r13+rcx+40h]
	mov	[rbx+68h],rbp
	mov	[r13+rcx+40h],rdx
	mov	rcx,rbx
	mov	[rbx+88h],r14
	mov	[rbx+90h],rdi
	sub	rcx,80h
	cmp	rsi,+98967Fh
	mov	edx,989680h
	cmovle	rsi,rdx

l00000000004015D2:
	add	rsi,rsi
	mov	[rbx+80h],rsi
	mov	[rbx+0B8h],rsi
	mov	rdx,[r14+38h]
	mov	[rbx+0A0h],rdx
	mov	[r14+38h],rcx
	mov	rdx,[r13+rax+40h]
	mov	[rbx+0A8h],rdx
	mov	[r13+rax+40h],rcx
	add	rbx,+0C0h
	add	r14,68h
	add	r12d,0FFh
	cmp	r15,r8
	lea	r15,[r15+1h]
	jl	4014B0h

l000000000040161F:
	jmp	401645h

l0000000000401621:
	mov	edi,403140h
	call	400850h
	mov	rdi,rbp
	call	getfree
	mov	r15,-1h
	jmp	40171Ch

l000000000040163F:
	mov	r15d,1h

l0000000000401645:
	add	r8,1h
	cmp	r15,r8
	jnz	401715h

l0000000000401652:
	mov	r15,[rsp+18h]
	cmp	qword ptr [r15+1B0h],0h
	jle	401731h

l0000000000401665:
	lea	r14,[rsp+30h]
	xor	ebp,ebp
	mov	r12,[rsp+10h]
	nop	word ptr cs:[rax+rax+0h]

l0000000000401680:
	mov	esi,0C8h
	mov	rdi,r14
	mov	rdx,r12
	call	4008D0h
	mov	esi,402FF2h
	xor	eax,eax
	mov	rdi,r14
	lea	rdx,[rsp+8h]
	mov	rcx,rsp
	lea	r8,[rsp+28h]
	call	4008E0h
	cmp	eax,3h
	jnz	401715h

l00000000004016B1:
	mov	rax,[r15+198h]
	add	rax,[rsp+8h]
	imul	rax,rax,68h
	lea	rcx,[rax+r13]
	mov	[rbx+8h],rcx
	imul	rcx,[rsp],68h
	lea	rdx,[rcx+r13]
	mov	[rbx+10h],rdx
	mov	rdx,[rsp+28h]
	mov	[rbx+38h],rdx
	mov	[rbx],rdx
	mov	rdx,[r13+rax+38h]
	mov	[rbx+20h],rdx
	mov	[r13+rax+38h],rbx
	mov	rax,[r13+rcx+40h]
	mov	[rbx+28h],rax
	mov	[r13+rcx+40h],rbx
	add	rbp,1h
	add	rbx,40h
	cmp	rbp,[r15+1B0h]
	jl	401680h

l0000000000401713:
	jmp	401736h

l0000000000401715:
	mov	r15,-1h

l000000000040171C:
	mov	rax,r15
	add	rsp,+108h
	pop	rbx
	pop	r12
	pop	r13
	pop	r14
	pop	r15
	pop	rbp
	ret

l0000000000401731:
	mov	r12,[rsp+10h]

l0000000000401736:
	cmp	[r15+240h],rbx
	jz	401772h

l000000000040173F:
	mov	[r15+240h],rbx
	mov	rax,[r15+238h]
	cmp	rax,rbx
	jnc	401762h

l0000000000401752:
	not	rax
	add	rbx,rax
	shr	rbx,6h
	add	rbx,1h
	jmp	401764h

l0000000000401762:
	xor	ebx,ebx

l0000000000401764:
	mov	[r15+1A8h],rbx
	mov	[r15+1B0h],rbx

l0000000000401772:
	mov	rdi,r12
	call	400900h
	mov	byte ptr [r15+0C8h],0h
	mov	rsi,[r15+198h]
	test	rsi,rsi
	jle	401818h

l0000000000401792:
	mov	rdx,[r15+210h]
	mov	rax,[r15+238h]
	cmp	rdx,+98967Fh
	mov	ecx,989680h
	cmovg	rcx,rdx

l00000000004017B0:
	add	rcx,rcx
	neg	rcx
	mov	ebp,esi
	and	ebp,1h
	cmp	rsi,1h
	jnz	4017CDh

l00000000004017C1:
	mov	esi,2h
	test	rbp,rbp
	jnz	40180Bh

l00000000004017CB:
	jmp	401818h

l00000000004017CD:
	lea	rdi,[rax+178h]
	mov	rdx,rbp
	sub	rdx,rsi
	mov	esi,2h
	nop

l00000000004017E0:
	mov	[rdi-0F8h],rcx
	mov	[rdi-0C0h],rcx
	mov	[rdi-38h],rcx
	mov	[rdi],rcx
	add	rdi,+180h
	add	rsi,6h
	add	rdx,2h
	jnz	4017E0h

l0000000000401806:
	test	rbp,rbp
	jz	401818h

l000000000040180B:
	shl	rsi,6h
	mov	[rax+rsi],rcx
	mov	[rax+rsi+38h],rcx

l0000000000401818:
	xor	r15d,r15d
	jmp	40171Ch

;; resize_prob: 0000000000401820
;;   Called from:
;;     0000000000401ADA (in price_out_impl)
resize_prob proc
	push	rbx
	mov	rbx,rdi
	mov	rax,[rbx+1C8h]
	mov	rdi,[rbx+238h]
	mov	rsi,[rbx+1A0h]
	add	rsi,rax
	mov	[rbx+1A0h],rsi
	add	[rbx+1C0h],rax
	shl	rsi,6h
	call	400910h
	test	rax,rax
	jz	4018B5h

l0000000000401858:
	mov	rcx,[rbx+238h]
	mov	[rbx+238h],rax
	mov	rsi,[rbx+1A8h]
	mov	rdx,[rbx+228h]
	shl	rsi,6h
	add	rsi,rax
	mov	[rbx+240h],rsi
	mov	rsi,[rbx+230h]
	lea	rdi,[rdx+68h]
	cmp	rdi,rsi
	jnc	4018D9h

l0000000000401892:
	sub	rax,rcx
	xor	ecx,ecx
	nop	word ptr [rax+rax+0h]

l00000000004018A0:
	cmp	[rdi+18h],rdx
	jz	4018AAh

l00000000004018A6:
	add	[rdi+30h],rax

l00000000004018AA:
	add	rdi,68h
	cmp	rdi,rsi
	jc	4018A0h

l00000000004018B3:
	jmp	4018DBh

l00000000004018B5:
	mov	edi,402FFEh
	xor	eax,eax
	mov	rsi,rbx
	call	400840h
	mov	rdi,[0000000000407F28]                                 ; [rip+0000665D]
	call	400920h
	mov	rcx,-1h
	jmp	4018DBh

l00000000004018D9:
	xor	ecx,ecx

l00000000004018DB:
	mov	rax,rcx
	pop	rbx
	ret

;; insert_new_arc: 00000000004018E0
insert_new_arc proc
	push	r15
	push	r14
	push	rbx
	mov	rax,rsi
	shl	rax,6h
	mov	[rdi+rax+8h],rdx
	mov	[rdi+rax+10h],rcx
	mov	[rdi+rax+38h],r8
	mov	[rdi+rax],r8
	mov	[rdi+rax+30h],r9
	test	rsi,rsi
	jz	40197Bh

l0000000000401909:
	lea	r11,[rsi+1h]
	nop	dword ptr [rax]

l0000000000401910:
	mov	rax,r11
	shr	rax,3Fh
	add	r11,rax
	sar	r11,1h
	lea	r10,[r11-1h]
	mov	rax,r10
	shl	rax,6h
	mov	r15,[rdi+rax+30h]
	cmp	r15,r9
	jge	40197Bh

l0000000000401932:
	mov	r14,[rdi+rax+10h]
	shl	rsi,6h
	mov	[rdi+rsi+10h],r14
	movups	xmm0,[rdi+rax]
	movups	[rdi+rsi],xmm0
	mov	rbx,[rdi+rax]
	mov	[rdi+rsi+38h],rbx
	mov	[rdi+rsi+30h],r15
	mov	[rdi+rax+8h],rdx
	mov	[rdi+rax+10h],rcx
	mov	[rdi+rax],r8
	mov	[rdi+rax+38h],r8
	add	rax,rdi
	add	rax,30h
	mov	[rax],r9
	mov	rsi,r10
	test	r10,r10
	jnz	401910h

l000000000040197B:
	pop	rbx
	pop	r14
	pop	r15
	ret
0000000000401981    66 66 66 66 66 66 2E 0F 1F 84 00 00 00 00 00  ffffff.........

;; replace_weaker_arc: 0000000000401990
replace_weaker_arc proc
	push	r15
	push	r14
	push	rbx
	mov	[rsi+8h],rdx
	mov	[rsi+10h],rcx
	mov	[rsi+38h],r8
	mov	[rsi],r8
	mov	[rsi+30h],r9
	mov	rax,[rsi+70h]
	xor	ebx,ebx
	cmp	rax,[rsi+0B0h]
	setg	bl
	mov	r11d,3h
	sub	r11,rbx
	mov	r10,[rdi+1C0h]
	cmp	r11,r10
	jg	401A6Bh

l00000000004019D1:
	mov	edi,1h
	nop	word ptr cs:[rax+rax+0h]

l00000000004019E0:
	mov	r14,r11
	lea	rax,[r14-1h]
	shl	rax,6h
	mov	r11,[rsi+rax+30h]
	cmp	r11,r9
	jle	401A6Bh

l00000000004019F5:
	shl	rdi,6h
	mov	rbx,[rsi+rax+10h]
	mov	[rsi+rdi-30h],rbx
	movups	xmm0,[rsi+rax]
	movups	[rsi+rdi-40h],xmm0
	lea	r15,[rsi+rax+30h]
	mov	rbx,[rsi+rax]
	mov	[rsi+rdi-8h],rbx
	mov	[rsi+rdi-10h],r11
	mov	[rsi+rax+8h],rdx
	mov	[rsi+rax+10h],rcx
	mov	[rsi+rax],r8
	mov	[rsi+rax+38h],r8
	mov	[r15],r9
	lea	r11,[r14+r14]
	lea	rax,[r14+r14]
	add	rax,1h
	cmp	rax,r10
	jg	401A5Fh

l0000000000401A46:
	mov	rdi,r11
	shl	rdi,6h
	mov	rbx,[rsi+rdi-10h]
	cmp	rbx,[rsi+rdi+30h]
	jl	401A5Ch

l0000000000401A59:
	mov	rax,r11

l0000000000401A5C:
	mov	r11,rax

l0000000000401A5F:
	mov	rdi,r14
	cmp	r11,r10
	jle	4019E0h

l0000000000401A6B:
	pop	rbx
	pop	r14
	pop	r15
	ret
0000000000401A71    66 66 66 66 66 66 2E 0F 1F 84 00 00 00 00 00  ffffff.........

;; price_out_impl: 0000000000401A80
;;   Called from:
;;     0000000000400AB5 (in global_opt)
price_out_impl proc
	push	rbp
	push	r15
	push	r14
	push	r13
	push	r12
	push	rbx
	sub	rsp,38h
	mov	r8,[rdi+198h]
	mov	rbx,[rdi+210h]
	cmp	r8,+3A99h
	jge	401B0Eh

l0000000000401AA5:
	mov	rax,[rdi+1A0h]
	mov	rcx,[rdi+1A8h]
	mov	rdx,[rdi+1C8h]
	add	rdx,rcx
	cmp	rdx,rax
	jle	401B2Ch

l0000000000401AC2:
	mov	rdx,r8
	imul	rdx,rdx
	shr	rdx,1h
	add	rcx,rdx
	cmp	rcx,rax
	jle	401B2Ch

l0000000000401AD4:
	mov	r14,rbx
	mov	rbp,rdi
	call	resize_prob
	mov	rcx,rax
	mov	rax,-1h
	test	rcx,rcx
	jnz	402072h

l0000000000401AF2:
	mov	rdi,rbp
	call	refresh_neighbour_lists
	mov	r8,[rbp+198h]
	mov	eax,1h
	mov	rdi,rbp
	mov	rbx,r14
	jmp	401B2Eh

l0000000000401B0E:
	lea	rax,[rdi+240h]
	mov	[rsp+28h],rax
	mov	r10,[rdi+238h]
	mov	r11,[rdi+240h]
	xor	eax,eax
	jmp	401B51h

l0000000000401B2C:
	xor	eax,eax

l0000000000401B2E:
	lea	rcx,[rdi+240h]
	mov	r10,[rdi+238h]
	mov	r11,[rdi+240h]
	test	r8,r8
	mov	[rsp+28h],rcx
	jle	401F99h

l0000000000401B51:
	xor	r14d,r14d
	nop	word ptr cs:[rax+rax+0h]

l0000000000401B60:
	cmp	dword ptr [r10+58h],0FFh
	jnz	401B77h

l0000000000401B67:
	add	r14,1h
	add	r10,+0C0h
	cmp	r14,r8
	jl	401B60h

l0000000000401B77:
	cmp	r14,r8
	jge	401FA5h

l0000000000401B80:
	mov	[rsp+30h],rax
	add	rbx,0F1h
	xor	esi,esi
	xor	eax,eax
	mov	[rsp+18h],rbx
	mov	[rsp+10h],r8
	mov	[rsp+20h],rdi
	nop	dword ptr [rax+0h]

l0000000000401BA0:
	cmp	dword ptr [r10+58h],0FFh
	jz	401BBEh

l0000000000401BA7:
	mov	rcx,[r10+10h]
	mov	rcx,[rcx+38h]
	mov	rcx,[rcx+10h]
	mov	[rcx+48h],rsi
	lea	rcx,[r10+40h]
	mov	rsi,rcx

l0000000000401BBE:
	cmp	dword ptr [r10+18h],0FFh
	jz	401E5Eh

l0000000000401BC9:
	mov	rcx,[rsi+8h]
	mov	rbp,[rcx+48h]
	test	rbp,rbp
	jz	401E5Eh

l0000000000401BDA:
	mov	r12,[r10+10h]
	movsxd	rcx,dword ptr [r12+64h]
	mov	r15,rbx
	sub	r15,[r10+38h]
	add	r15,rcx
	jmp	401E40h

l0000000000401BF2:
	mov	r13d,1Eh
	sub	r13,[rdx]
	add	r13,[r12]
	jns	401E55h

l0000000000401C05:
	mov	rbp,[rdi+1C0h]
	cmp	rax,rbp
	jge	401CEFh

l0000000000401C15:
	mov	rcx,rax
	shl	rcx,6h
	mov	[r11+rcx+8h],rdx
	mov	[r11+rcx+10h],r12
	mov	qword ptr [r11+rcx+38h],+1Eh
	mov	qword ptr [r11+rcx],+1Eh
	mov	[r11+rcx+30h],r13
	test	rax,rax
	jz	401D42h

l0000000000401C45:
	mov	[rsp+8h],rsi
	lea	r8,[rax+1h]
	mov	rbp,r8
	nop	word ptr cs:[rax+rax+0h]

l0000000000401C60:
	mov	rcx,rbp
	shr	rcx,3Fh
	add	rbp,rcx
	sar	rbp,1h
	lea	rsi,[rbp-1h]
	mov	rdi,rsi
	shl	rdi,6h
	mov	rcx,[r11+rdi+30h]
	cmp	rcx,r13
	jge	401CD3h

l0000000000401C82:
	mov	r9,[r11+rdi+10h]
	shl	rax,6h
	mov	[r11+rax+10h],r9
	movups	xmm0,[r11+rdi]
	movups	[r11+rax],xmm0
	mov	rbx,[r11+rdi]
	mov	[r11+rax+38h],rbx
	mov	[r11+rax+30h],rcx
	mov	[r11+rdi+8h],rdx
	lea	rax,[r11+rdi+30h]
	mov	[r11+rdi+10h],r12
	mov	qword ptr [r11+rdi],+1Eh
	mov	qword ptr [r11+rdi+38h],+1Eh
	mov	[rax],r13
	mov	rax,rsi
	test	rsi,rsi
	jnz	401C60h

l0000000000401CD3:
	mov	rax,r8
	mov	rdi,[rsp+20h]
	mov	rbx,[rsp+18h]
	mov	r8,[rsp+10h]
	mov	rsi,[rsp+8h]
	jmp	401E55h

l0000000000401CEF:
	cmp	[r11+30h],r13
	jle	401E55h

l0000000000401CF9:
	mov	[rsp+8h],rsi
	mov	[r11+8h],rdx
	mov	[r11+10h],r12
	mov	qword ptr [r11+38h],+1Eh
	mov	qword ptr [r11],+1Eh
	mov	[r11+30h],r13
	mov	rcx,[r11+70h]
	xor	esi,esi
	cmp	rcx,[r11+0B0h]
	setg	sil
	mov	r9d,3h
	sub	r9,rsi
	cmp	r9,rbp
	jle	401D4Ch

l0000000000401D38:
	mov	rsi,[rsp+8h]
	jmp	401E55h

l0000000000401D42:
	mov	eax,1h
	jmp	401E55h

l0000000000401D4C:
	mov	edi,1h
	mov	rsi,[rsp+8h]
	nop	word ptr cs:[rax+rax+0h]

l0000000000401D60:
	mov	rbx,r12
	mov	r12,rbp
	mov	r8,r9
	lea	rbp,[r8-1h]
	shl	rbp,6h
	mov	rcx,[r11+rbp+30h]
	cmp	rcx,r13
	jle	401E1Eh

l0000000000401D7F:
	lea	r9,[r11+rbp]
	add	r9,30h
	shl	rdi,6h
	mov	rsi,[r11+rbp+10h]
	mov	[r11+rdi-30h],rsi
	movups	xmm0,[r11+rbp]
	movups	[r11+rdi-40h],xmm0
	mov	rsi,[r11+rbp]
	mov	[r11+rdi-8h],rsi
	mov	[r11+rdi-10h],rcx
	mov	[r11+rbp+8h],rdx
	mov	[r11+rbp+10h],rbx
	mov	qword ptr [r11+rbp],+1Eh
	mov	qword ptr [r11+rbp+38h],+1Eh
	mov	[r9],r13
	lea	r9,[r8+r8]
	lea	rcx,[r8+r8]
	add	rcx,1h
	mov	rbp,r12
	cmp	rcx,rbp
	jg	401DF9h

l0000000000401DE0:
	mov	rsi,r9
	shl	rsi,6h
	mov	rdi,[r11+rsi-10h]
	cmp	rdi,[r11+rsi+30h]
	jl	401DF6h

l0000000000401DF3:
	mov	rcx,r9

l0000000000401DF6:
	mov	r9,rcx

l0000000000401DF9:
	mov	rsi,[rsp+8h]
	mov	r12,rbx
	mov	rdi,r8
	cmp	r9,rbp
	jle	401D60h

l0000000000401E0D:
	mov	rdi,[rsp+20h]
	mov	rbx,[rsp+18h]
	mov	r8,[rsp+10h]
	jmp	401E55h

l0000000000401E1E:
	mov	rdi,[rsp+20h]
	mov	rcx,[rsp+18h]
	mov	r8,[rsp+10h]
	mov	r12,rbx
	mov	rbx,rcx
	jmp	401E55h
0000000000401E35                66 66 2E 0F 1F 84 00 00 00 00 00      ff.........

l0000000000401E40:
	mov	rdx,[rbp+8h]
	movsxd	rcx,dword ptr [rdx+64h]
	add	rcx,[rbp+38h]
	cmp	rcx,r15
	jle	401BF2h

l0000000000401E55:
	mov	rbp,[rdx+48h]
	test	rbp,rbp
	jnz	401E40h

l0000000000401E5E:
	add	r14,1h
	add	r10,+0C0h
	cmp	r14,r8
	jnz	401BA0h

l0000000000401E72:
	test	rax,rax
	jz	401FA5h

l0000000000401E7B:
	mov	rsi,rax
	shl	rsi,6h
	lea	rdx,[r11+rsi]
	mov	rcx,[rsp+28h]
	mov	[rcx],rdx
	add	rsi,0C0h
	cmp	qword ptr [rsp+30h],0h
	jz	401FACh

l0000000000401E9E:
	mov	ecx,esi
	shr	ecx,6h
	add	ecx,1h
	and	rcx,7h
	jz	401ECAh

l0000000000401EAC:
	neg	rcx
	nop

l0000000000401EB0:
	mov	qword ptr [r11+30h],+0h
	mov	dword ptr [r11+18h],1h
	add	r11,40h
	add	rcx,1h
	jnz	401EB0h

l0000000000401ECA:
	cmp	rsi,+1C0h
	jc	40205Dh

l0000000000401ED7:
	nop	word ptr [rax+rax+0h]

l0000000000401EE0:
	mov	qword ptr [r11+30h],+0h
	mov	dword ptr [r11+18h],1h
	mov	qword ptr [r11+70h],+0h
	mov	dword ptr [r11+58h],1h
	mov	qword ptr [r11+0B0h],+0h
	mov	dword ptr [r11+98h],1h
	mov	qword ptr [r11+0F0h],+0h
	mov	dword ptr [r11+0D8h],1h
	mov	qword ptr [r11+130h],+0h
	mov	dword ptr [r11+118h],1h
	mov	qword ptr [r11+170h],+0h
	mov	dword ptr [r11+158h],1h
	mov	qword ptr [r11+1B0h],+0h
	mov	dword ptr [r11+198h],1h
	mov	qword ptr [r11+1F0h],+0h
	mov	dword ptr [r11+1D8h],1h
	add	r11,+200h
	cmp	rdx,r11
	jnz	401EE0h

l0000000000401F94:
	jmp	40205Dh

l0000000000401F99:
	xor	r14d,r14d
	cmp	r14,r8
	jl	401B80h

l0000000000401FA5:
	xor	eax,eax
	jmp	402072h

l0000000000401FAC:
	test	sil,40h
	jnz	401FE6h

l0000000000401FB2:
	mov	qword ptr [r11+30h],+0h
	mov	dword ptr [r11+18h],1h
	mov	rcx,[r11+8h]
	mov	rbp,[rcx+38h]
	mov	[r11+20h],rbp
	mov	[rcx+38h],r11
	mov	rcx,[r11+10h]
	mov	rbp,[rcx+40h]
	mov	[r11+28h],rbp
	mov	[rcx+40h],r11
	add	r11,40h

l0000000000401FE6:
	test	rsi,rsi
	jz	40205Dh

l0000000000401FEB:
	nop	dword ptr [rax+rax+0h]

l0000000000401FF0:
	mov	qword ptr [r11+30h],+0h
	mov	dword ptr [r11+18h],1h
	mov	rcx,[r11+8h]
	mov	rsi,[rcx+38h]
	mov	[r11+20h],rsi
	mov	[rcx+38h],r11
	mov	rcx,[r11+10h]
	mov	rsi,[rcx+40h]
	mov	[r11+28h],rsi
	mov	[rcx+40h],r11
	lea	rcx,[r11+40h]
	mov	qword ptr [r11+70h],+0h
	mov	dword ptr [r11+58h],1h
	mov	rsi,[r11+48h]
	mov	rbp,[rsi+38h]
	mov	[r11+60h],rbp
	mov	[rsi+38h],rcx
	mov	rsi,[r11+50h]
	mov	rbp,[rsi+40h]
	mov	[r11+68h],rbp
	mov	[rsi+40h],rcx
	sub	r11,80h
	cmp	rdx,r11
	jnz	401FF0h

l000000000040205D:
	add	[rdi+1A8h],rax
	add	[rdi+1B8h],rax
	sub	[rdi+1C0h],rax

l0000000000402072:
	add	rsp,38h
	pop	rbx
	pop	r12
	pop	r13
	pop	r14
	pop	r15
	pop	rbp
	ret
0000000000402081    66 66 66 66 66 66 2E 0F 1F 84 00 00 00 00 00  ffffff.........

;; suspend_impl: 0000000000402090
;;   Called from:
;;     0000000000400A94 (in global_opt)
suspend_impl proc
	push	r14
	push	rbx
	push	rax
	test	rdx,rdx
	jz	4020AEh

l0000000000402099:
	mov	r14,[rdi+1B8h]
	test	r14,r14
	jnz	402157h

l00000000004020A9:
	jmp	402181h

l00000000004020AE:
	mov	rax,[rdi+1A8h]
	mov	r8,[rdi+240h]
	sub	rax,[rdi+1B8h]
	shl	rax,6h
	add	rax,[rdi+238h]
	xor	r14d,r14d
	cmp	rax,r8
	jnc	402184h

l00000000004020DA:
	mov	rdx,rax
	nop	dword ptr [rax]

l00000000004020E0:
	mov	ebx,[rax+18h]
	mov	rcx,-2h
	test	ebx,ebx
	jz	402110h

l00000000004020EE:
	cmp	ebx,1h
	jnz	402104h

l00000000004020F3:
	mov	rcx,[rax]
	mov	rbx,[rax+8h]
	sub	rcx,[rbx]
	mov	rbx,[rax+10h]
	add	rcx,[rbx]

l0000000000402104:
	cmp	rcx,rsi
	jle	402127h

l0000000000402109:
	add	r14,1h
	jmp	402149h
000000000040210F                                              90                .

l0000000000402110:
	mov	rbx,[rax+8h]
	cmp	rax,[rbx+30h]
	jz	40211Eh

l000000000040211A:
	mov	rbx,[rax+10h]

l000000000040211E:
	mov	[rbx+30h],rdx
	cmp	rcx,rsi
	jg	402109h

l0000000000402127:
	movups	xmm0,[rax]
	movups	xmm1,[rax+10h]
	movups	xmm2,[rax+20h]
	movups	xmm3,[rax+30h]
	movups	[rdx+30h],xmm3
	movups	[rdx+20h],xmm2
	movups	[rdx+10h],xmm1
	movups	[rdx],xmm0
	add	rdx,40h

l0000000000402149:
	add	rax,40h
	cmp	rax,r8
	jc	4020E0h

l0000000000402152:
	test	r14,r14
	jz	402181h

l0000000000402157:
	sub	[rdi+1A8h],r14
	sub	[rdi+1B8h],r14
	mov	rax,r14
	shl	rax,6h
	sub	[rdi+240h],rax
	add	[rdi+1C0h],r14
	call	refresh_neighbour_lists
	jmp	402184h

l0000000000402181:
	xor	r14d,r14d

l0000000000402184:
	mov	rax,r14
	add	rsp,8h
	pop	rbx
	pop	r14
	ret
000000000040218F                                              90                .

;; primal_start_artificial: 0000000000402190
;;   Called from:
;;     0000000000400BBD (in main)
primal_start_artificial proc
	mov	r10,[rdi+228h]
	lea	r8,[r10+68h]
	mov	qword ptr [r10+30h],+0h
	mov	qword ptr [r10+18h],+0h
	mov	[r10+10h],r8
	pxor	xmm0,xmm0
	movdqu	[r10+20h],xmm0
	mov	rcx,[rdi+190h]
	add	rcx,1h
	mov	[r10+58h],rcx
	mov	dword ptr [r10+8h],0h
	mov	qword ptr [r10],-5F5E100h
	mov	qword ptr [r10+50h],+0h
	mov	rdx,[rdi+238h]
	mov	rsi,[rdi+240h]
	cmp	rdx,rsi
	jz	40227Ch

l00000000004021F6:
	lea	r9,[rsi-40h]
	sub	r9,rdx
	mov	ecx,r9d
	shr	ecx,6h
	add	ecx,1h
	and	rcx,3h
	jz	402227h

l000000000040220C:
	neg	rcx
	nop

l0000000000402210:
	cmp	dword ptr [rdx+18h],0FFh
	jz	40221Dh

l0000000000402216:
	mov	dword ptr [rdx+18h],1h

l000000000040221D:
	add	rdx,40h
	add	rcx,1h
	jnz	402210h

l0000000000402227:
	cmp	r9,+0C0h
	jc	40227Ch

l0000000000402230:
	cmp	dword ptr [rdx+18h],0FFh
	jz	40223Dh

l0000000000402236:
	mov	dword ptr [rdx+18h],1h

l000000000040223D:
	cmp	dword ptr [rdx+58h],0FFh
	jz	40224Ah

l0000000000402243:
	mov	dword ptr [rdx+58h],1h

l000000000040224A:
	cmp	dword ptr [rdx+98h],0FFh
	jz	40225Dh

l0000000000402253:
	mov	dword ptr [rdx+98h],1h

l000000000040225D:
	cmp	dword ptr [rdx+0D8h],0FFh
	jz	402270h

l0000000000402266:
	mov	dword ptr [rdx+0D8h],1h

l0000000000402270:
	add	rdx,+100h
	cmp	rsi,rdx
	jnz	402230h

l000000000040227C:
	mov	rcx,[rdi+230h]
	cmp	r8,rcx
	jz	40231Eh

l000000000040228C:
	mov	rsi,[rdi+248h]
	add	rcx,98h
	mov	edx,1h
	movd	xmm0,rdx
	pslldq	xmm0,8h
	mov	rdx,r10
	nop	dword ptr [rax+0h]
	mov	rdi,rdx
	lea	rdx,[rdi+68h]
	mov	[rdi+98h],rsi
	mov	[rdi+80h],r10
	mov	qword ptr [rdi+78h],+0h
	lea	rax,[rdi+0D0h]
	mov	[rdi+88h],rax
	mov	[rdi+90h],rdi
	mov	qword ptr [rsi],+5F5E100h
	mov	dword ptr [rsi+18h],0h
	mov	dword ptr [rdi+70h],1h
	mov	qword ptr [rdi+68h],+0h
	mov	[rsi+8h],rdx
	mov	[rsi+10h],r10
	movdqu	[rdi+0B8h],xmm0
	add	rsi,40h
	cmp	rcx,rdx
	jnz	4022B0h
	add	rdx,20h
	jmp	402322h

l000000000040231E:
	lea	rdx,[r10+20h]
	mov	qword ptr [rdx],+0h
	mov	qword ptr [r10+90h],+0h
	xor	eax,eax
	ret
0000000000402337                      66 0F 1F 84 00 00 00 00 00        f........

;; write_circulations: 0000000000402340
;;   Called from:
;;     0000000000400BDB (in main)
write_circulations proc
	push	rbp
	push	r15
	push	r14
	push	r13
	push	r12
	push	rbx
	push	rax
	mov	rbx,rsi
	mov	rbp,[rbx+1B8h]
	mov	r12,[rbx+240h]
	mov	esi,40301Dh
	call	4008C0h
	mov	r15,rax
	mov	r14,-1h
	test	r15,r15
	jz	402472h

l0000000000402379:
	mov	rdi,rbx
	call	refresh_neighbour_lists
	mov	rax,[rbx+228h]
	imul	rcx,[rbx+190h],68h
	mov	r13,[rax+rcx+38h]
	test	r13,r13
	jz	40245Dh

l000000000040239E:
	shl	rbp,6h
	sub	r12,rbp

l00000000004023A5:
	cmp	qword ptr [r13+30h],0h
	jz	402450h

l00000000004023B0:
	mov	edi,40301Fh
	mov	esi,3h
	mov	edx,1h
	mov	rcx,r15
	call	4008A0h
	mov	rbp,r13

l00000000004023CA:
	cmp	rbp,r12
	jc	4023E6h

l00000000004023CF:
	mov	edi,403023h
	mov	esi,4h
	mov	edx,1h
	mov	rcx,r15
	call	4008A0h

l00000000004023E6:
	mov	rax,[rbp+10h]
	xor	edx,edx
	sub	edx,[rax+60h]
	mov	esi,403028h
	xor	eax,eax
	mov	rdi,r15
	call	400930h
	mov	rax,[rbp+10h]
	imul	rcx,[rbx+198h],68h
	mov	rax,[rax+rcx+38h]
	test	rax,rax
	jnz	402429h

l0000000000402414:
	jmp	40246Ah
0000000000402416                   66 2E 0F 1F 84 00 00 00 00 00       f.........

l0000000000402420:
	mov	rax,[rax+20h]
	test	rax,rax
	jz	40246Ah

l0000000000402429:
	cmp	qword ptr [rax+30h],0h
	jz	402420h

l0000000000402430:
	mov	rcx,[rax+10h]
	cmp	dword ptr [rcx+60h],0h
	mov	ebp,0h
	cmovnz	rbp,rax

l0000000000402441:
	test	rbp,rbp
	jnz	4023CAh

l0000000000402446:
	nop	word ptr cs:[rax+rax+0h]

l0000000000402450:
	mov	r13,[r13+20h]
	test	r13,r13
	jnz	4023A5h

l000000000040245D:
	mov	rdi,r15
	call	400900h
	xor	r14d,r14d
	jmp	402472h

l000000000040246A:
	mov	rdi,r15
	call	400900h

l0000000000402472:
	mov	rax,r14
	add	rsp,8h
	pop	rbx
	pop	r12
	pop	r13
	pop	r14
	pop	r15
	pop	rbp
	ret
0000000000402484             66 66 66 2E 0F 1F 84 00 00 00 00 00     fff.........

;; update_tree: 0000000000402490
;;   Called from:
;;     00000000004028CB (in primal_net_simplex)
update_tree proc
	push	rbp
	push	r15
	push	r14
	push	r13
	push	r12
	push	rbx
	mov	rbp,[rsp+58h]
	mov	r12,[rsp+50h]
	mov	rax,[r12+8h]
	test	rbp,rbp
	jns	4024B3h

l00000000004024AE:
	cmp	rax,r9
	jz	4024BDh

l00000000004024B3:
	test	rbp,rbp
	jle	4024C9h

l00000000004024B8:
	cmp	rax,r8
	jnz	4024C9h

l00000000004024BD:
	mov	r11,rbp
	neg	r11
	cmovl	r11,rbp

l00000000004024C7:
	jmp	4024D6h

l00000000004024C9:
	mov	r11,rbp
	neg	r11
	cmovl	r11,rbp

l00000000004024D3:
	neg	r11

l00000000004024D6:
	mov	r13,[rsp+40h]
	mov	rbp,[rsp+38h]
	mov	rax,rbp

l00000000004024E3:
	mov	rbx,rax
	add	[rbx],r11
	mov	rax,[rbx+10h]
	test	rax,rax
	jnz	4024E3h

l00000000004024F2:
	jmp	402504h
00000000004024F4             66 66 66 2E 0F 1F 84 00 00 00 00 00     fff.........

l0000000000402500:
	mov	rbx,[rbx+18h]

l0000000000402504:
	cmp	rbx,rbp
	jz	402514h

l0000000000402509:
	mov	rax,[rbx+20h]
	test	rax,rax
	jz	402500h

l0000000000402512:
	jmp	4024E3h

l0000000000402514:
	mov	r11,[rbp+58h]
	cmp	r8,r13
	jz	4025DDh

l0000000000402521:
	mov	rax,rdx
	neg	rax
	mov	[rsp-8h],rax
	mov	rbx,r11
	mov	r10,r9
	nop	word ptr cs:[rax+rax+0h]

l0000000000402540:
	mov	rax,r8
	mov	r8,[rax+18h]
	mov	r14,[rax+20h]
	test	r14,r14
	jz	402558h

l0000000000402550:
	mov	rbp,[rax+28h]
	mov	[r14+28h],rbp

l0000000000402558:
	mov	rbp,[rax+28h]
	lea	r15,[r8+10h]
	test	rbp,rbp
	lea	rbp,[rbp+20h]
	cmovz	rbp,r15

l000000000040256B:
	mov	[rbp+0h],r14
	mov	[rax+18h],r10
	mov	rbp,[r10+10h]
	mov	[rax+20h],rbp
	test	rbp,rbp
	jz	402584h

l0000000000402580:
	mov	[rbp+28h],rax

l0000000000402584:
	mov	[r10+10h],rax
	mov	qword ptr [rax+28h],+0h
	xor	r15d,r15d
	cmp	dword ptr [rax+8h],0h
	setz	r15b
	cmp	r15,rdi
	mov	rbp,[rsp-8h]
	cmovz	rbp,rdx

l00000000004025A7:
	add	rbp,[rax+50h]
	mov	r14,[rax+30h]
	mov	r10,[rax+58h]
	mov	[rax+8h],esi
	mov	[rax+50h],rcx
	mov	[rax+30h],r12
	mov	[rax+58h],rbx
	mov	rbx,r11
	sub	rbx,r10
	mov	rsi,r15
	mov	rcx,rbp
	mov	r10,rax
	mov	r12,r14
	cmp	r8,r13
	jnz	402540h

l00000000004025DD:
	cmp	rdx,[rsp+60h]
	jle	402663h

l00000000004025E4:
	mov	rbp,[rsp+48h]
	cmp	r13,rbp
	jz	40261Fh

l00000000004025EE:
	mov	rax,rdx
	neg	rax
	nop	word ptr cs:[rax+rax+0h]

l0000000000402600:
	sub	[r13+58h],r11
	movsxd	rcx,dword ptr [r13+8h]
	cmp	rcx,rdi
	mov	rcx,rdx
	cmovz	rcx,rax

l0000000000402612:
	add	[r13+50h],rcx
	mov	r13,[r13+18h]
	cmp	r13,rbp
	jnz	402600h

l000000000040261F:
	cmp	r9,rbp
	jz	40268Dh

l0000000000402624:
	mov	rax,rdx
	neg	rax
	movd	xmm0,r11
	nop

l0000000000402630:
	movsxd	rsi,dword ptr [r9+8h]
	movdqu	xmm1,[r9+50h]
	mov	rcx,rdx
	cmp	rsi,rdi
	jz	402645h

l0000000000402642:
	mov	rcx,rax

l0000000000402645:
	movd	xmm2,rcx
	punpcklqdq	xmm2,xmm0
	paddq	xmm2,xmm1
	movdqu	[r9+50h],xmm2
	mov	r9,[r9+18h]
	cmp	r9,rbp
	jnz	402630h

l0000000000402661:
	jmp	40268Dh

l0000000000402663:
	mov	rax,[rsp+48h]
	jmp	402678h
000000000040266A                               66 0F 1F 44 00 00           f..D..

l0000000000402670:
	sub	[r13+58h],r11
	mov	r13,[r13+18h]

l0000000000402678:
	cmp	r13,rax
	jnz	402670h

l000000000040267D:
	jmp	402688h
000000000040267F                                              90                .

l0000000000402680:
	add	[r9+58h],r11
	mov	r9,[r9+18h]

l0000000000402688:
	cmp	r9,rax
	jnz	402680h

l000000000040268D:
	pop	rbx
	pop	r12
	pop	r13
	pop	r14
	pop	r15
	pop	rbp
	ret
0000000000402698                         0F 1F 84 00 00 00 00 00         ........

;; primal_iminus: 00000000004026A0
;;   Called from:
;;     0000000000402858 (in primal_net_simplex)
primal_iminus proc
	xor	eax,eax
	cmp	rdx,rcx
	jz	40275Ah

l00000000004026AB:
	mov	r9,rdx
	mov	rdx,rcx
	nop	word ptr cs:[rax+rax+0h]

l00000000004026C0:
	mov	rcx,[r9+58h]
	cmp	rcx,[rdx+58h]
	jge	4026E0h

l00000000004026CA:
	cmp	dword ptr [r9+8h],0h
	jz	40271Ah

l00000000004026D1:
	mov	rcx,[r9+50h]
	cmp	[rdi],rcx
	jg	402733h

l00000000004026DA:
	jmp	402740h
00000000004026DC                                     0F 1F 40 00             ..@.

l00000000004026E0:
	cmp	dword ptr [rdx+8h],0h
	jz	40274Fh

l00000000004026E6:
	mov	rcx,[rdx+18h]
	cmp	qword ptr [rcx+18h],0h
	jz	40270Fh

l00000000004026F1:
	mov	r10,[rdx+50h]
	mov	ecx,1h
	sub	rcx,r10
	cmp	[rdi],rcx
	jl	40270Fh

l0000000000402702:
	mov	[rdi],rcx
	mov	qword ptr [rsi],+1h
	mov	rax,rdx

l000000000040270F:
	mov	rdx,[rdx+18h]
	cmp	r9,rdx
	jnz	4026C0h

l0000000000402718:
	jmp	40275Ah

l000000000040271A:
	mov	rcx,[r9+18h]
	cmp	qword ptr [rcx+18h],0h
	jz	402740h

l0000000000402725:
	mov	ecx,1h
	sub	rcx,[r9+50h]
	cmp	[rdi],rcx
	jle	402740h

l0000000000402733:
	mov	[rdi],rcx
	mov	qword ptr [rsi],+0h
	mov	rax,r9

l0000000000402740:
	mov	r9,[r9+18h]
	cmp	r9,rdx
	jnz	4026C0h

l000000000040274D:
	jmp	40275Ah

l000000000040274F:
	mov	rcx,[rdx+50h]
	cmp	[rdi],rcx
	jge	402702h

l0000000000402758:
	jmp	40270Fh

l000000000040275A:
	mov	[r8],rdx
	ret
000000000040275E                                           66 90               f.

;; primal_update_flow: 0000000000402760
;;   Called from:
;;     0000000000402974 (in primal_net_simplex)
primal_update_flow proc
	jmp	402781h
0000000000402762       66 66 66 66 66 2E 0F 1F 84 00 00 00 00 00   fffff.........

l0000000000402770:
	xor	eax,eax
	cmp	dword ptr [rdi+8h],0h
	setz	al
	mov	[rdi+50h],rax
	mov	rdi,[rdi+18h]

l0000000000402781:
	cmp	rdi,rdx
	jnz	402770h

l0000000000402786:
	jmp	4027A1h
0000000000402788                         0F 1F 84 00 00 00 00 00         ........

l0000000000402790:
	xor	eax,eax
	cmp	dword ptr [rsi+8h],0h
	setnz	al
	mov	[rsi+50h],rax
	mov	rsi,[rsi+18h]

l00000000004027A1:
	cmp	rsi,rdx
	jnz	402790h

l00000000004027A6:
	ret
00000000004027A7                      66 0F 1F 84 00 00 00 00 00        f........

;; primal_net_simplex: 00000000004027B0
;;   Called from:
;;     0000000000400A48 (in global_opt)
primal_net_simplex proc
	push	rbp
	push	r15
	push	r14
	push	r13
	push	r12
	push	rbx
	sub	rsp,38h
	mov	r15,rdi
	mov	rdi,[r15+1A8h]
	mov	rsi,[r15+238h]
	mov	r12,[r15+240h]
	lea	rcx,[rsp+8h]
	mov	[rsp+28h],rdi
	mov	[rsp+20h],rsi
	mov	rdx,r12
	jmp	402802h
00000000004027EA                               66 0F 1F 44 00 00           f..D..

l00000000004027F0:
	mov	rdi,[rsp+28h]
	mov	rsi,[rsp+20h]
	mov	rdx,r12
	lea	rcx,[rsp+8h]

l0000000000402802:
	call	primal_bea_mpp
	mov	r13,rax
	test	r13,r13
	jz	40297Eh

l0000000000402813:
	add	qword ptr [r15+258h],1h
	lea	rax,[r13+10h]
	lea	rcx,[r13+8h]
	cmp	qword ptr [rsp+8h],0h
	mov	rdx,rax
	cmovg	rdx,rcx

l0000000000402830:
	cmovg	rcx,rax

l0000000000402834:
	mov	r14,[rcx]
	mov	rbp,[rdx]
	mov	qword ptr [rsp+10h],+1h
	lea	rdi,[rsp+10h]
	lea	rsi,[rsp+30h]
	mov	rdx,r14
	mov	rcx,rbp
	lea	r8,[rsp+18h]
	call	primal_iminus
	test	rax,rax
	jz	402940h

l0000000000402866:
	mov	rcx,[rsp+30h]
	xor	edi,edi
	test	rcx,rcx
	mov	r9,r14
	cmovz	r9,rbp

l0000000000402877:
	setz	dil
	cmovz	rbp,r14

l000000000040287F:
	mov	r14,[rax+30h]
	movsxd	rdx,dword ptr [rax+8h]
	xor	ebx,ebx
	cmp	rcx,rdx
	setz	bl
	add	ebx,1h
	mov	r10,[rsp+8h]
	mov	rdx,[rsp+10h]
	mov	ecx,1h
	sub	rcx,rdx
	test	r10,r10
	cmovle	rcx,rdx

l00000000004028AB:
	xor	esi,esi
	cmp	[r13+8h],rbp
	setz	sil
	mov	r8,rbp
	push	qword ptr [r15+200h]
	push	r10
	push	r13
	push	qword ptr [rsp+30h]
	push	qword ptr [rax+18h]
	push	rax
	call	update_tree
	add	rsp,30h
	mov	dword ptr [r13+18h],0h
	mov	[r14+18h],ebx
	mov	rsi,[r15+258h]
	lea	rcx,[rsi-1h]
	mov	rax,rcx
	mov	rdx,0A3D70A3D70A3D70Bh
	imul	rdx
	lea	rax,[rdx+rsi]
	add	rax,0FFh
	mov	rdx,rax
	shr	rdx,3Fh
	sar	rax,7h
	add	rax,rdx
	imul	rax,rax,+0C8h
	cmp	rcx,rax
	jnz	4027F0h

l0000000000402921:
	mov	rdi,r15
	call	refresh_potential
	add	[r15+268h],rax
	jmp	4027F0h
0000000000402935                66 66 2E 0F 1F 84 00 00 00 00 00      ff.........

l0000000000402940:
	add	qword ptr [r15+260h],1h
	xor	eax,eax
	cmp	dword ptr [r13+18h],2h
	setz	al
	mov	ecx,2h
	sub	ecx,eax
	mov	[r13+18h],ecx
	cmp	qword ptr [rsp+10h],0h
	jz	4027F0h

l0000000000402969:
	mov	rdx,[rsp+18h]
	mov	rdi,r14
	mov	rsi,rbp
	call	primal_update_flow
	jmp	4027F0h

l000000000040297E:
	mov	rdi,r15
	call	refresh_potential
	add	[r15+268h],rax
	mov	rdi,r15
	call	primal_feasible
	mov	rdi,r15
	call	dual_feasible
	xor	eax,eax
	add	rsp,38h
	pop	rbx
	pop	r12
	pop	r13
	pop	r14
	pop	r15
	pop	rbp
	ret
00000000004029AE                                           66 90               f.

;; bea_is_dual_infeasible: 00000000004029B0
bea_is_dual_infeasible proc
	xor	eax,eax
	test	rsi,rsi
	js	4029C4h

l00000000004029B7:
	test	rsi,rsi
	jz	4029C3h

l00000000004029BC:
	cmp	dword ptr [rdi+18h],2h
	setz	al

l00000000004029C3:
	ret

l00000000004029C4:
	cmp	dword ptr [rdi+18h],1h
	setz	al
	ret
00000000004029CC                                     0F 1F 40 00             ..@.

;; sort_basket: 00000000004029D0
;;   Called from:
;;     0000000000402AA5 (in sort_basket)
;;     0000000000402D9E (in primal_bea_mpp)
sort_basket proc
	push	r15
	push	r14
	push	r12
	push	rbx
	push	rax
	mov	r15,rsi
	mov	r14,3FFFFFFFFFFFFFFEh
	nop	word ptr cs:[rax+rax+0h]

l00000000004029F0:
	lea	rax,[rdi+r15]
	mov	rcx,rax
	shr	rcx,3Fh
	add	rcx,rax
	and	rcx,r14
	mov	rax,[4050B0h+rcx*4]
	mov	r9,[rax+10h]
	mov	r8,r15
	mov	rax,rdi
	nop	word ptr cs:[rax+rax+0h]

l0000000000402A20:
	add	rax,0FFh
	mov	r10,rax
	nop	word ptr [rax+rax+0h]

l0000000000402A30:
	mov	rax,r10
	mov	rdx,[4050B8h+rax*8]
	lea	r10,[rax+1h]
	cmp	[rdx+10h],r9
	jg	402A30h

l0000000000402A45:
	add	r8,1h
	mov	rsi,r8
	nop	dword ptr [rax+0h]

l0000000000402A50:
	mov	rcx,rsi
	mov	rbx,[4050A8h+rcx*8]
	lea	rsi,[rcx-1h]
	cmp	r9,[rbx+10h]
	jg	402A50h

l0000000000402A65:
	cmp	r10,rsi
	jge	402A7Ah

l0000000000402A6A:
	mov	[4050B8h+rax*8],rbx
	mov	[4050A8h+rcx*8],rdx

l0000000000402A7A:
	xor	eax,eax
	cmp	r10,rsi
	setle	al
	mov	r8,rsi
	sub	r8,rax
	add	rax,r10
	cmp	rax,r8
	jle	402A20h

l0000000000402A90:
	xor	r12d,r12d
	cmp	r10,rsi
	setle	r12b
	sub	rsi,r12
	add	r12,r10
	cmp	rsi,rdi
	jle	402AAAh

l0000000000402AA5:
	call	sort_basket

l0000000000402AAA:
	cmp	r12,r15
	jge	402ABCh

l0000000000402AAF:
	mov	rdi,r12
	cmp	r12,33h
	jl	4029F0h

l0000000000402ABC:
	add	rsp,8h
	pop	rbx
	pop	r12
	pop	r14
	pop	r15
	ret
0000000000402AC8                         0F 1F 84 00 00 00 00 00         ........

;; primal_bea_mpp: 0000000000402AD0
;;   Called from:
;;     0000000000402802 (in primal_net_simplex)
primal_bea_mpp proc
	push	rbp
	push	r15
	push	r14
	push	r12
	push	rbx
	mov	r14,rcx
	mov	r11,rdx
	mov	al,[0000000000405BA8]                                  ; [rip+000030C4]
	test	al,al
	jz	402B01h

l0000000000402AE8:
	mov	rdx,[0000000000407CA8]                                 ; [rip+000051B9]
	cmp	rdx,2h
	jge	402C54h

l0000000000402AF9:
	xor	r15d,r15d
	jmp	402CC8h

l0000000000402B01:
	movdqa	xmm5,[0000000000403160]                             ; [rip+00000657]
	mov	rax,-0AE0h
	movdqa	xmm1,[0000000000403170]                             ; [rip+00000658]
	mov	ecx,405BB0h
	movd	xmm2,rcx
	pshufd	xmm2,xmm2,44h
	movdqa	xmm8,[0000000000403180]                             ; [rip+00000650]
	movdqa	xmm9,[0000000000403190]                             ; [rip+00000657]
	movdqa	xmm10,[00000000004031A0]                            ; [rip+0000065E]
	movdqa	xmm11,[00000000004031B0]                            ; [rip+00000665]
	movdqa	xmm7,[00000000004031C0]                             ; [rip+0000066D]
	movdqa	xmm3,[00000000004031D0]                             ; [rip+00000675]
	nop	dword ptr [rax+rax+0h]

l0000000000402B60:
	movdqa	xmm0,xmm5
	pmuludq	xmm0,xmm1
	paddq	xmm0,xmm2
	movdqa	xmm4,xmm5
	psrlq	xmm4,20h
	pmuludq	xmm4,xmm1
	psllq	xmm4,20h
	paddq	xmm4,xmm0
	movdqa	xmm0,xmm4
	paddq	xmm0,xmm8
	movdqu	[rax+405B98h],xmm4
	movdqu	[rax+405BA8h],xmm0
	movdqa	xmm0,xmm4
	paddq	xmm0,xmm9
	movdqa	xmm6,xmm4
	paddq	xmm6,xmm10
	movdqu	[rax+405BB8h],xmm0
	movdqu	[rax+405BC8h],xmm6
	movdqa	xmm0,xmm4
	paddq	xmm0,xmm11
	paddq	xmm4,xmm7
	movdqu	[rax+405BD8h],xmm0
	movdqu	[rax+405BE8h],xmm4
	paddq	xmm5,xmm3
	add	rax,60h
	jnz	402B60h

l0000000000402BE8:
	mov	[0000000000405B98],+407C68h                            ; [rip+00002FA5]
	add	rdi,0FFh
	mov	rcx,6D3A06D3A06D3A07h
	mov	rax,rdi
	imul	rcx
	mov	rax,rdx
	shr	rax,3Fh
	sar	rdx,7h
	lea	r9,[rdx+rax]
	add	r9,1h
	mov	[0000000000407C98],r9                                  ; [rip+00005077]
	mov	[0000000000405BA0],+407C80h                            ; [rip+00002F74]
	mov	[0000000000405BA8],1h                                  ; [rip+00002F75]
	mov	[0000000000407CA0],+0h                                 ; [rip+00005062]
	mov	[0000000000407CA8],+0h                                 ; [rip+0000505F]
	xor	r15d,r15d
	xor	r10d,r10d
	jmp	402CDDh

l0000000000402C54:
	mov	edi,2h
	xor	r15d,r15d
	nop	dword ptr [rax+0h]

l0000000000402C60:
	mov	rcx,[4050B0h+rdi*8]
	mov	rcx,[rcx]
	mov	rbx,[rcx]
	mov	rbp,[rcx+8h]
	sub	rbx,[rbp+0h]
	mov	rbp,[rcx+10h]
	add	rbx,[rbp+0h]
	js	402CC0h

l0000000000402C80:
	test	rbx,rbx
	jz	402CADh

l0000000000402C85:
	cmp	dword ptr [rcx+18h],2h
	jnz	402CADh

l0000000000402C8B:
	mov	rbp,[4050B8h+r15*8]
	mov	[rbp+0h],rcx
	add	r15,1h
	mov	[rbp+8h],rbx
	mov	rcx,rbx
	neg	rcx
	cmovl	rcx,rbx

l0000000000402CA9:
	mov	[rbp+10h],rcx

l0000000000402CAD:
	cmp	rdi,31h
	ja	402CC8h

l0000000000402CB3:
	cmp	rdi,rdx
	lea	rdi,[rdi+1h]
	jl	402C60h

l0000000000402CBC:
	jmp	402CC8h
0000000000402CBE                                           66 90               f.

l0000000000402CC0:
	cmp	dword ptr [rcx+18h],1h
	jz	402C8Bh

l0000000000402CC6:
	jmp	402CADh

l0000000000402CC8:
	mov	[0000000000407CA8],r15                                 ; [rip+00004FD9]
	mov	r10,[0000000000407CA0]                                 ; [rip+00004FCA]
	mov	r9,[0000000000407C98]                                  ; [rip+00004FBB]

l0000000000402CDD:
	mov	rdx,r9
	shl	rdx,6h
	xor	r8d,r8d
	mov	r12,r10
	nop	word ptr [rax+rax+0h]

l0000000000402CF0:
	mov	rbx,r12
	shl	rbx,6h
	add	rbx,rsi
	cmp	rbx,r11
	jc	402D18h

l0000000000402CFF:
	jmp	402D70h
0000000000402D01    66 66 66 66 66 66 2E 0F 1F 84 00 00 00 00 00  ffffff.........

l0000000000402D10:
	add	rbx,rdx
	cmp	rbx,r11
	jnc	402D70h

l0000000000402D18:
	mov	ebp,[rbx+18h]
	test	ebp,ebp
	jle	402D10h

l0000000000402D1F:
	mov	rdi,[rbx]
	mov	rax,[rbx+8h]
	sub	rdi,[rax]
	mov	rax,[rbx+10h]
	add	rdi,[rax]
	js	402D40h

l0000000000402D32:
	test	rdi,rdi
	jz	402D10h

l0000000000402D37:
	cmp	ebp,2h
	jz	402D45h

l0000000000402D3C:
	jmp	402D10h
0000000000402D3E                                           66 90               f.

l0000000000402D40:
	cmp	ebp,1h
	jnz	402D10h

l0000000000402D45:
	mov	rax,[4050B8h+r15*8]
	lea	r15,[r15+1h]
	mov	[0000000000407CA8],r15                                 ; [rip+00004F50]
	mov	[rax],rbx
	mov	[rax+8h],rdi
	mov	rcx,rdi
	neg	rcx
	cmovl	rcx,rdi

l0000000000402D69:
	mov	[rax+10h],rcx
	jmp	402D10h
0000000000402D6F                                              90                .

l0000000000402D70:
	add	r12,1h
	cmp	r12,r9
	cmovz	r12,r8

l0000000000402D7B:
	cmp	r15,31h
	jg	402D8Ah

l0000000000402D81:
	cmp	r12,r10
	jnz	402CF0h

l0000000000402D8A:
	mov	[0000000000407CA0],r12                                 ; [rip+00004F0F]
	test	r15,r15
	jz	402DB6h

l0000000000402D96:
	mov	edi,1h
	mov	rsi,r15
	call	sort_basket
	mov	rax,[00000000004050B8]                                 ; [rip+0000230E]
	mov	rcx,[rax+8h]
	mov	[r14],rcx
	mov	rax,[rax]
	jmp	402DC6h

l0000000000402DB6:
	mov	[0000000000405BA8],0h                                  ; [rip+00002DEB]
	mov	qword ptr [r14],+0h
	xor	eax,eax

l0000000000402DC6:
	pop	rbx
	pop	r12
	pop	r14
	pop	r15
	pop	rbp
	ret
0000000000402DCF                                              90                .

;; __libc_csu_init: 0000000000402DD0
__libc_csu_init proc
	push	r15
	push	r14
	mov	r15,rdx
	push	r13
	push	r12
	lea	r12,[0000000000404DF0]                                 ; [rip+0000200E]
	push	rbp
	lea	rbp,[0000000000404DF8]                                 ; [rip+0000200E]
	push	rbx
	mov	r13d,edi
	mov	r14,rsi
	sub	rbp,r12
	sub	rsp,8h
	sar	rbp,3h
	call	_init
	test	rbp,rbp
	jz	402E26h

l0000000000402E06:
	xor	ebx,ebx
	nop	dword ptr [rax+rax+0h]

l0000000000402E10:
	mov	rdx,r15
	mov	rsi,r14
	mov	edi,r13d
	call	qword ptr [r12+rbx*8]
	add	rbx,1h
	cmp	rbp,rbx
	jnz	402E10h

l0000000000402E26:
	add	rsp,8h
	pop	rbx
	pop	rbp
	pop	r12
	pop	r13
	pop	r14
	pop	r15
	ret
0000000000402E35                90 66 2E 0F 1F 84 00 00 00 00 00      .f.........

;; __libc_csu_fini: 0000000000402E40
__libc_csu_fini proc
	ret
