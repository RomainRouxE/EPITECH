[BITS 64]
	global rindex
	section .text

rindex:
	mov rcx, 0
	mov rax, 0

loop:
	movzx rdx, byte [rdi+rcx]
	cmp rdx, rsi
	je found
resume:
	cmp rdx, 0
	je return
	inc rcx
	jmp loop
	
found:
	mov rax, rdi
	add rax, rcx
	jmp resume

return:
	ret
