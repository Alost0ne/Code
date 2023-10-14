#include<stdio.h>
#include<locale.h>

void visuInicio();
	int op;
	
void calculadora();
void visuCalculadora1();
	float num1, num2;
	char opCalculadora;

void matriz();

void primo();
	int i, opPrimo;
	int numPrimo;
	
main(){
	setlocale(LC_ALL,"portuguese");
	
	visuInicio();
	
	switch(op){
		case 1:
			system("cls");
			calculadora();
			break;
		case 2:
			system("cls");
			matriz();
			break;	
		case 3:
			system("cls");
			primo();
			break;
		default:
			return 0;
	}
	return 0;
	system("pause");
}


void calculadora(){
	
	visuCalculadora1();
	
	switch(opCalculadora){
		case '+':
			system("cls");
			printf("\tAdição:\n\n");
			printf("A operação de %.2f + %.2f é igual a:",num1, num2, num1 + num2);
			break;
		case '-':
			system("cls");
			printf("\tSubtração:\n\n");
			printf("A operação de %.2f + %.2f é igual a:",num1, num2, num1 - num2);
			break;
		case '/':
			system("cls");
			printf("\tDivisão:\n\n");
			if(num1 || num2 == 0){
				printf("Não é possivel dividir por 0.");
				break;
			} else{
				printf("A operação de %.2f + %.2f é igual a:",num1, num2, num1 / num2);
			}
			break;
		case '*':
			system("cls");
			printf("\tMultiplicação:\n\n");
			printf("A operação de %.2f + %.2f é igual a:",num1, num2, num1 * num2);
			break;
		default:
			system("cls");
			printf("\tErro: Opção invalida");
			break;
	}
}

void matriz(){
	printf("Matriz");
}

void primo(){

	printf("\t\tPrimos\n\n");
	printf("O que você deseja?\n");
	printf("1 - Saber se um número é primo;\n");
	printf("2 - Saber quantos números primos existem até o número escolhido;\n");
	printf("3 - Saber quais números primos até o número escolhido.\n");
	scanf("%d", & opPrimo);
	
	switch(opPrimo){
		case 1:
			printf("\tSaber se um número é primo:\n\n");
			printf("Digite um número: ");
			scanf("%d", & numPrimo);
			if(numPrimo == 1){
				printf("1 é o menor número primo");
			}else if(numPrimo<=0){
				printf("Erro número invalido");
			}else {
				for(i=2; i<numPrimo; i++){
					if(numPrimo % i == 0){
						printf("Não é primo");
						break;
					}else if(i == numPrimo-1){
						printf("é primo");
					}
				}
			}
		case 2:
			printf("Saber quantos números existem até X número\n");
		default :
			break;
	}
}

	//Funções de Visual
	
void visuInicio(){
	printf("\tQual função você deseja usar?\n");
	printf("1 - Calculadora\n");
	printf("2 - Matriz\n");
	printf("3 - Primo\n");
	printf("0 - Para fechar o programa\n");
	printf("\n\tOpção escolhida: ");
	scanf("%d", & op);
}

void visuCalculadora1(){
	printf("\t\tCalculadora\n\n");
	printf("Digite um número: ");
	scanf("%f",& num1);
	fflush(stdin);
	printf("\nDigite outro número: ");
	scanf("%f",& num2);
	fflush(stdin);
	
	system("cls");
	printf("\n\t\tCalculadora\n");
	printf("\tOs Números Digitados são: %.2f e %.2f\n\n", num1, num2);
	printf("Escolha a operação a ser calculada:\n");
	printf("'+' - Adição\n");
	printf("'-' - Subtração\n");
	printf("'/' - Divisão\n");
	printf("'*' - Multiplicação\n");
	printf("\n\t\tOperação escolhida: ");
	scanf(" %c",& opCalculadora);
}
