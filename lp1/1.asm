; 1. Dado um inteiro x, determine x!.

%include "io.inc"

section .text
global CMAIN
CMAIN:
    mov eax, [num]      ; Atribui o valor de num a eax
    call fatorial       ; Chama a função fatorial
    PRINT_UDEC 4, [num] ; Mostra o resultado

    xor eax, eax
    ret

fatorial:               ; f(n) = n * f(n-1), f(1) = 1
    cmp eax, 1          ; Verifica o caso base n = 1
    jle .end            ; Termina a recursão

    dec eax             ; Decrementa eax, o passo/step

    mov ebx, eax        ; Guarda o valor de eax em ebx
    xchg eax, [num]     ; Troca o valor de eax com o de num
    mul ebx             ; Multiplica eax por ebx e guarda em eax
    xchg eax, [num]     ; Troca o resultado com o num que guarda o passo
    
    call fatorial       ; Continu a recursão

    xor ebx, ebx
    ret

.end:
    ret

section .data
num dd 5
