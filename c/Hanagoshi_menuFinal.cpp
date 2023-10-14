//Menu com Arquivos
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

//ponteiros
FILE *arquivo;
FILE *arquivoCompra;
FILE *temp;

//variaveis area cliente
int escolha=1, acao;
char cliente[200];
char nome[30], idade[3], tel[14], cpf[14],endereco[100],dados[5][100];
int id=1,validacao=1, tamcliente=0;
int campo=0, conteudo=0, cont;

//variaveis area de compra
char compra[500],mostraCompra[500];
char tam[10],cor[10];
int quant,numtam,numcor,tamcompra=0;
float preco=0, precototal=0;

//funções decoração layout
void ArtTelaInicio();
void ArtMenuPrincipal();
void ArtCadastroCliente();
void ArtVisualizacaoCadastro();
void ArtEdicaoCadastro();
void ArtExclusaoCadastro();
void ArtVisualizacaoProdutos();
void ArtRealizarCompra();
void ArtRelatorio();
void ArtFinalizacao();

//funções secundárias
void escolhaproduto();
void alteraEndereco();

//funções
void cadastrar();
void listar();
void visualizarCadastro();
void alterar();
void excluir();
void comprar();
void relatorio();

//função principal
main(){
	setlocale(LC_ALL,"Portuguese_Brazil");

	ArtTelaInicio();
	scanf("%d",&escolha);

	while(escolha>0){ 
		system("cls");
		ArtMenuPrincipal();
		scanf("%d",&acao);
		
		system("cls");
		switch(acao){
			case 1:
				cadastrar();
				break;
			case 2:
				visualizarCadastro();
				break;
			case 3:
				alterar();
				break;
			case 4:
				excluir();
				break;
			case 5:
			    ArtVisualizacaoProdutos();
			    break;
			case 6:
				comprar();
				break;
			case 7:
				relatorio();
				break;
		    }
			printf("\n\nDigite [1] para voltar ao Menu Principal ou [0] para sair do programa.");
			printf("\nSelecione a opção: ");
			scanf("%d",&escolha);
    }
    ArtFinalizacao();
    system("pause");
}

void cadastrar(){
	ArtCadastroCliente();
	printf("Bem-vindo(a) ao Cadastro de Clientes! Por favor, preencha os campos a seguir para realizar seu cadastro.\n\n\n");
	
	arquivo = fopen("ClientesHanagoshi.txt", "a");
	
	printf("Nome: ");
	fflush(stdin);
	gets(nome);
	printf("Idade: ");
	fflush(stdin);
	gets(idade);
	printf("Celular [(99)999999999]: ");
	fflush(stdin);
	gets(tel);
	printf("CPF (somente números): ");
	fflush(stdin);
	gets(cpf);
	printf("Endereço: ");
	fflush(stdin);
	gets(endereco);
	
	fprintf(arquivo,"%s|%s|%s|%s|%s\n",nome,idade,tel,cpf,endereco);
	fclose(arquivo);
	
	printf("\nCADASTRO FINALIZADO COM SUCESSO!\n");
}

void listar() {	
	arquivo = fopen("ClientesHanagoshi.txt","r");
	id=1;
	printf("\t\t\t\t====== CLIENTES CADASTRADOS ======\n");
	//separa o cadastro de cliente em campos (nome,idade,celular,cpf e endereço)
	while(fgets(cliente,200,arquivo) != NULL) {
		campo=0;
		conteudo=0;
		tamcliente = strlen(cliente);
		for(cont=0;cont<tamcliente;cont++) {
			if(cliente[cont] != '|') {
				dados[campo][conteudo] = cliente[cont];
				conteudo++;
			} else {
				dados[campo][conteudo] = '\0';
				campo++;
				conteudo=0;
			}
			dados[campo][conteudo] = '\0';
		}
		printf("\n\t\t\t\t  ID: %d\t Nome: %s",id,dados[0]); // mostra apenas o ID e o nome
		id++;
	}
	printf("\n\n\t\t\t\t==================================");
	fclose(arquivo);
}

