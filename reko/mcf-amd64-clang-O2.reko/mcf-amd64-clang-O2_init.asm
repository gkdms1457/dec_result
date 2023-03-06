;;; Segment .init (0000000000400810)

;; _init: 0000000000400810
;;   Called from:
;;     0000000000402DFC (in __libc_csu_init)
_init proc
	sub	rsp,8h
	mov	rax,[0000000000404FE0]                                 ; [rip+000047C5]
	test	rax,rax
	jz	400822h

l0000000000400820:
	call	rax

l0000000000400822:
	add	rsp,8h
	ret
