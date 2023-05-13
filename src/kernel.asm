[org 7e00h]
[bits 16]

start:
	push bp
	mov bp, sp

	call clear

	mov bh, 0
	mov bl, 0fh
	push welcome
	call print
	
	call shellStart
	
	jmp $
	
	mov sp, bp
	pop bp
	ret

welcome db "Welcome to my tiny OS!", 13, 10, 10, 0

%include "src/vga.inc"
%include "src/shell.inc"

times (2048-($-$$)) db 0