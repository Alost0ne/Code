#include<stdio.h>
#include<locale.h>

main(){
	setlocale(LC_ALL,"portuguese");
	
	int num, i, contador=0;
	
	printf("Digite um número: ");
	scanf("%d",& num);
	
	if(num % 2 == 0){
		printf("É par\n");
	}else{
		printf("É ímpar\n");
	}
	
	system("pause");
	
	return 0;
}
