/*
ALGORITMO MULTIPLICA()
    string  OP1_STR, OP2_STR;
    int     OP1[4], OP2[4], R[8], AUX_MULT, AUX_DIV, AUX_SOMA, R_AUX[5];

    ESCREVA("informe o 1o operador: ")
    LEIA(OP1_STR);
    ESCREVA("informe o 2o operador: ")
    LEIA(OP2_STR);

    PARA i = 1 ATÉ 4 FAÇA
        OP1[i] = int(OP1_STR[i]);
        OP2[i] = int(OP2_STR[i]);
    FIM PARA;

    PARA i = 1 ATÉ 8 FAÇA
        R[i] = 0;
    FIM PARA;

    PARA i = 4 ATÉ 1 FAÇA
        AUX_DIV = 0;
        PAR j = 4 ATÉ 1 FAÇA
            AUX_MULT = OP1[j] * OP2[i] + AUX_DIV;
            R_AUX[j + 1] = AUX_MULT mod 10;
            AUX_DIV = AUX_MULT div 10;
        FIM PARA;
        R_AUX[1] = AUX_DIV;
        
        AUX_DIV = 0;
        PARA j = 4 ATÉ 0 FAÇA
            AUX_SOMA = R_AUX[j + 1] + R[i + j] + AUX_DIV;
            R[i + j] = AUX_SOMA  div 10;
            AUX_DIV = AUX_SOMA mod 10;
        FIM PARA
    FIM PARA;

    MOSTRE(R);
FIM ALGORITMO;
*/

/*
MULTIPLICA(op1-str, op2-str)
    let OP1[1..4], OP2[1..4], R[1..8], R-AUX[1..5] be new arrays
    for i = 1 to 4
        OP1[i] = INT(op1-str[i])
        OP2[i] = INT(op2-str[i])
    for i = 1 to 8
        R[i] = 0
    for i = 4 downto 1
        aux-div = 0
        for j = 4 downto 1
            aux-mult = OP1[j] * OP2[i] + aux-div
            R-AUX[j + 1] = aux-mult mod 10
            aux-div = INT(aux-mult / 10)
        R-AUX[1] = aux-div
        aux-div = 0
        for j = 5 downto 1
            aux-soma = R-AUX[j] + R[i + j - 1] + aux-div
            R[i + j - 1] = aux-soma mod 10
            aux-div = INT(aux-soma / 10)
        R[i - 1] = aux-div
    return R
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("usage: mult operator1 operator2\n");
        return 1;
    }

    int *op1 = (int *)calloc(4, sizeof(int));
    int *op2 = (int *)calloc(4, sizeof(int));
    int *aux = (int *)calloc(5, sizeof(int));
    int *res = (int *)calloc(8, sizeof(int));

    for (int i = 0; i < 4; i++)
    {
        op1[i] = argv[1][i] - '0';
        op2[i] = argv[2][i] - '0';
    }

    int mcarry, scarry;
    for (int i = 3; i >= 0; i--)
    {
        mcarry = 0;
        for (int j = 3; j >= 0; j--)
        {
            int mult = op1[j] * op2[i] + mcarry;
            aux[j + 1] = mult % 10;
            mcarry = (int)mult / 10;
        }
        aux[0] = mcarry;

        scarry = 0;
        for (int j = 4; j >= 0; j--)
        {
            int sum = aux[j] + res[i + j] + scarry;
            res[i + j] = sum % 10;
            scarry = (int)sum / 10;
        }
        res[i - 1] = scarry;
    }

    for (int i = 0; i < 8; i++)
    {
        printf("%d", res[i]);
    }
    printf("\n");

    return 0;
}