void visualizarCadastro() {
	ArtVisualizacaoCadastro();
	printf("Bem-vindo(a) à Visualização de Cadastros! Aqui você consegue visualizar seus dados cadastrais pesquisando por seu ID.\n");
	printf("Caso você não se lembre de seu ID, consulte a lista de clientes cadastrados!\n\n");
	
	listar();
	
	printf("\n\n\nPara consultar seus dados cadastrais completos, digite seu ID: ");
   	scanf("%d",&id); 

	arquivo = fopen("ClientesHanagoshi.txt","r");

	system("cls");
	ArtVisualizacaoCadastro();	
	validacao=1;
	while(fgets(cliente,200,arquivo)!= NULL){
		if (id == validacao) {
			campo=0;
			conteudo=0;
			//separa o cadastro de cliente em campos (nome,idade,celular,cpf e endereço)
			tamcliente = strlen(cliente);
			for(cont=0;cont<tamcliente;cont++){
				if(cliente[cont] != '|') {
					dados[campo][conteudo] = cliente[cont];
					conteudo++;
				} else {
					dados[campo][conteudo] = '\0';
					campo++;
					conteudo=0;
				}
				dados[campo][conteudo] = '\0';
			}
	        printf("DADOS CADASTRAIS COMPLETOS:\n\nNome: %s\nIdade: %s\nCelular: %s\nCPF: %s\nEndereço: %s",dados[0],dados[1],dados[2],dados[3],dados[4]);
		}
		validacao++;
	}
	fclose(arquivo);
}

void alterar(){
	ArtEdicaoCadastro();
	printf("Bem-vindo(a) à Edição de Cadastro! Aqui você consegue alterar seus dados cadastrais através de seu ID.\n");
	printf("Caso você não se lembre de seu ID, consulte a lista de clientes cadastrados!\n\n");
	listar(); 
	printf("\n\n\nInforme o ID que deseja alterar: ");
	scanf("%d",&id);
	
	temp = fopen("Temporario.txt","a");
	arquivo = fopen("ClientesHanagoshi.txt","r");
	
	validacao=1;
	while(fgets(cliente,200,arquivo)!= NULL){
		if (id == validacao){
			//separa o cadastro de cliente em campos (nome,idade,celular,cpf e endereço)
			campo =0;
			conteudo=0;
			tamcliente = strlen(cliente);
			for(cont=0;cont<tamcliente;cont++){
				if(cliente[cont] != '|'){
					dados[campo][conteudo] = cliente[cont];
					conteudo++;
				} else {
					dados[campo][conteudo] = '\0';
					campo++;
					conteudo=0;
				}
				dados[campo][conteudo] = '\0';
			}
			
			system("cls");
			ArtEdicaoCadastro();
			printf("SEUS DADOS CADASTRAIS:\n");
			printf("[1] Nome: %s\n[2] Idade: %s\n[3] Celular: %s\n[4] CPF: %s\n[5] Endereço: %s",dados[0],dados[1],dados[2],dados[3],dados[4]);
			printf("\n\nQual dado deseja alterar?");
			printf("\nSelecione a opção: ");
			scanf("%d",&escolha);
					
			printf("\nInsira o dado correto\n");
			
			if(escolha == 5){
				printf("Endereço: ");
				fflush(stdin);
				gets(dados[4]);
				fprintf(temp,"%s|%s|%s|%s|%s\n",dados[0],dados[1],dados[2],dados[3],dados[4]);
			} else {
			switch(escolha){
				case 1:
					printf("Nome: ");
					fflush(stdin);
					gets(dados[0]);
					break;
				case 2:
					printf("Idade: ");
					fflush(stdin);
					gets(dados[1]);
					break;
				case 3:
					printf("Celular: ");
					fflush(stdin);
					gets(dados[2]);
					break;
				case 4:
					printf("CPF: ");
					fflush(stdin);
					gets(dados[3]);
					break;		
			}
			fprintf(temp,"%s|%s|%s|%s|%s",dados[0],dados[1],dados[2],dados[3],dados[4]);
		    }
		    
		} else {
			//copia o cadastro que não é para ser alterado
			fprintf(temp,"%s",cliente);
		}
		validacao++;
	}
	fclose(arquivo);
	fclose(temp);
	remove("ClientesHanagoshi.txt");
	rename("Temporario.txt","ClientesHanagoshi.txt");
	
	printf("\nCADASTRO ALTERADO COM SUCESSO!");
}

