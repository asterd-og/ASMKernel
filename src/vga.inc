%ifndef vga
%define vga

printChar:
	push bp
	mov bp, sp

	mov ah, 09h ; To get colors
	mov cx, 1
	int 10h
	
	mov ah, 03h
	mov bh, 0
	int 10h
	
	add dl, 1
	mov ah, 02h
	mov bh, 0
	int 10h
	
	mov sp, bp
	pop bp
	ret

print:
	push bp
	mov bp, sp
	
	mov si, word [bp + 4]
.loop:
	lodsb
	cmp al, 0
	je .exit
	cmp al, 13
	je .ret
	cmp al, 10
	je .nl
	cmp al, 08
	je .backspace
	call printChar
	jmp .loop
.backspace:
	mov ah, 03h
	mov bh, 0
	int 10h
	
	dec dl
	mov ah, 02h
	mov bh, 0
	int 10h
	
	mov al, ' '
	mov ah, 09h
	mov cx, 1
	int 10h
	
	jmp .loop
.ret:
	mov ah, 03h
	mov bh, 0
	int 10h

	mov ah, 02h
	mov dl, 0
	mov bh, 0
	int 10h
	
	jmp .loop
.nl:
	mov ah, 03h
	mov bh, 0
	int 10h
	
	add dh, 1
	mov ah, 02h
	mov bh, 0
	int 10h
	
	jmp .loop
.exit:
	mov sp, bp
	pop bp
	ret

clear:
    mov ax, 3
	int 10h
	ret

%endif