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
                cadastrarProduto(); // chama a fun��o que cadastra produtos
                break;
            case 2:
                mostrarEstoque();  // chama a fun��o que mostra o estoque
                break;
            case 3:
                venderProduto();   // chama a fun��o que realiza a venda
                break;
            case 0:
                printf("Saindo...\n"); // mensagem ao sair do programa
                break;
            default:
                printf("Op��o inv�lida!\n"); // caso o usu�rio digite algo errado
        }
    } while (opcao != 0);

    return 0;
}

