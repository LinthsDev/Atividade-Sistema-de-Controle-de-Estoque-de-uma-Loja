
#include <stdio.h>

char nomes[10][50];
float precos[10];
int quantidades[10];
int totalProdutos = 0;

float calcular_Venda(float preco, int quantidade)
{
    return preco * quantidade;
}

void registrarVenda()
{
    int codigo, quantidade;

    if (totalProdutos == 0)
    {
        printf("Nenhum produto cadastrado!\n");
        return;
    }

    printf("Digite o codigo do produto: ");
    scanf("%d", &codigo);

    if (codigo < 1 || codigo > totalProdutos)
    {
        printf("Codigo invalido!\n");
        return;
    }

    printf("Digite a quantidade desejada: ");
    scanf("%d", &quantidade);

    if (quantidade <= 0)
    {
        printf("Quantidade invalida!\n");
    }
    else if (quantidade <= quantidades[codigo - 1])
    {
        quantidades[codigo - 1] -= quantidade;

        printf("Venda realizada com sucesso!\n");
        printf("Produto: %s\n", nomes[codigo - 1]);
        printf("Valor total: R$ %.2f\n",
               calcular_Venda(precos[codigo - 1], quantidade));
        printf("Estoque restante: %d\n", quantidades[codigo - 1]);
    }
    else
    {
        printf("Venda nao pode ser realizada!\n");
        printf("Estoque disponivel: %d\n", quantidades[codigo - 1]);
    }
}

void verificarEstoqueBaixo()
{
    int i;

    printf("\n--- PRODUTOS COM ESTOQUE BAIXO ---\n");

    for (i = 0; i < totalProdutos; i++)
    {
        if (quantidades[i] < 5)
        {
            printf("Produto: %s\n", nomes[i]);
            printf("Quantidade: %d unidades\n", quantidades[i]);
        }
    }
}

int main()
{
    int opcao;

    do
    {
        printf("\n--- MENU DE PRODUTOS ---\n");
        printf("1 - Cadastrar produtos\n");
        printf("2 - Registrar venda\n");
        printf("3 - Verificar estoque baixo\n");
        printf("4 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Quantos produtos deseja cadastrar (1 a 10)? ");
            scanf("%d", &totalProdutos);

            if (totalProdutos < 1 || totalProdutos > 10)
            {
                printf("Quantidade invalida!\n");
                totalProdutos = 0;
                break;
            }

            for (int i = 0; i < totalProdutos; i++)
            {
                printf("\nProduto %d\n", i + 1);

                printf("Digite o nome do produto: ");
                scanf(" %49[^\n]", nomes[i]);

                printf("Digite o preco: ");
                scanf("%f", &precos[i]);

                printf("Digite a quantidade em estoque: ");
                scanf("%d", &quantidades[i]);
            }
            break;

        case 2:
            registrarVenda();
            break;

        case 3:
            verificarEstoqueBaixo();
            break;

        case 4:
            printf("Encerrando o programa...\n");
            break;

        default:
            printf("Opcao invalida!\n");
        }

    } while (opcao != 4);

    return 0;
}
