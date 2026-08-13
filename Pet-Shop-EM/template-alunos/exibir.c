#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "comercio-template.h"

Produto estoque[MAX];
Venda v;
Produto p;
Estoque e;

 // Lógica de mostrar estoque
void mostrarEstoque() {
    if (indice_produto == 0) {
        printf("\nNenhum produto cadastrado.\n");
        return;
    }

    printf("\n--- Estoque ---\n");
    for (int i = 0; i < indice_produto; i++) {
        printf(" Produto %d: %s Codigo: %d \n Preco: R$ %.2f\n Estoque: %d \n ",
               i + 1, estoque[i].nome, estoque[i].codigo, estoque[i].preco, estoque[i].quantidade_estoque);
    }
}

