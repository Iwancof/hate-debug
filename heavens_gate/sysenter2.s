.intel_syntax noprefix
.globl assembly_write

.type assembly_write, @function

assembly_write:
  mov eax, 4
  mov ebx, 1
  mov rcx, rdi
  mov edx, 10

  int 0x80
  ret


.section .note.GNU-stack,"",%progbits
