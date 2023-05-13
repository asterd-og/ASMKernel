%ifndef keyboard
%define keyboard

kbReadChar:
	mov ah, 0
	int 16h
	ret

kbReadLine:
	push bp
	mov bp, sp
	
	mov di, word [bp + 4]
	mov si, [counter]
	mov word [si], 0
.loop:
	mov si, [counter]
	call kbReadChar
	cmp ah, 0eh
	je .backspace
	cmp ah, 1ch
	je .enter
	call printChar
	stosb			; Store AL to DI (:B)
	inc word [si]
	jmp .loop
.backspace:
	cmp word [si], 0
	jle .loop
	
	dec word [si]
	
	push bsChar
	call print

	dec di
	mov al, ''
	stosb
	dec di
	jmp .loop
.enter:
	push nl
	call print

	mov al, 0
	stosb
	
	mov sp, bp
	pop bp
	ret
	
bsChar db 08, 00
counter resb 1

%include "src/vga.inc"

%endif