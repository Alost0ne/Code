
/*O Programa faz a SOMA e Multiplica (A.B e B.A) das matrizes.*/

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>


main(){
	int MATRIZA[2][2],MATRIZB[2][2],RESsoma[2][2],RESmulAB[2][2],i,j,K,RESmulBA[2][2];
	setlocale(LC_ALL,"");
	
	
	printf("\n\n\nO Programa faz a SOMA e Multiplica (A.B e B.A) das matrizes.\n\Por favor complete as matrizes conforme o nº abaixo:\n\n\tX.1\tX.2\n\tX.3\tX.4\n");
	printf("\n\nPor favor informar os valores abaixo da Matriz A:\n");
K=1;
	for(i=0;i<=1;i++){for(j=0;j<=1;j++){
		
		printf("Escreva o valor de X.%d:",K);
		scanf("%d",&MATRIZA[i][j]);
		K++;
	}}
	K=1;
		printf("\n\nPor favor informar os valores abaixo da Matriz B:\n");
		for(i=0;i<=1;i++){for(j=0;j<=1;j++){
		
		printf("Escreva o valor de X.%d:",K);
		scanf("%d",&MATRIZB[i][j]);
		K++;
	}}
	
		printf("\n\nMatriz A:\n");
		for(i=0;i<=1;i++){for(j=0;j<=1;j++){
		printf("%d\t",MATRIZA[i][j]);
}	printf("\n");
}
		
		printf("\n\nMatriz B:\n");
		for(i=0;i<=1;i++){for(j=0;j<=1;j++){
		printf("%d\t",MATRIZB[i][j]);
}	printf("\n");
}

	printf("\n\nA soma das matrizes fica conforme abaixo:\n\n");
	
	for(i=0;i<=1;i++){for(j=0;j<=1;j++){
	RESsoma[i][j]=MATRIZA[i][j] + MATRIZB[i][j];
	
}}
			for(i=0;i<=1;i++){for(j=0;j<=1;j++){
		printf("%d\t",RESsoma[i][j]);
}	printf("\n");
}
	printf("\n\nA Multiplicação das matrizes (A.B) fica conforme abaixo:\n\n");
	RESmulAB[0][0]=(MATRIZA[0][0] * MATRIZB[0][0])+(MATRIZA[0][1] * MATRIZB[1][0]);
	RESmulAB[0][1]=(MATRIZA[0][0] * MATRIZB[0][1])+(MATRIZA[0][1] * MATRIZB[1][1]);
	RESmulAB[1][0]=(MATRIZA[1][0] * MATRIZB[0][0])+(MATRIZA[1][1] * MATRIZB[1][0]);
	RESmulAB[1][1]=(MATRIZA[1][0] * MATRIZB[0][1])+(MATRIZA[1][1] * MATRIZB[1][1]);
	
	for(i=0;i<=1;i++){for(j=0;j<=1;j++){
	printf("%d\t",RESmulAB[i][j]);
}	printf("\n");
}

	printf("\n\nA Multiplicação das matrizes (B.A) fica conforme abaixo:\n\n");
	RESmulBA[0][0]=(MATRIZB[0][0] * MATRIZA[0][0])+(MATRIZB[0][1] * MATRIZA[1][0]);
	RESmulBA[0][1]=(MATRIZB[0][0] * MATRIZA[0][1])+(MATRIZB[0][1] * MATRIZA[1][1]);
	RESmulBA[1][0]=(MATRIZB[1][0] * MATRIZA[0][0])+(MATRIZB[1][1] * MATRIZA[1][0]);
	RESmulBA[1][1]=(MATRIZB[1][0] * MATRIZA[0][1])+(MATRIZB[1][1] * MATRIZA[1][1]);
	
	for(i=0;i<=1;i++){for(j=0;j<=1;j++){
	printf("%d\t",RESmulBA[i][j]);
}	printf("\n");
}
}

