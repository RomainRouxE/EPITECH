[BITS 64]

	SECTION .text

	GLOBAL  memset:function

memset:
	PUSH RBP
	MOV RBP, RSP
	XOR RCX, RCX
	XOR RAX, RAX
loop:
	CMP RCX, RDX
	JE retu
	MOV BYTE[RDI + RCX], SIL
	INC RCX
	JMP loop

retu:
	MOV RAX, RDI
	LEAVE
	RET
