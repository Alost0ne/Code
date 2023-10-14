#include<stdio.h>
#include<locale.h>

main(){
	setlocale(LC_ALL,"portuguese");
	
	int num, i;
	
	printf("Digite um número: \n");
	scanf("%d",& num);
	
	if(num <= 1){
		printf("não é primo\n");
	}else{
		for(i = 2; i < num; i++){
			if(num % i == 0){
				printf("não é primo\n");
				break;
			}
		}
		if(i == num){
			printf("É primo!\n");
		}
	}
	
	return 0;
}
