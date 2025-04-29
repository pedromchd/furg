; 2. Dado um inteiro positivo n, verificar se n é primo.

%include "io.inc"

section .text
global CMAIN
CMAIN:
    mov ebp, esp

    mov ebx, [num]      ; Lê a entrada para ebx
    mov ecx, 2          ; Inicializa o contador em 2

    mov al, 1           ; Inicializa "é primo" como 1 (true)
    call isPrime        ; Verifica se o número é primo

    cmp al, 1
    je .prime

    xor eax, eax
    ret

.prime:
    PRINT_STRING "Prime"
    ret

isPrime:
    cmp ecx, ebx        ; Executa o loop no intervalo 2..n-1
    jge .end

    mov edx, 0          ; Iniciliza registrador que guarda o mod
    mov eax, ebx        ; Atribui o acumulador o valor do número
    
    div ecx             ; Faz a divisão entre o número e o contador
    cmp edx, 0          ; Compara se foi uma divisão inteira ou não
    je .not             ; Encerra se for divisão inteira => não é primo

    inc ecx             ; Incrementa o contador e continua o loop
    jmp isPrime

    .not:
        PRINT_STRING "Not prime"
        mov al, 0       ; Define o "é primo" como 0 (false)

    .end:
        ret

section .data
num dd 11