void excluir(){
	ArtExclusaoCadastro();
	printf("Bem-vindo(a) à Exclusão de Cadastro! Aqui você consegue excluir dados cadastrais através do ID.\n");
	printf("Caso você não se lembre do ID, consulte a lista de clientes cadastrados!\n\n");
	listar();
	printf("\n\n\nInforme o ID que deseja excluir: ");
	scanf("%d",&id);
	
	arquivo = fopen("ClientesHanagoshi.txt","r");
	temp = fopen("Temporario.txt","w");
	
	validacao=1;
	while(fgets(cliente,200,arquivo)!= NULL){
		if (id != validacao){
			fprintf(temp,"%s",cliente);
		}
		validacao++;
	}
	fclose(arquivo);
	fclose(temp);
	remove("ClientesHanagoshi.txt");
	rename("Temporario.txt","ClientesHanagoshi.txt");
	
	printf("\nCADASTRO EXCLUIDO COM SUCESSO!\n");
}

void comprar(){
	ArtRealizarCompra();
	printf("Bem-vindo(a) à seção de compras! Verifique seu ID abaixo!\n\n");
	listar();
	printf("\n\nDigite seu ID para prosseguir: ");
	scanf("%d",&id);
	
	validacao=1;
	arquivo = fopen("ClientesHanagoshi.txt","r");
	//separa o cadastro de cliente em campos (nome,idade,celular,cpf e endereço)
	while(fgets(cliente,200,arquivo)!= NULL){
		campo=0;
		conteudo=0;
		if (id == validacao){
			tamcliente = strlen(cliente);
			
			for(cont=0;cont<tamcliente;cont++){
				if(cliente[cont] != '|'){
					dados[campo][conteudo] = cliente[cont];
					conteudo++;
				} else {
					dados[campo][conteudo] = '\0';
					campo++;
					conteudo=0;
				}
				dados[campo][conteudo] = '\0';
			}
			
	        system("cls");
	        ArtRealizarCompra();
	     	printf("Bem vindo, %s! Antes de prosseguir, precisamos confirmar seu endereço!",dados[0]);
	     	printf("\nEndereço cadastrado: %s",dados[4]);
	     	printf("\n\nDigite [1] para confirmar endereço ou [2] para alterá-lo.");
	     	printf("\nSelecione a opção: ");
	     	scanf("%d",&escolha);
     	
     	    arquivoCompra = fopen("ComprasHanagoshi.txt","a");
	     	if(escolha == 2){
	     		fclose(arquivo);
	     		alteraEndereco();
	     		
		        fprintf(arquivoCompra,"*Cliente: %s   Endereço: %s\n",dados[0],dados[4]);
			} else {
		    	fprintf(arquivoCompra,"*Cliente: %s   Endereço: %s",dados[0],dados[4]);
		    }
		    system("cls");
		    
		    preco = 0;
		    precototal = 0;

			do {
				escolhaproduto();
			    ArtRealizarCompra();
			    printf("DESEJA ADICIONAR MAIS UM ITEM?\nDigite [1] para adicionar e [2] para finalizar:");
			    scanf("%d",&escolha);
			    system("cls");
	        } while(escolha == 1);
	        
	        fprintf(arquivoCompra,"~ Preço total: %.2f",precototal);
	        fprintf(arquivoCompra,"\n\n");
	        fclose(arquivoCompra);
	        
	        system("cls");
	        ArtRealizarCompra();
	        printf("COMPRA FINALIZADA COM SUCESSO! MUITO OBRIGADO PELA PREFERÊNCIA!\n\n");
	        printf("Essa foi sua compra:\n");
	        arquivoCompra = fopen("ComprasHanagoshi.txt","r");
	        
			//aribui a ultima compra salva no arquivo na variavel mostraCompra
			while(fgets(compra,500,arquivoCompra)!= NULL){
	        	if(compra[0] == '~'){
	        		strcpy(mostraCompra, compra);
				}
	        }
	        
	        //formata a exibicao da compra
	        tamcompra = strlen(mostraCompra);
	        for(cont=0;cont<tamcompra;cont++){
	        	if(mostraCompra[cont]=='~'){
	        		mostraCompra[cont] = '\n';
				}
				printf("%c",mostraCompra[cont]);
			}
			fclose(arquivoCompra);
	        printf("\n\nOs produtos serão enviados para %s",dados[4]);
		}
        validacao++;
    }
    fclose(arquivo);
}

