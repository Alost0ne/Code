#include<stdio.h>
#include<locale.h>

main(){
	setlocale(LC_ALL,"portuguese");
	
	int num, i;
	
	printf("Digite um n�mero, e o c�digo ir� mostrar todos os pares at� o n�mero.\n");
	scanf("%d",& num);
	
	printf("Os pares de 1 at� %d s�o:\n", num);
	
	for(i=1; i<=num; i++){
		if(i % 2 == 0){
			printf("%d, ",i);
		}
	}
	system("pause");
	
	return 0;
}
