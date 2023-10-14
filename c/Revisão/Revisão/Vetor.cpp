#include <stdio.h>
#define NUM_TEMAS 5
#define NUM_FORMATOS 2
#include<locale.h>

/* vetor: 
Crie um algoritmo que apresente 5 opções de temas de filmes (ação, romance, comédia, terror, suspense) através de um vetor selecionável. 
Após isso , a pessoa deve escolher se o filme será 2d ou 3d (Também feito em vetor); 
*/

int main() {
	setlocale(LC_ALL,"Portuguese");
    char temas[NUM_TEMAS][20] = {
        "Ação",
        "Romance",
        "Comédia",
        "Terror",
        "Suspense"
    };
    char formatos[NUM_FORMATOS][3] = {
        "2D",
        "3D"
    };

    int escolha_tema, escolha_formato;
    printf("Escolha um tema de filme:\n");
    for (int i = 0; i < NUM_TEMAS; i++) {
        printf("%d. %s\n", i + 1, temas[i]);
    }
    printf("Digite o número correspondente ao tema escolhido: ");
    scanf("%d", &escolha_tema);
    if (escolha_tema < 1 || escolha_tema > NUM_TEMAS) {
        printf("Escolha inválida!\n");
        return 1;
    }
    printf("\nEscolha o formato:\n");
    for (int i = 0; i < NUM_FORMATOS; i++) {
        printf("%d. %s\n", i + 1, formatos[i]);
    }

    printf("Digite o número correspondente ao formato escolhido: ");
    scanf("%d", &escolha_formato);

    if (escolha_formato < 1 || escolha_formato > NUM_FORMATOS) {
        printf("Escolha inválida!\n");
        return 1;
    }

    printf("\nVocê escolheu o tema: %s\n", temas[escolha_tema - 1]);
    printf("Formato escolhido: %s\n", formatos[escolha_formato - 1]);

    return 0;
}