void relatorio() {
	ArtRelatorio();
	arquivoCompra = fopen("ComprasHanagoshi.txt","r");
	
	if (arquivoCompra != NULL) {
		while (fgets(compra,500,arquivoCompra)!= NULL) { 
			tamcompra = strlen(compra);
			for(cont=0;cont<tamcompra;cont++) {
				if (compra[cont] == '~') {
					compra[cont] = '\n';
				}
				printf("%c", compra[cont]);
			}
		} 
	} else {
		printf("Problema ao abrir o arquivo.");
	}
	fclose(arquivoCompra);
}

//função secundaria da escolha de produtos
void escolhaproduto(){
	ArtRealizarCompra();
	printf("Selecione o tamanho do vaso que deseja:\n");
	printf("[1] Tamanho pequeno	(R$100,00)\n");
	printf("[2] Tamanho médio	(R$200,00)\n");
	printf("[3] Tamanho grande	(R$300,00)\n");
	printf("\nSelecione a opção: ");
	scanf("%d",&numtam);
	switch(numtam){
	    case 1:
	    	strcpy (tam, "Pequeno" );
	    	preco = 100.00;
	    	break;
	    case 2:
	    	strcpy (tam, "Médio" );
	    	preco = 200.00;
	    	break;
	    case 3:
	    	strcpy (tam, "Grande" );
	    	preco = 300.00;
	    	break;
	}
				
	printf("\nSelecione a cor do vaso que deseja:\n");
	printf("[1] Marrom\n");			
	printf("[2] Amarelo\n");			
	printf("[3] Azul\n");			
	printf("[4] Verde\n");			
	printf("[5] Cinza\n");			
	printf("\nSelecione a opção: ");
	scanf("%d",&numcor);
	switch(numcor){
	    case 1:
	    	strcpy (cor, "Marrom" );
	    	break;
	    case 2:
	    	strcpy (cor, "Amarelo" );
	    	break;
	    case 3:
	    	strcpy (cor, "Azul" );
	    	break;
	    case 4:
	    	strcpy (cor, "Verde" );
	    	break;
	    case 5:
	    	strcpy (cor, "Cinza" );
	    	break;
	}											
	printf("\nQuantas unidades deseja comprar? ");			
	scanf("%d",&quant);
	
	preco = preco*quant;
	precototal = precototal + preco;
	fprintf(arquivoCompra,"~ Tamanho: %s|Cor: %s|Quantidade: %d|Preco: %.2f ",tam,cor,quant,preco);
	system("cls");
}

//função secundaria para alterar endereço
void alteraEndereco(){
	temp = fopen("Temporario.txt","w");
	arquivo = fopen("ClientesHanagoshi.txt","r");
	
	validacao=1;
	while(fgets(cliente,200,arquivo)!= NULL){
		if (id == validacao){
			printf("\nDigite o novo endereço para a compra: ");
     		fflush(stdin);
     		gets(dados[4]);
     		
     		fprintf(temp,"%s|%s|%s|%s|%s\n",dados[0],dados[1],dados[2],dados[3],dados[4]);
        } else {
            fprintf(temp,"%s",cliente);
	    }
	    validacao++;
	}
	fclose(arquivo);
	fclose(temp);
	remove("ClientesHanagoshi.txt");
	rename("Temporario.txt","ClientesHanagoshi.txt");
		
}

