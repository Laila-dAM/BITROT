global _start
section .text
_start:
mov rax, 5
push rax
mov rax, [rsp + 0]
mov rax, 60
xor rdi, rdi
syscall
