#include <stdio.h>
#include <string.h>

int kmpAlgorithm(char *text, char *word);
void kmpTable(char *word, int wlen, int *table);

int main(void)
{
    char text[255], word[255];

    printf("Digite o texto: ");
    gets(text);

    printf("Digite a palavra: ");
    gets(word);

    int res = kmpAlgorithm(text, word);

    printf("Temos que a palavra %s ocorre %d vez(es) na frase.\n", word, res);

    return 0;
}

int kmpAlgorithm(char *text, char *word)
{
    int tlen = strlen(text);
    int wlen = strlen(word);

    int ti = 0;
    int wi = 0;

    int res = 0;

    int table[wlen];
    kmpTable(word, wlen, table);

    while (ti < tlen)
    {
        if (word[wi] == text[ti])
        {
            ti++;
            wi++;
        }

        if (wi == wlen)
        {
            res++;
            wi = table[wi - 1];
        }
        else if (ti < tlen && word[wi] != text[ti])
        {
            if (wi != 0)
            {
                wi = table[wi - 1];
            }
            else
            {
                ti++;
            }
        }
    }

    return res;
}

void kmpTable(char *word, int wlen, int *table)
{
    int len = 0;
    table[0] = 0;

    int i = 1;
    while (i < wlen)
    {
        if (word[i] == word[len])
        {
            len++;
            table[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = table[len - 1];
            }
            else
            {
                table[i] = 0;
                i++;
            }
        }
    }
}
