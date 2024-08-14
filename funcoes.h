#define TAM 10

struct Produto {
  int codigo;
  int quantidade;
  float preco;
  char nome[20];
};

void apresentarMenu();
void receberDadosProduto(struct Produto prateleira[], int tamPrateleira);
float calcularValorEstoqueProduto(struct Produto prateleira[],
                                  int tamPrateleira, int codproduto);
float calcularValorTotalEstoque(struct Produto prateleira[], int tamPrateleira);
void encontrarProdutoMaisCaro(struct Produto prateleira[], int tamPrateleira);
void encontrarProdutoMaisBarato(struct Produto prateleira[], int tamPrateleira);