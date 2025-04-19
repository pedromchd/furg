; 1. Dado um inteiro x, determine x!.

%include "io.inc"

section .text
global CMAIN
CMAIN:
    push ebp
    mov ebp, esp

    mov ecx, [num]  ; Inicializa o contador com valor de num
    mov eax, 1      ; Inicializa o acumulador como 1

    call fatorial   ; Calcula o fatorial
    mov [res], eax  ; Atribui no resultado o cálculo

    PRINT_UDEC 4, [res]

    mov esp, ebp
    pop ebp

    xor eax, eax
    ret

fatorial:
    cmp ecx, 1      ; Encerra o loop se num <= 1
    jle .end

    mul ecx         ; Multiplica o acumulador pelo contador
    dec ecx         ; Decrementa o contador

    jmp fatorial    ; Continua o loop do fatorial

.end:
    ret

section .data
num dd 5
res dd 0
