#include <stdio.h>
#include<locale.h>

/* fun��es: 
Desenvolva um algoritmo de venda de pipoca (P,M,G, GG), bebidas (�gua, com g�s, refri e suco), 
chocolate (morango, chocolate e coco) e 
uma fun��o calculando os pre�os definidos pelo usu�rio;
 */

// Fun��o para calcular o pre�o total
float calcularPreco(int tamanho_pipoca, int tipo_bebida, int tipo_chocolate) {
    float preco_pipoca, preco_bebida, preco_chocolate;
    
    // Defini��o dos pre�os
    float precos_pipoca[4] = {0, 5.0, 7.0, 9.0};    
    float precos_bebida[5] = {0, 2.0, 2.5, 3.0, 3.5}; 
    float precos_chocolate[4] = {0, 4.0, 4.5, 5.0};
    
    // Obter os pre�os selecionados
    preco_pipoca = precos_pipoca[tamanho_pipoca];
    preco_bebida = precos_bebida[tipo_bebida];
    preco_chocolate = precos_chocolate[tipo_chocolate];
    
    // Calcular o pre�o total
    float preco_total = preco_pipoca + preco_bebida + preco_chocolate;
    
    return preco_total;
}
main() {
    
    setlocale(LC_ALL,"Portuguese");
	// Tamanhos de pipoca
    printf("Tamanhos de pipoca:\n");
    printf("1 - Pequena\n");
    printf("2 - M�dia\n");
    printf("3 - Grande\n");
    printf("4 - Extra Grande\n");
    
    int tamanho_pipoca;
    printf("Escolha o tamanho da pipoca (1-4): ");
    scanf("%d", &tamanho_pipoca);
    
    // Tipos de bebida
    printf("\nTipos de bebida:\n");
    printf("1 - �gua\n");
    printf("2 - �gua com g�s\n");
    printf("3 - Refrigerante\n");
    printf("4 - Suco\n");
    
    int tipo_bebida;
    printf("Escolha o tipo de bebida (1-4): ");
    scanf("%d", &tipo_bebida);
    

    printf("\nTipos de chocolate:\n");
    printf("1 - Morango\n");
    printf("2 - Chocolate\n");
    printf("3 - Coco\n");
    
    int tipo_chocolate;
    printf("Escolha o tipo de chocolate (1-3): ");
    scanf("%d", &tipo_chocolate);
    float preco_total = calcularPreco(tamanho_pipoca, tipo_bebida, tipo_chocolate);
    printf("\nPre�o total: R$%.2f\n", preco_total);
    
    return 0;
}

