/*	
	// exemplo vetor 
	
	#include<stdio.h>
	#include<stdlib.h>
	#include<locale.h>


		// 1) Faça um programa, que leia um vetor chamado NUMERO de 3 posições, conte quantos valores são positivos  e escreva essa informação. 
		int num[3],i,positivos = 0;

	main(){
		setlocale(LC_ALL,"portuguese");

		int num[3], i , pos= 0;
		
		for(i=0;i<3;i++){
		
		printf("digite qual é o numero %d: \n",i+1);
		scanf("%d",&num[i]);
	}

	for (i=0;i<3;i++){
	if (num[i]>0){
	pos++;
	}
	}

		printf("Existem %d valores positivos no vetor num.\n",pos);
		return 0;
	}
	

*/
	// 2) Faça um programa com 3 tamanhos de 3 peças de roupas



#include<stdio.h>
#include<stdlib.h>
#include<locale.h>



main()
{
	setlocale(LC_ALL,"portuguese");

	int tamanhos[3][3];
	char tamanhos[3][3];
	int roupas, tamanho, i;
		
	for(roupas=0;roupas<3;roupas++){
		printf("digite os 3 tamanhos de roupas %d - P M G \n", roupas+1);
			
	for(tamanho=0;tamanho<3;tamanho++){
			scanf(" %c", &tamanhos[roupas][tamanho]);
	}	
	
	//motrar resultado
	//printf ("os tamanhos são %f" , &tamanhos[roupas][tamanho]);
}
	
	for(roupas=0;roupas<3;roupas++){
			printf("\n");
	for(tamanho=0;tamanho<3;tamanho++){
	printf ("%c\t",tamanhos[roupas][tamanho]);
	}	
	
}
}


 
// 3) Faça um programa, que leia os 16 valores de uma matriz 4x4 de elementos reais e crie a matriz transposta da matriz fornecida.

/*

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>	
	

main()
{
	setlocale(LC_ALL,"portuguese");
	int matriz[4][4];
	int elem1, elem2;
			for(elem1=0;elem1<4;elem1++){
		for(elem2=0;elem2<4;elem2++) {
	printf("digite as os 16 numeros da matriz \n");
	scanf ("%d", &matriz[elem1][elem2]);
}	
}
	for(elem1=0;elem1<4;elem1++){
		for(elem2=0;elem2<4;elem2++){
		printf (" \t %d ",  matriz[elem2][elem1]);
	}
	printf ("\n");
}
	
}
*/

	
	
	
