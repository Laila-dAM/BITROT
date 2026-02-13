# Bootloader

This bootloader is written in x86 Assembly using NASM.

It is a 16-bit BIOS boot sector that:

- Is loaded by the BIOS at memory address 0x7C00
- Loads the kernel from disk into memory at 0x1000
- Sets up a Global Descriptor Table
- Switches the CPU to 32-bit protected mode
- Transfers control to the kernel entry point

## Architecture

Execution flow:

1. BIOS loads the first 512 bytes from disk into 0x7C00.
2. The bootloader stores the boot drive number.
3. It reads multiple sectors from disk starting at sector 2.
4. The kernel is loaded at physical address 0x1000.
5. A minimal GDT is configured.
6. Protected mode is enabled.
7. Execution jumps to the kernel.

The bootloader ends with the signature 0xAA55 and must be exactly 512 bytes.

## Build

From the project root:

```bash
nasm -f bin bootloader/boot.asm -o bootloader/boot.bin
```

## Requirements

- NASM
- x86 BIOS-compatible environment
- QEMU or similar emulator for testing

## Testing Boot Sector

1. To verify the size:

```bash
stat -c%s bootloader/boot.bin
```

2. The output must be:

```bash
512
```

3. To verify the boot signature:

```bash
hexdump -C bootloader/boot.bin | tail
```

4. The last two bytes must be:

```bash
55 aa
```

## Integration with Kernel

### The kernel must:
- Be linked to load at 0x1000
- Provide a C entry function named kernel_main
- Be built as a freestanding 32-bit binary

### The final disk image must concatenate:

- boot.bin
- kernel.bin