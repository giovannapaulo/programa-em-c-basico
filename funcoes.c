#include "funcoes.h"
#include <stdio.h>
#include <string.h>

void apresentarMenu() {
  printf("\nFaca a escolha de sua opcao: \n");
  printf("1. Realizar calculo do valor em estoque de um produto especifico.\n");
  printf("2. Realizar caculo do valor total em estoque dos produtos.\n");
  printf("3. Encontrar o produto mais caro da prateleira.\n");
  printf("4. Encontrar o produto mais barato da prateleira.\n");
  printf("5. Finalizar operacao.\n");
}
void receberDadosProduto(struct Produto prateleira[], int tamPrateleira) {
  int i;
  for (i = 0; i < tamPrateleira; i++) {
    printf("Digite o nome do produto: ");
    fgets(prateleira[i].nome, sizeof(prateleira[i].nome), stdin);
    if(prateleira[i].nome[strlen(prateleira[i].nome) - 1] == '\n')
      prateleira[i].nome[strlen(prateleira[i].nome)-1] = '\0';
    printf("Insira o codigo do seu produto: ");
    scanf("%d", &prateleira[i].codigo);
    printf("Insira a quantidade do seu produto: ");
    scanf("%d", &prateleira[i].quantidade);
    printf("Insira o preco do seu produto: ");
    scanf("%f", &prateleira[i].preco);
    __fpurge(stdin);
  }
}

float calcularValorEstoqueProduto(struct Produto prateleira[],
                                  int tamPrateleira, int codproduto) {
  int i;
  float calculo = 0.0;
  for (i = 0; i < tamPrateleira; i++) {
    if (prateleira[i].codigo == codproduto) {
      calculo = (float)prateleira[i].quantidade * prateleira[i].preco;
      break;
    }
  }
  return calculo;
}

float calcularValorTotalEstoque(struct Produto prateleira[],
                                int tamPrateleira) {
  int i;
  float valorTotal = 0.0;
  for (i = 0; i < tamPrateleira; i++) {
    valorTotal += (float)prateleira[i].quantidade * prateleira[i].preco;
  }
  return valorTotal;
}

void encontrarProdutoMaisCaro(struct Produto prateleira[], int tamPrateleira) {
  int i, maiscaro = 0;
  for (i = 0; i < tamPrateleira; i++) {
    if (prateleira[i].preco > prateleira[maiscaro].preco) {
      maiscaro = i;
    }
  }
  printf("\nO produto mais caro eh o %d: R$%.2f\n", prateleira[maiscaro].codigo,
         prateleira[maiscaro].preco);
}

void encontrarProdutoMaisBarato(struct Produto prateleira[],
                                int tamPrateleira) {
  int i, maisbarato=0;
  for (i = 0; i < tamPrateleira; i++) {
    if (prateleira[i].preco < prateleira[maisbarato].preco) {
      maisbarato = i;
    }
  }
  printf("\nO produto mais barato eh o %d: R$%.2f\n",
         prateleira[maisbarato].codigo, prateleira[maisbarato].preco);
}