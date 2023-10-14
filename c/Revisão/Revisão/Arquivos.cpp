#include <stdio.h>
#include<locale.h>
#define NUM_POLTRONAS 10

/* Arquivo: 
Crie um algoritmo que armazene as informações obtidas nas funções anteriores em um arquivo, armazenando em cada linha a poltrona selecionada, o quanto ela gastou na lojinha e o tipo de filme que ela assistirá, bem como se este é 3d ou 2d;
 */

// Função para exibir as opções de temas de filmes
void exibirTemas() {
	setlocale(LC_ALL,"Portuguese");
    printf("Escolha um tema de filme:\n");
    printf("1. Ação\n");
    printf("2. Romance\n");
    printf("3. Comédia\n");
    printf("4. Terror\n");
    printf("5. Suspense\n");
}

// Função para exibir as opções de formatos
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

    // Obtém as informações das poltronas, gastos na lojinha, filmes e formatos
    for (int i = 0; i < NUM_POLTRONAS; i++) {
        printf("Digite a poltrona selecionada pela pessoa %d: ", i + 1);
        scanf("%d", &poltrona[i]);

        printf("Digite o gasto na lojinha da pessoa %d: ", i + 1);
        scanf("%f", &gasto_lojinha[i]);

        exibirTemas();
        printf("Digite o número correspondente ao tema escolhido pela pessoa %d: ", i + 1);
        scanf("%d", &filme[i]);

        exibirFormatos();
        printf("Digite o número correspondente ao formato escolhido pela pessoa %d: ", i + 1);
        scanf("%d", &formato[i]);
    }

    // Abre o arquivo para escrita
    arquivo = fopen("informacoes.txt", "w");

    // Verifica se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    // Escreve as informações no arquivo
    for (int i = 0; i < NUM_POLTRONAS; i++) {
        fprintf(arquivo, "Poltrona: %d - Gasto na lojinha: %.2f - Filme: %d (%s)\n", poltrona[i], gasto_lojinha[i], filme[i], formato[i] == 1 ? "2D" : "3D");
    }

    // Fecha o arquivo
    fclose(arquivo);

    printf("As informações foram armazenadas no arquivo 'informacoes.txt'.\n");

    return 0;
}

