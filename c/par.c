#include<stdio.h>
#include<locale.h>

main(){
	setlocale(LC_ALL,"portuguese");
	
	int num, i, contador=0;
	
	printf("Digite um n�mero: ");
	scanf("%d",& num);
	
	if(num % 2 == 0){
		printf("� par\n");
	}else{
		printf("� �mpar\n");
	}
	
	system("pause");
	
	return 0;
}
