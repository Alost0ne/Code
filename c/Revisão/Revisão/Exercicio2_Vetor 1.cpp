#include <stdio.h>
#include <stdlib.h>
#include<locale.h>

/// 3. Faça um programa que cria uma lista de bebidas e as mostre em um cardápio.
 int main() {
 	setlocale(LC_ALL,"portuguese");
    int num_bebidas;
	
    printf("Quantidade de bebidas: ");
    scanf("%d", &num_bebidas);

	char bebidas[num_bebidas][50];
	
    printf("=== CADASTRO DE BEBIDAS ===\n");

    // Preenchendo a matriz com as bebidas
    for (int i = 0; i < num_bebidas; i++) {
        printf("Digite a bebida %d: ", i + 1);
        scanf(" %[^\n]", bebidas[i]);
    }

    printf("\n=== CARDÁPIO DE BEBIDAS ===\n");

    // Exibindo o cardápio de bebidas
    for (int i = 0; i < num_bebidas; i++) {
        printf("%d. %s\n", i + 1, bebidas[i]);
    }

    return 0;
}
