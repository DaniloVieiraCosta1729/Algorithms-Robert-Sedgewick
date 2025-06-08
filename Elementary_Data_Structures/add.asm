.intel_syntax noprefix

.section data

.section .text

.globl soma

soma:
    push ebp
    mov ebp, esp
    mov eax, [ebp + 8]
    add eax, [ebp + 12]
    pop ebp
    ret

