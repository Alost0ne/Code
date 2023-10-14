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
			printf("\tAdi��o:\n\n");
			printf("A opera��o de %.2f + %.2f � igual a:",num1, num2, num1 + num2);
			break;
		case '-':
			system("cls");
			printf("\tSubtra��o:\n\n");
			printf("A opera��o de %.2f + %.2f � igual a:",num1, num2, num1 - num2);
			break;
		case '/':
			system("cls");
			printf("\tDivis�o:\n\n");
			if(num1 || num2 == 0){
				printf("N�o � possivel dividir por 0.");
				break;
			} else{
				printf("A opera��o de %.2f + %.2f � igual a:",num1, num2, num1 / num2);
			}
			break;
		case '*':
			system("cls");
			printf("\tMultiplica��o:\n\n");
			printf("A opera��o de %.2f + %.2f � igual a:",num1, num2, num1 * num2);
			break;
		default:
			system("cls");
			printf("\tErro: Op��o invalida");
			break;
	}
}

void matriz(){
	printf("Matriz");
}

void primo(){

	printf("\t\tPrimos\n\n");
	printf("O que voc� deseja?\n");
	printf("1 - Saber se um n�mero � primo;\n");
	printf("2 - Saber quantos n�meros primos existem at� o n�mero escolhido;\n");
	printf("3 - Saber quais n�meros primos at� o n�mero escolhido.\n");
	scanf("%d", & opPrimo);
	
	switch(opPrimo){
		case 1:
			printf("\tSaber se um n�mero � primo:\n\n");
			printf("Digite um n�mero: ");
			scanf("%d", & numPrimo);
			if(numPrimo == 1){
				printf("1 � o menor n�mero primo");
			}else if(numPrimo<=0){
				printf("Erro n�mero invalido");
			}else {
				for(i=2; i<numPrimo; i++){
					if(numPrimo % i == 0){
						printf("N�o � primo");
						break;
					}else if(i == numPrimo-1){
						printf("� primo");
					}
				}
			}
		case 2:
			printf("Saber quantos n�meros existem at� X n�mero\n");
		default :
			break;
	}
}

	//Fun��es de Visual
	
void visuInicio(){
	printf("\tQual fun��o voc� deseja usar?\n");
	printf("1 - Calculadora\n");
	printf("2 - Matriz\n");
	printf("3 - Primo\n");
	printf("0 - Para fechar o programa\n");
	printf("\n\tOp��o escolhida: ");
	scanf("%d", & op);
}

void visuCalculadora1(){
	printf("\t\tCalculadora\n\n");
	printf("Digite um n�mero: ");
	scanf("%f",& num1);
	fflush(stdin);
	printf("\nDigite outro n�mero: ");
	scanf("%f",& num2);
	fflush(stdin);
	
	system("cls");
	printf("\n\t\tCalculadora\n");
	printf("\tOs N�meros Digitados s�o: %.2f e %.2f\n\n", num1, num2);
	printf("Escolha a opera��o a ser calculada:\n");
	printf("'+' - Adi��o\n");
	printf("'-' - Subtra��o\n");
	printf("'/' - Divis�o\n");
	printf("'*' - Multiplica��o\n");
	printf("\n\t\tOpera��o escolhida: ");
	scanf(" %c",& opCalculadora);
}
