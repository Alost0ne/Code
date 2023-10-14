#include <stdio.h>

// Tópico - Matriz
//  1) Faça um programa que lê uma matriz de 3 x 3 elementos usando um comando for, multiplica cada elemento por 5 e imprime o resultado. 

int main(){
	int linha,coluna,matriz[3][3];	
	for(linha=0;linha<3;linha++){
		for(coluna=0;coluna<3;coluna++){
			printf("Digite um valor:");
			scanf("%d",&matriz[linha][coluna]);
		}
	}
	printf("\n");
	// pára imprimir a matriz:
	for(linha=0;linha<3;linha++){
		for(coluna=0;coluna<3;coluna++){
			printf("%d ",matriz[linha][coluna]);
		
		}
	printf("\n");	
	}
	
	// Multiplica por 5
	
	for(linha=0;linha<3;linha++){
		for(coluna=0;coluna<3;coluna++){
			matriz[linha][coluna] = matriz[linha][coluna] * 5;
		}
	}
	// Mostra os valores multiplicados
		printf("\n::: Valores Multiplicados por 5:::\n");
	 for(linha=0;linha<3;linha++){
	 for(coluna=0;coluna<3;coluna++)
	 printf("%d ",matriz[linha][coluna]);
	 printf("\n");
	 }
	 return 0;	
}
