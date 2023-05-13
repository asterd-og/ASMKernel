[org 7c00h]
[bits 16]

mov ah, 02h
mov al, 2
mov ch, 0
mov cl, 2
mov dh, 0
mov dl, 80h
mov bx, 7e00h
int 13h
jmp 7e00h

times (510-($-$$)) db 0
dw 0xaa55