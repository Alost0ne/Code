#include<stdio.h>
#include<locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	FILE* Abrir;
	// Matriz 4 x 10 para armazenar os refrigerantes
	char r[4][10]; 
	int i;
	// abertura de arquivo com o ponteiro
	Abrir = fopen("NotaFiscal.txt", "w"); 
	

	printf("Escolha 4 refrigerantes para comprar:\n");
	/// for para recolher os valores e armazenar na matriz r[i]
	for(i = 0; i < 4; i++){
		printf("\nRefri %d: ", i+1);
		scanf("%s", r[i]);
	}
	// verificação se deu tudo certo para gravar os dados no arquivo
	if(Abrir == NULL){
		printf("ERRO! Ocorreu um erro ao manipular o arquivo!");
	}
	
	else{
		fprintf(Abrir,"====NOTA FISCAL====\n");
		for(i = 0; i < 4; i++){
			fprintf(Abrir, "%s\n", r[i]);
		}
		printf("Dados gravados com sucesso!");
		fclose(Abrir);
	}
	
	return 0;
}
