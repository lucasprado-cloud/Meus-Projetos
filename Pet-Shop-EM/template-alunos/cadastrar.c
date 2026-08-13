#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "comercio-template.h"


Produto p;
Venda v;
Estoque e;
int indice_produto = 0;


void cadastrarProduto() {

    //é possivel que de problema, se der, exclua!!!!!!!!!!!!!!!!!
    if (indice_produto >= MAX) {
        printf("\nErro: Estoque cheio, não é possível cadastrar mais produtos.\n");
    }

    // Cadastrar produto
    printf("\nDigite o codigo do produto: ");
    scanf("%d", &p.codigo);
    getchar();  // Limpa o '\n'

    if (p.codigo <= 0 || p.codigo > 999) {
        printf("\nCodigo invalido! O codigo deve ser maior que 0 e ter no maximo 3 digitos.\n");
    } else {
        // Le o nome do produto
        printf("\nDigite o nome do produto: ");
        fgets(p.nome, sizeof(p.nome), stdin);  // Le o nome com espacos

        // Validar o preço do produto
        printf("\nDigite o preco do produto:\n");
        scanf("%f", &p.preco);
        getchar();  // Limpa o '\n'

        if (p.preco <= 0) {
            printf("Valor invalido, por favor digite outro valor...\n");
        } else {
            // Validar a quantidade
            printf("\nDigite a quantidade de produtos no estoque:\n");
            scanf("%d", &p.quantidade_estoque);
            getchar();  // Limpa o '\n'

            if (p.quantidade_estoque <= 0 || p.quantidade_estoque > 100) {
                printf("Quantidade invalida! A quantidade deve ser maior que 0 ou menor que 100.\n");
                return;
            } else {
                // Armazenar produto no estoque
                estoque[indice_produto] = p;
                e.produto_cadastrado = 1;
                indice_produto++; // Avança para o próximo índice do vetor
                printf("\nProduto cadastrado com sucesso!\n");
            }
        }
    }

}

// Lógica de vender produto
void venderProduto() {
    if (e.produto_cadastrado == 0) {
        printf("\nNenhum produto no sistema...\n");
        return;
    }

    if (e.produto_cadastrado == 1) {
        // Validar quantidade de compra
        printf("\nDigite quantas unidades deseja comprar:\n");
        scanf("%d", &v.quantidade_compra);
        getchar(); // Limpa o '\n'

        if (v.quantidade_compra <= 0 || v.quantidade_compra > p.quantidade_estoque) {
            printf("Voce nao pode comprar essa quantidade.\n");
            return;
        } else {
            // Calcular o valor total da compra
            v.total_compra = p.preco * v.quantidade_compra; // Total da compra baseado na quantidade e preço
            p.quantidade_estoque = p.quantidade_estoque - v.quantidade_compra;
        }

        // Finalizar compra
        printf("\n--- Finalizando Compra ---\n");
        printf("\nTotal da compra: R$ %.2f\n", v.total_compra);
        printf("\nQuantidade restante no estoque: %d\n", p.quantidade_estoque); // Exibe a quantidade restante no estoque

        // Escolher forma de pagamento
        printf("\nEscolha a forma de pagamento:\n");
        printf("1 - Cartao de Credito\n");
        printf("2 - Cartao de Debito\n");
        printf("3 - Dinheiro\n");
        printf("0 - Cancelar compra\n");
        scanf("%d", &v.pagamento);
        getchar(); // Limpa o '\n'

        switch (v.pagamento) {
            case 1:
                if (v.total_compra < 100) {
                printf("\nO valor da sua compra e muito baixo para ser parcelado.\n");
                return;}

                printf("Em quantas vezes deseja parcelar? (ate 6 vezes sem juros)");
                scanf("%d", &v.parcela);

                if (v.parcela <= 0 || v.parcela > 6 ) {
                    printf("\nEssa parcela nao existe.\n");
                    return;
                }

                else {
                    v.valor_parcela = v.total_compra / v.parcela; // Correção aqui
                    printf("\nO valor da sua parcela e: R$ %.2f\n", v.valor_parcela);
                    printf("Valor total :%.2f", v.total_compra);
                }
                break;

            case 2:
                printf("\nPagamento com cartao de debito confirmado.\n");
                printf("\nO valor descontado foi:%.2f", v.total_compra);
                break;


            case 3:
                printf("\nDigite sua quantia em dinheiro.\n");
                scanf("%.2f", &v.dinheiro);
                if (v.dinheiro < v.total_compra) {
                    printf ("Voce nao tem dinheiro suficiente...\nEscolha outro metodo de pagamento ou coloque um valor de dinheiro maior.");
                    return;
                } else { v.troco = v.dinheiro - v.total_compra;
                         printf ("\nSeu troco e:%.2f", &v.troco);
                }
                break;

            case 0:
                printf("\nSua compra foi cancelada\n");
                p.quantidade_estoque = p.quantidade_estoque + v.quantidade_compra;
                return;

            default:
                printf("Opção de pagamento inválida.\n");
                break;
        }
    }
}


