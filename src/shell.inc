%ifndef shell
%define shell

shellStart:
	push bp
	mov bp, sp

	push shellMsg
	mov bh, 0
	mov bl, 0fh
	call print
.loop:
	push input
	mov bh, 0
	mov bl, 0eh
	call print
	
	mov bh, 0
	mov bl, 0fh
	push buffer
	call kbReadLine
	
	push buffer
	call print
	
	push nl
	call print
	
	mov word [buffer], 0
	jmp .loop
.exit:
	mov sp, bp
	pop bp
	ret

input db "sh> "
buffer resb 64
shellMsg db "Tiny OS Shell.", 13, 10, 10, 0
nl db 13, 10, 0

%include "src/vga.inc"
%include "src/keyboard.inc"

%endif