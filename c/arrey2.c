#include<stdio.h>
#include<locale.h>

main(){
	setlocale(LC_ALL,"portuguese");
	
	int num[5][3], l, c;
	
	printf("Digite os n�meros para completar a matriz.\n");
	
	for(l=0 ;l<5 ;l++){
		for(c=0 ;c<3 ;c++){
			printf("Posi��o %d-%d: ",l+1 ,c+1);
			scanf("%d",& num[l][c]);
		}
		printf("\n");
	}

	printf("Os n�meros na matriz: \n");
	for(l=0 ;l<5 ;l++){
		for(c=0 ;c<3 ;c++){
			printf(" %d -", num[l][c]);
		}
		printf("\n");
	}

	printf("Agora os n�meros na matriz inversa: \n");
	for(c=0 ;c<3 ;c++){
		for(l=0 ;l<5 ;l++){
			printf(" %d -", num[l][c]);
		}
		printf("\n");
	}
	printf("\n");
	system("pause");
	
	return 0;
}
