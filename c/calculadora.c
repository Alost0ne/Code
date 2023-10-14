#include<stdio.h>
#include<locale.h>

main(){
    setlocale(LC_ALL,"portuguese");

    float num1, num2;
    char op;

    printf("\nDigite um número:");
    scanf("%f", & num1);

    printf("Digite outro número:");
    scanf("%f", & num2);

    printf("\nAgora escolha uma operação:\n");
    printf("'+' Para adição\n'-' Para Subtração\n'x' Para multiplicação\n'/' Para divisão");
    printf("\nEscolha: ");
    scanf(" %c", & op);

    switch(op){
        case '+' :
        system ("cls");
        printf("\tAdição:\n");
        printf("O resultado de %.2f %c %.2f é: %.2f",num1 ,op , num2, num1 + num2);
        break;

        case '-' :
        system ("cls");
        printf("\tSubtração:\n");
        printf("O resultado de %.2f %c %.2f é: %.2f",num1 ,op , num2, num1 - num2);
        break;

        case '*' :
        system ("cls");
        printf("\tMultiplicação:\n");
        printf("O resultado de %.2f %c %.2f é: %.2f",num1 ,op , num2, num1 * num2);
        break;

        case '/' :
        system ("cls");
        printf("\tDivisão:\n");
        printf("O resultado de %.2f %c %.2f é: %.2f",num1 ,op , num2, num1 / num2);
        break;
    }
    printf("\n");
    system("pause");

    return 0;
}
