#include<stdio.h>
#include<locale.h>

main(){
	setlocale(LC_ALL,"portuguese");
	
	int num, i, contador=0;
	
	printf("Digite um número: ");
	scanf("%d",& num);
	if(num == 0){
		printf("Erro, digite outro número...");
		return 0;
	}else{
		for(i=1; i<=num; i++){
			if(i % 2 ==0){
				contador++;
			}	
		}
	printf("O número de pares é: %d\n",contador);
		}
	system("pause");
	
	return 0;
}
