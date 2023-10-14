#include<stdio.h>
#include<locale.h>

main(){
	setlocale(LC_ALL,"portuguese");
	
	int num[6], i;
	
	for(i=0 ;i<6 ;i++){
		printf("Digite o  %d° número: ",i+1);
		scanf("%d",& num[i]);
	}
	printf("Agora os números na ordem inversa:\n ");
	for(i=5 ;i>=0 ;i--){
		printf("%d - ", num[i]);
	}
	system("pause");
	
	return 0;
}
