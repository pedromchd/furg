; 1. Dado um inteiro x, determine x!.

%include "io.inc"

section .text
global CMAIN
CMAIN:
    mov ebp, esp

    mov ecx, [num]      ; Lê um inteiro e armazena no contador
    mov eax, 1          ; Inicializa o acumulador como 1

    call fatorial       ; Calcula o fatorial no acumulador

    PRINT_UDEC 4, eax   ; Imprime o resultado

    xor eax, eax
    ret

fatorial:
    cmp ecx, 1          ; Encerra o loop se o contador <= 1
    jle .end

    mul ecx             ; Multiplica o acumulador pelo contador
    dec ecx             ; Decrementa o contador

    jmp fatorial        ; Continua o loop do fatorial

.end:
    ret

section .data
num dd 5
