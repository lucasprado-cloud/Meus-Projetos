 #include <stdio.h>
 #include <locale.h>
 #include "comercio-template.h"

 int main() {
    // setlocale(LC_ALL, "Portuguese_Brazil); // Windows

    int opcao;
    do {
            //menu de exemplo, deve ser trocado para um melhor
        printf("\n=++=_ PET SHOP _=++=\n");
        printf("1. Cadastrar Produto\n");
        printf("2. Mostrar Estoque\n");
        printf("3. Vender Produto\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar();

         switch (opcao) {
            case 1:
                cadastrarProduto(); // chama a função que cadastra produtos
                break;
            case 2:
                mostrarEstoque();  // chama a função que mostra o estoque
                break;
            case 3:
                venderProduto();   // chama a função que realiza a venda
                break;
            case 0:
                printf("Saindo...\n"); // mensagem ao sair do programa
                break;
            default:
                printf("Opção inválida!\n"); // caso o usuário digite algo errado
        }
    } while (opcao != 0);

    return 0;
}