void ArtTelaInicio(){
	printf("      __.     ,                .                                        .       ,           .        .        ,    \n");
	printf("     (__ * __-+- _ ._ _  _.   _| _    _. _ ._ _ ._ ._. _.   _    _. _. _| _. __-+-._. _    _| _    _.|* _ ._ -+- _ \n");
	printf("     .__)|_)  | (/,[ | )(_]  (_](/,  (_.(_)[ | )[_)[  (_]  (/,  (_.(_](_](_]_)  | [  (_)  (_](/,  (_.||(/,[ ) | (/,\n");
	printf("		  		   		|     \n");
	printf("  ==================================================================================================================== \n\n");
	printf("	.---.  .---.    ____    ,---.   .--.   ____      .-_'''-.       ,-----.       .-'''-. .---.  .---..-./`)  \n");
	printf("	|   |  |_ _|  .'  __ `. |    \\  |  | .'  __ `.  '_( )_   \\    .'  .-,  '.    / _     \\|   |  |_ _|\\ .-.') \n");
	printf("	|   |  ( ' ) /   '  \\  \\|  ,  \\ |  |/   '  \\  \\|(_ o _)|  '  / ,-.|  \\ _ \\  (`' )/`--'|   |  ( ' )/ `-' \\ \n");
	printf("	|   '-(_{;}_)|___|  /  ||  |\\_ \\|  ||___|  /  |. (_,_)/___| ;  \\  '_ /  | :(_ o _).   |   '-(_{;}_)`-'`\"  \n");
	printf("	|      (_,_)    _.-`   ||  _( )_\\  |   _.-`   ||  |  .-----.|  _`,/ \\ _/  | (_,_). '. |      (_,_) .---.  \n");
	printf("	| _ _--.   | .'   _    || (_ o _)  |.'   _    |'  \\  '-   .': (  '\\_/ \\   ;.---.  \\  :| _ _--.   | |   |  \n");
	printf("	|( ' ) |   | |  _( )_  ||  (_,_)\\  ||  _( )_  | \\  `-'`   |  \\ `\"/  \\  ) / \\    `-'  ||( ' ) |   | |   |  \n");
	printf("	(_{;}_)|   | \\ (_ o _) /|  |    |  |\\ (_ o _) /  \\        /   '. \\_/``\".'   \\       / (_{;}_)|   | |   |  \n");
	printf("	'(_,_) '---'  '.(_,_).' '--'    '--' '.(_,_).'    `'-...-'      '-----'      `-...-'  '(_,_) '---' '---'  \n\n\n");
	printf("			   ================================================================\n");
	printf("			    Created by Alexandre | Isabella | Rafael | Rodney | Victoria\n");
	printf("			   ================================================================\n\n\n");
	printf("					  ====================================\n");
	printf("					      Pressione [1] para prosseguir\n");
	printf("					      Pressione [0] para sair\n");
	printf("					  ====================================\n\n\n");
	printf("					          Selecione a opção: ");	
}

void ArtMenuPrincipal() {
	printf("\t\t    __  __                ___     _         _            _ \n");
	printf("\t\t   |  \\/  |___ _ _ _  _  | _ \\_ _(_)_ _  __(_)_ __  __ _| |\n");
	printf("================== | |\\/| / -_) ' \\ || | |  _/ '_| | ' \\/ _| | '_ \\/ _` | | ==================\n");
	printf("\t\t   |_|  |_\\___|_||_\\_,_| |_| |_| |_|_||_\\__|_| .__/\\__,_|_|\n");
	printf("\t\t\t\t\t\t\t     |_|          \n\n\n");
	printf("		==== ÁREA DO CLIENTE ====	    ==== ÁREA DE COMPRA =====\n\n\n");
	printf("		= [1] Cadastrar cliente		    = [5] Visualizar produtos\n");
	printf("		= [2] Visualizar cadastros	    = [6] Comprar produtos\n");
	printf("		= [3] Editar cadastro		    = [7] Relatório de vendas\n");
	printf("		= [4] Excluir cadastro\n\n");
	printf("==============================================================================================\n\n");
	printf("		Selecione uma entre as opções acima para prosseguir\n");
	printf("		Selecione a opção: ");
}

