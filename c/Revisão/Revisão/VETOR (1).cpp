//Faça um programa com função que leia 5 números em um vetor e os exiba dobrados

#include <stdio.h>
#include <locale.h>
#define DIM 5
 
int recebe(int original[]){
    int i = 0;
 
    for(i = 0; i < DIM ; i++){
        printf("Entre com o elemento %d: ", i+1);
        scanf("%d", &original[i]);
    }
}
 
int copiar(int copiado[], int original[]){
    int i;
 
    for(i=0 ; i < DIM ; i++)
        copiado[i] = original[i];
}
 
int dobrar(int dobrado[], int original[]){
    int i;

    for(i=0 ; i < DIM ; i++)
        dobrado[i] = 2 * original[i];
}
 
int exibir(int vet[]){
    int i;
 
    for(i=0 ; i < DIM ; i++)
        printf("%3d ", vet[i]);
}
 
int main(void){
	
	setlocale(LC_ALL, "Portuguese");
	
    int original[DIM],
        dobrado[DIM];
 
    recebe(original);
    dobrar(dobrado, original);
 
    printf("Vetor original: ");
    exibir(original);
 
    printf("\nVetor dobrado : ");
    exibir(dobrado);
 
    return 0; 
}
