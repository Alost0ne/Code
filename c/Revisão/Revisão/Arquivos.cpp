#include <stdio.h>
#include<locale.h>
#define NUM_POLTRONAS 10

/* Arquivo: 
Crie um algoritmo que armazene as informa��es obtidas nas fun��es anteriores em um arquivo, armazenando em cada linha a poltrona selecionada, o quanto ela gastou na lojinha e o tipo de filme que ela assistir�, bem como se este � 3d ou 2d;
 */

// Fun��o para exibir as op��es de temas de filmes
void exibirTemas() {
	setlocale(LC_ALL,"Portuguese");
    printf("Escolha um tema de filme:\n");
    printf("1. A��o\n");
    printf("2. Romance\n");
    printf("3. Com�dia\n");
    printf("4. Terror\n");
    printf("5. Suspense\n");
}

// Fun��o para exibir as op��es de formatos
void exibirFormatos() {
	
    printf("Escolha o formato:\n");
    printf("1. 2D\n");
    printf("2. 3D\n");
}

int main() {
	
    FILE *arquivo;
    int poltrona[NUM_POLTRONAS];
    float gasto_lojinha[NUM_POLTRONAS];
    int filme[NUM_POLTRONAS];
    int formato[NUM_POLTRONAS];

    // Obt�m as informa��es das poltronas, gastos na lojinha, filmes e formatos
    for (int i = 0; i < NUM_POLTRONAS; i++) {
        printf("Digite a poltrona selecionada pela pessoa %d: ", i + 1);
        scanf("%d", &poltrona[i]);

        printf("Digite o gasto na lojinha da pessoa %d: ", i + 1);
        scanf("%f", &gasto_lojinha[i]);

        exibirTemas();
        printf("Digite o n�mero correspondente ao tema escolhido pela pessoa %d: ", i + 1);
        scanf("%d", &filme[i]);

        exibirFormatos();
        printf("Digite o n�mero correspondente ao formato escolhido pela pessoa %d: ", i + 1);
        scanf("%d", &formato[i]);
    }

    // Abre o arquivo para escrita
    arquivo = fopen("informacoes.txt", "w");

    // Verifica se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    // Escreve as informa��es no arquivo
    for (int i = 0; i < NUM_POLTRONAS; i++) {
        fprintf(arquivo, "Poltrona: %d - Gasto na lojinha: %.2f - Filme: %d (%s)\n", poltrona[i], gasto_lojinha[i], filme[i], formato[i] == 1 ? "2D" : "3D");
    }

    // Fecha o arquivo
    fclose(arquivo);

    printf("As informa��es foram armazenadas no arquivo 'informacoes.txt'.\n");

    return 0;
}

