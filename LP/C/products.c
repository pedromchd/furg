#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[30];
    int codigo;
    double preco;
} Produto;

typedef struct node
{
    Produto* produto;
    struct node* next;
} Node;

Produto* criarProduto(char* nome, int codigo, double preco);

void exibirLista(Node* lista);

Produto* buscarProduto(Node* lista, char* nome);

int main(void)
{
    Node* lista = NULL;
    int i;

    do
    {
        do
        {
            printf("Selecione uma opção:\n");
            printf("(1) Adicionar produto\n");
            printf("(2) Exibir lista de produtos\n");
            printf("(3) Buscar produto por nome\n");
            printf("(4) Sair\n");
            printf("Opção: ");
            scanf("%i", &i);
            getchar();
        } while (i < 1 || i > 4);

        switch (i)
        {
            case 1:
            {
                char nome[30];
                int codigo;
                double preco;

                printf("Digite o nome do produto: ");
                fgets(nome, sizeof(nome), stdin);

                printf("Digite o código do produto: ");
                scanf("%d", &codigo);
                getchar();

                printf("Digite o preço do produto: ");
                scanf("%lf", &preco);
                getchar();

                Produto* produto = criarProduto(nome, codigo, preco);

                Node* novo = (Node*)malloc(sizeof(Node));

                if (novo == NULL)
                {
                    printf("Erro ao alocar memória para o produto.\n");
                    exit(1);
                }

                novo->produto = produto;
                novo->next = lista;
                lista = novo;

                printf("Produto adicionado com sucesso!\n");
                break;
            }

            case 2:
            {
                if (lista == NULL)
                {
                    printf("Lista vazia!\n");
                }
                else
                {
                    exibirLista(lista);
                }
                break;
            }

            case 3:
            {
                char nome[30];

                printf("Digite o nome do produto: ");
                fgets(nome, sizeof(nome), stdin);

                Produto* encontrado = buscarProduto(lista, nome);

                if (encontrado != NULL)
                {
                    printf("Produto encontrado!\n");
                    printf("Nome: %s\n", encontrado->nome);
                    printf("Código: %d\n", encontrado->codigo);
                    printf("Preço: %.2f\n", encontrado->preco);
                }
                else
                {
                    printf("Produto não encontrado!\n");
                }
                break;
            }

            case 4:
            {
                Node* atual = lista;

                while (atual != NULL)
                {
                    Node* temp = atual;
                    atual = atual->next;
                    free(temp->produto);
                    free(temp);
                }

                free(lista);
                lista = NULL;

                break;
            }
        }

        printf("\n");
    } while (i != 4);

    return 0;
}

Produto* criarProduto(char* nome, int codigo, double preco)
{
    Produto* produto = (Produto*)malloc(sizeof(Produto));

    if (produto == NULL)
    {
        printf("Erro ao alocar memória para o produto.\n");
        exit(1);
    }

    strcpy(produto->nome, nome);
    produto->codigo = codigo;
    produto->preco = preco;

    return produto;
}

void exibirLista(Node* lista)
{
    Node* atual = lista;

    printf("--------------------------\n");
    while (atual != NULL)
    {
        printf("Nome: %s\n", atual->produto->nome);
        printf("Código: %d\n", atual->produto->codigo);
        printf("Preço: %.2f\n", atual->produto->preco);
        printf("--------------------------\n");
        atual = atual->next;
    }
}

Produto* buscarProduto(Node* lista, char* nome)
{
    Node* atual = lista;

    while (atual != NULL)
    {
        if (strcmp(atual->produto->nome, nome) == 0)
        {
            return atual->produto;
        }
        atual = atual->next;
    }

    return NULL;
}
