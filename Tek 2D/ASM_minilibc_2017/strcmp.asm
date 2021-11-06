[BITS 64]
	global strcmp

	section .text

strcmp:
	push rbp
	mov rbp, rsp


loop:
	xor r8, r8
	xor r9, r9
	mov r8B, [rdi]
	mov r9B, [rsi]
	cmp r8B, r9B
	jne end
	cmp r8B, 0
	je end
	inc rdi
	inc rsi
	jmp loop

end:
	sub r8, r9
	mov rax, r8

	mov rsp, rbp 
	pop rbp
	ret
