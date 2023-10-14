#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>
#include<string.h>

FILE * pArq;
FILE * temp;

char funcionario[100];
char nome[30];
char funcao[30];
float salario;

void cadastrar(){
	
	pArq = fopen("funcionario.txt", "a");
	printf("Digite seu nome:\n");
	fflush(stdin);
	gets(nome);
	printf("Digite sua funcao:\n");
	fflush(stdin);
	gets(funcao);
	printf("digite seu salario:\n");
	fflush(stdin);
	scanf("%f", &salario);
	fprintf(pArq,"%s-%s-%.2f\n",nome,funcao,salario);
	fclose(pArq);
	printf("boa mano");
	
	}
	
void excluir(){
	int id, valid=1;
	printf("Digite o id do funcionário que deseja excluir:");
	scanf("%d",&id);
	
	pArq = fopen("funcionario.txt","r");
	temp = fopen("temp.txt","w");
	
	while(fgets(funcionario,100,pArq) != NULL){
		if(valid != id ){
			fprintf(temp,"%s",funcionario);
		}
		valid++;
	}
	fclose(pArq);
	fclose(temp);
	
	remove("funcionario.txt");
	rename("temp.txt","funcionario.txt");
}

int main(){
	int escolha;
	printf("Digite 1 para cadastrar e 2 para excluir:");
	scanf("%d",&escolha);
	if(escolha==1){
	    cadastrar();
    } else {
    	excluir();
	}    

}	
