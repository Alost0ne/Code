#include<stdio.h>
#include<locale.h>

main(){
    setlocale(LC_ALL,"portuguese");

    float num1, num2;
    char op;

    printf("\nDigite um n�mero:");
    scanf("%f", & num1);

    printf("Digite outro n�mero:");
    scanf("%f", & num2);

    printf("\nAgora escolha uma opera��o:\n");
    printf("'+' Para adi��o\n'-' Para Subtra��o\n'x' Para multiplica��o\n'/' Para divis�o");
    printf("\nEscolha: ");
    scanf(" %c", & op);

    switch(op){
        case '+' :
        system ("cls");
        printf("\tAdi��o:\n");
        printf("O resultado de %.2f %c %.2f �: %.2f",num1 ,op , num2, num1 + num2);
        break;

        case '-' :
        system ("cls");
        printf("\tSubtra��o:\n");
        printf("O resultado de %.2f %c %.2f �: %.2f",num1 ,op , num2, num1 - num2);
        break;

        case '*' :
        system ("cls");
        printf("\tMultiplica��o:\n");
        printf("O resultado de %.2f %c %.2f �: %.2f",num1 ,op , num2, num1 * num2);
        break;

        case '/' :
        system ("cls");
        printf("\tDivis�o:\n");
        printf("O resultado de %.2f %c %.2f �: %.2f",num1 ,op , num2, num1 / num2);
        break;
    }
    printf("\n");
    system("pause");

    return 0;
}
