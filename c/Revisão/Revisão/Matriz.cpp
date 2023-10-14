#include <stdio.h>
#define FILAS 20
#define COLUNAS 20
#include<locale.h>

/*Matriz:
Desenvolva um algoritmo que crie a sala de um cinema com a escala 20x20 e 
permita que o usuário reserve uma cadeira. Caso a cadeira que o usuário queira já esteja ocupada, 
mostre um aviso impedindo a ação*/

void exibirSala(char sala[FILAS][COLUNAS]) {
	setlocale(LC_ALL,"Portuguese");
    printf("Sala de cinema:\n");
    printf("  ");
    for (int i = 1; i <= COLUNAS; i++) {
        printf("%2d  ", i);
    }
    printf("\n");
    for (int i = 0; i < FILAS; i++) {
        printf("%2d", i + 1);
        for (int j = 0; j < COLUNAS; j++) {
            printf(" %c  ", sala[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char sala[FILAS][COLUNAS];
    
    // Inicializa a sala com todas as cadeiras livres
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            sala[i][j] = 'L'; // 'L' representa uma cadeira livre
        }
    }
    
    int fila, coluna;
    
    while (1) {
        exibirSala(sala);
        
        // Solicita ao usuário a cadeira que deseja reservar
        printf("\nDigite a fila (1 a 20) e a coluna (1 a 20) da cadeira que deseja reservar (0 0 para sair): ");
        scanf("%d %d", &fila, &coluna);
        if (fila == 0 && coluna == 0) {
            break;
        }
        if (fila < 1 || fila > FILAS || coluna < 1 || coluna > COLUNAS) {
            printf("Cadeira inválida! Por favor, escolha uma cadeira válida.\n\n");
            continue;
        }
        if (sala[fila - 1][coluna - 1] == 'O') {
            printf("A cadeira já está ocupada! Por favor, escolha outra cadeira.\n\n");
        } else {
            sala[fila - 1][coluna - 1] = 'O'; // 'O' representa uma cadeira ocupada
            printf("Cadeira reservada com sucesso!\n\n");
        }
    }
    
    return 0;
}

