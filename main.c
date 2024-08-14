#include "funcoes.h"
#include <stdio.h>
#include <string.h>

int main() {
  struct Produto prateleira[TAM];
  int opcao, codproduto, i;
  float valorTotal, calculo;

  receberDadosProduto(prateleira, TAM);

  do {
    apresentarMenu();
    scanf("%d", &opcao);
    switch (opcao) {
    case 1:
      printf("\nQual o produto deseja calcular o estoque? ");
      scanf("%d", &codproduto);
      printf("\nO valor em estoque do produto de codigo %d eh de: %.2f\n",
             codproduto,
             calcularValorEstoqueProduto(prateleira, TAM, codproduto));
      break;
    case 2:
      printf("\nO valor total em estoque eh: R$%.2f\n",
             calcularValorTotalEstoque(prateleira, TAM));
      break;
    case 3:
      encontrarProdutoMaisCaro(prateleira, TAM);
      break;
    case 4:
      encontrarProdutoMaisBarato(prateleira, TAM);
      break;
    case 5:
      printf("\nEncerrando operacao...\n");
      break;
    default:
      printf("\n Codigo invalida! Tente Novamente.\n");
    }
  } while (opcao != 5);

  return 0;
}