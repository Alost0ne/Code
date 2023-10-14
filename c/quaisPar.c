#include<stdio.h>
#include<locale.h>

main(){
	setlocale(LC_ALL,"portuguese");
	
	int num, i;
	
	printf("Digite um número, e o código irá mostrar todos os pares até o número.\n");
	scanf("%d",& num);
	
	printf("Os pares de 1 até %d são:\n", num);
	
	for(i=1; i<=num; i++){
		if(i % 2 == 0){
			printf("%d, ",i);
		}
	}
	system("pause");
	
	return 0;
}
