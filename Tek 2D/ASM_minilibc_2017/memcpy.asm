[BITS 64]
	SECTION .text
	global memcpy:function

memcpy:
	push rcx
	push rbx
	xor rcx, rcx
	mov rax, rdi

.memsetter:
	cmp rcx, rdx
	je .memret
	mov bl, byte [rsi+rcx]
	mov byte [rax+rcx], bl
	inc rcx
	jmp .memsetter

.memret:
	pop rbx
	pop rcx
	ret
