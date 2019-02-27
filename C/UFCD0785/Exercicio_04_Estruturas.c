#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. Declaracao da estrutura pessoa e da variavel dados
struct pessoa
{
    char nome[50];
    char morada[20];
    int telefone;
    int idade;
} dados;// inicializar uma variavel chama dados.

void main()
{
    // 2. Fazendo a leitura dos dados
    printf("Digite seu nome:");
    //fgets(nome, tamanho, stdin); gets - get string : lé uma string do teclado
    //stdin ->standard input
    fgets(dados.nome, 50, stdin);

    printf("Indique a sua morada:");
    //scanf("%s", &dados.morada);
    fgets(dados.morada, 20, stdin);

    printf("Qual o seu telefone:");
    scanf("%d", &dados.telefone);


    printf("Digite a sua idade:");
    //fflush(stdin);//limpar o buffer do teclado
    scanf("%d", &dados.idade);

    // 3. Mostrar dados no monitor
    printf("\n===== LISTAR DADOS =====\n");
    printf("NOME..: %s", dados.nome);
    printf("MORADA....: %s", dados.morada);
    printf("TELEFONE...: %d \n", dados.telefone);
    printf("IDADE.: %d \n", dados.idade);


}