void ArtCadastroCliente(){
	printf("   ___         _         _                _        ___ _ _         _       \n");
	printf("  / __|__ _ __| |__ _ __| |_ _ _ ___   __| |___   / __| (_)___ _ _| |_ ___ \n");
	printf(" | (__/ _` / _` / _` (_-<  _| '_/ _ \\ / _` / -_) | (__| | / -_) ' \\  _/ -_)\n");
	printf("  \\___\\__,_\\__,_\\__,_/__/\\__|_| \\___/ \\__,_\\___|  \\___|_|_\\___|_||_\\__\\___|\n\n\n\n");
}

void ArtVisualizacaoCadastro() {
	printf(" __   ___              _ _             /\\/|         _        ___         _         _              \n");
	printf(" \\ \\ / (_)____  _ __ _| (_)_____ _ __ |/\\/ ___   __| |___   / __|__ _ __| |__ _ __| |_ _ _ ___ ___\n");
	printf("  \\ V /| (_-< || / _` | | |_ / _` / _/ _` / _ \\ / _` / -_) | (__/ _` / _` / _` (_-<  _| '_/ _ (_-<\n");
	printf("   \\_/ |_/__/\\_,_\\__,_|_|_/__\\__,_\\__\\__,_\\___/ \\__,_\\___|  \\___\\__,_\\__,_\\__,_/__/\\__|_| \\___/__/\n");
	printf("                                   )_)                                                            \n\n\n");
}

void ArtEdicaoCadastro() {
	printf("  ___    _ _     /\\/|         _        ___         _         _           \n");
	printf(" | __|__| (_)__ |/\\/ ___   __| |___   / __|__ _ __| |__ _ __| |_ _ _ ___ \n");
	printf(" | _|/ _` | / _/ _` / _ \\ / _` / -_) | (__/ _` / _` / _` (_-<  _| '_/ _ \\\n");
	printf(" |___\\__,_|_\\__\\__,_\\___/ \\__,_\\___|  \\___\\__,_\\__,_\\__,_/__/\\__|_| \\___/\n");
	printf("             )_)                                               \n\n\n");
}

void ArtExclusaoCadastro() {
	printf("  ___        _           /\\/|         _        ___         _         _           \n");
	printf(" | __|_ ____| |_  _ ___ |/\\/ ___   __| |___   / __|__ _ __| |__ _ __| |_ _ _ ___ \n");
	printf(" | _|\\ \\ / _| | || (_-</ _` / _ \\ / _` / -_) | (__/ _` / _` / _` (_-<  _| '_/ _ \\ \n");
	printf(" |___/_\\_\\__|_|\\_,_/__/\\__,_\\___/ \\__,_\\___|  \\___\\__,_\\__,_\\__,_/__/\\__|_| \\___/\n\n\n\n");
}

void ArtVisualizacaoProdutos(){
	printf("	  _____     _         _           _       ___             _      _          \n");
	printf("	 |_   _|_ _| |__  ___| |__ _   __| |___  | _ \\_ _ ___  __| |_  _| |_ ___ ___\n");
	printf("========   | |/ _` | '_ \\/ -_) / _` | / _` / -_) |  _/ '_/ _ \\/ _` | || |  _/ _ (_-< ========\n");
	printf("	   |_|\\__,_|_.__/\\___|_\\__,_| \\__,_\\___| |_| |_| \\___/\\__,_|\\_,_|\\__\\___/__/\n\n\n\n");
	printf("	  	==== OPÇÕES DE TAMANHO ====		==== OPÇÕES DE CORES ====\n\n\n");
	printf("	  	= Pequeno	[R$100,00]		= Marrom\n");
	printf("	  	= Médio		[R$200,00]		= Amarelo\n");
	printf("	  	= Grande	[R$300,00]		= Azul\n");
	printf("							= Verde\n");
	printf("							= Cinza\n\n");
	printf("=============================================================================================\n\n");
	printf("Deseja realizar uma compra? Volte para o Menu Principal e selecione a opção Comprar produtos\n");
}

