#ifndef COMERCIO_TEMPLATE_H_INCLUDED
#define COMERCIO_TEMPLATE_H_INCLUDED

#define MAX 100 //define o maximo de produtos que podem ser cadastrados


//struct de produto
typedef struct {

    char nome[21];
    int codigo;
    float preco;
    int quantidade_estoque;

} Produto;


//struct de venda
typedef struct{
    int codigo_do_produto;
    int quantidade_compra;
    float total_compra;
    int pagamento;
    int parcela;
    int pixparcela;
    float valor_parcela;
    float dinheiro;
    float troco;
} Venda;


//struct de estoque
typedef struct {
    int produto_cadastrado;

} Estoque;




extern Produto estoque[MAX];
extern int indice_produto;

void mostrarEstoque();
void cadastrarProduto();
void venderProduto();

#endif // COMERCIO-TEMPLATE_H_INCLUDED
