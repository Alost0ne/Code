#include<stdio.h>
#include<locale.h>

main(){
	setlocale(LC_ALL,"portuguese");
	
	int num[3][5], i, j, opcao;
	
	printf("Digite números para completar uma matriz\n");
	
	for(i=0; i<3; i++){
		for(j=0; j<5; j++){
			printf("posição %d-%d:\t", i+1, j+1);
			scanf("%d",& num[i][j]);
		}
		printf("\n");
	}
	
	system("cls");
	printf("Agora escolha uma opção:\n[1] - para exibir a matriz\n[2] - para exibir a matriz inversa\n\t:");
	scanf("%d",& opcao);
	
	switch(opcao){
			case 1: 
		printf("\tMatriz\n");
		for(i=0; i<3; i++){
			for(j=0; j<5; j++){
				printf("\t%d", num[i][j]);
			}
			printf("\n");
		}
		break;
		
			case 2:
		printf("\tMatriz inversa\n");
		for(j=0; j<5; j++){
			for(i=0; i<3; i++){
				printf("\t%d", num[i][j]);
			}
			printf("\n");
		}
		break;
		
		default :
			printf("Valor invalido\n");
			break;
	}
	
	system("pause");
	
	return 0;
}