void ArtRealizarCompra() {
	printf("  ___          _ _                ___                         \n");
	printf(" | _ \\___ __ _| (_)_____ _ _ _   / __|___ _ __  _ __ _ _ __ _ \n");
	printf(" |   / -_) _` | | |_ / _` | '_| | (__/ _ \\ '  \\| '_ \\ '_/ _` |\n");
	printf(" |_|_\\___\\__,_|_|_/__\\__,_|_|    \\___\\___/_|_|_| .__/_| \\__,_|\n");
	printf("                                               |_|                     \n\n\n");
}

void ArtRelatorio() {
	printf("  ___     _      _    __     _          _      __   __           _         \n");
	printf(" | _ \\___| |__ _| |_ /_/ _ _(_)___   __| |___  \\ \\ / /__ _ _  __| |__ _ ___\n");
	printf(" |   / -_) / _` |  _/ _ \\ '_| / _ \\ / _` / -_)  \\ V / -_) ' \\/ _` / _` (_-<\n");
	printf(" |_|_\\___|_\\__,_|\\__\\___/_| |_\\___/ \\__,_\\___|   \\_/\\___|_||_\\__,_\\__,_/__/\n\n");
}

void ArtFinalizacao(){
	system("cls");
	printf("\n\n	    ,-----.     _______   .-------.   .-./`)   .-_'''-.      ____     ______         ,-----.   .---.         \n");
	printf("	  .'  .-,  '.  \\  ____  \\ |  _ _   \\  \\ .-.') '_( )_   \\   .'  __ `. |    _ `''.   .'  .-,  '. \\   /         \n");
	printf("	 / ,-.|  \\ _ \\ | |    \\ | | ( ' )  |  / `-' \\|(_ o _)|  ' /   '  \\  \\| _ | ) _  \\ / ,-.|  \\ _ \\|   |         \n");
	printf("	;  \\  '_ /  | :| |____/ / |(_ o _) /   `-'`\"`. (_,_)/___| |___|  /  ||( ''_'  ) |;  \\  '_ /  | :\\ /          \n");
	printf("	|  _`,/ \\ _/  ||   _ _ '. | (_,_).' __ .---. |  |  .-----.   _.-`   || . (_) `. ||  _`,/ \\ _/  | v           \n");
	printf("	: (  '\\_/ \\   ;|  ( ' )  \\|  |\\ \\  |  ||   | '  \\  '-   .'.'   _    ||(_    ._) ': (  '\\_/ \\   ;_ _          \n");
	printf("	 \\ `\"/  \\  ) / | (_{;}_) ||  | \\ `'   /|   |  \\  `-'`   | |  _( )_  ||  (_.\\.' /  \\ `\"/  \\  ) /(_I_)         \n");
	printf("	  '. \\_/``\".'  |  (_,_)  /|  |  \\    / |   |   \\        / \\ (_ o _) /|       .'    '. \\_/``\".'(_(=)_)        \n");
	printf("	    '-----'    /_______.' ''-'   `'-'  '---'    `'-...-'   '.(_,_).' '-----'`        '-----'   (_I_)         \n\n\n\n");
	printf("				AGRADECEMOS SUA VISITA E CONFIANÇA! VOLTE SEMPRE!\n\n\n\n");
	printf("Projeto criado por:\n");
	printf("Alexandre Bastos, Isabella Oshima, Rafael Santos, Rodney Ramos, Victoria Fujii.\n\n\n");
}

