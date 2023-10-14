#include<stdio.h>
#include<locale.h>

main(){
	setlocale(LC_ALL,"portuguese");
	
	int num[5][3], i, j, valor;
	
	printf("Digite números para formar uma matriz.\n");
	
	for(i=0 ;i<5 ;i++){
		for(j=0 ;j<3 ;j++){
			printf("Posição %d-%d\t",i+1 ,j+1);
			scanf("%d",& num[i][j]);
		}
		printf("\n");
	}
	
	printf("Digite: \n'1' para ver a matriz. \n'2' para ver a matriz transposta.\n");
	scanf("%d",& valor);
	
	switch(valor){
	
		case 1 :
		system("cls");
		printf("Matriz\n");
		for(i=0; i<5; i++){
			for(j=0; j<3; j++){
				printf(" %d -", num[i][j]);
			}
			printf("\n");
		}
		break;
		
		case 2 :
		system("cls");
		printf("Matriz inversa\n");
		for(j=0; j<3; j++){
			for(i=0; i<5; i++){
				printf(" %d -", num[i][j]);
			}
			printf("\n");
		}
		break;
		
		default :
			printf("Valor indefinido\n");
	}
	
	system("pause");
	
	return 0;
}
