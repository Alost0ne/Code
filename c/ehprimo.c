#include<stdio.h>
#include<locale.h>

main(){
	setlocale(LC_ALL,"portuguese");
	
	int num, i;
	
	printf("Digite um n�mero: \n");
	scanf("%d",& num);
	
	if(num <= 1){
		printf("n�o � primo\n");
	}else{
		for(i = 2; i < num; i++){
			if(num % i == 0){
				printf("n�o � primo\n");
				break;
			}
		}
		if(i == num){
			printf("� primo!\n");
		}
	}
	
	return 0;
}
