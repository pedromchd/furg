; 3. Dado um número inteiro positivo n, imprimir os n primeiros naturais ímpares.

%include "io.inc"

section .text
global CMAIN
CMAIN:
    mov ebp, esp

    GET_UDEC 4, ecx     ; Lê a entrada no contador
    mov eax, 1          ; Inicializa o acumulador em 1 (primeiro ímpar)

    call print_odds     ; Escreve os n primeiros ímpares naturais

    xor eax, eax
    ret

print_odds:
    PRINT_UDEC 4, eax   ; Escreve o atual número ímpar

    dec ecx
    cmp ecx, 0          ; Encerra o loop se não há mais ímpares
    je .end

    PRINT_CHAR ' '      ; Adiciona separador para o próximo ímpar

    add eax, 2          ; Pega o próximo ímpar e repete
    jmp print_odds

    .end:
        ret
