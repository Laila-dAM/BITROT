[org 0x7c00]
bits 16

KERNEL_OFFSET equ 0x1000
KERNEL_SECTORS equ 32

start:
    cli
    xor ax, ax
    mov ds, ax
    mov es, ax
    mov ss, ax
    mov sp, 0x7c00

    mov [BOOT_DRIVE], dl

    mov bx, KERNEL_OFFSET
    mov dh, KERNEL_SECTORS
    mov dl, [BOOT_DRIVE]
    call load_kernel

    call switch_to_protected_mode

hang:
    jmp hang

load_kernel:
    pusha
    mov ah, 0x02
    mov al, dh
    mov ch, 0x00
    mov cl, 0x02
    mov dh, 0x00
    int 0x13
    jc disk_error
    popa
    ret

disk_error:
    jmp $

gdt_start:
    dq 0x0000000000000000
    dq 0x00cf9a000000ffff
    dq 0x00cf92000000ffff
gdt_end:

gdt_descriptor:
    dw gdt_end - gdt_start - 1
    dd gdt_start

switch_to_protected_mode:
    cli
    lgdt [gdt_descriptor]
    mov eax, cr0
    or eax, 1
    mov cr0, eax
    jmp 0x08:protected_mode_entry

bits 32

protected_mode_entry:
    mov ax, 0x10
    mov ds, ax
    mov ss, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov esp, 0x90000
    call KERNEL_OFFSET
    jmp $

BOOT_DRIVE db 0

times 510-($-$$) db 0
dw 0xaa55
