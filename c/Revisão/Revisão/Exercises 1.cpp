
#include <stdio.h>
#include <stdlib.h>

FILE *fp;
FILE *temp;
char data[80];
char name[32];
char quantity[8];
char price[8];
char category[32];

	//Write a code in order to create a .txt file containing a header for a product's name, amount, price and category
	//Write a code in order to write a product info on the first empy line of the previously created file
	//Write a code in order to print all the products entered with their respective lines
	//Write a code in order to delete a product based on its line

void printFile() {
    fp = fopen("any.txt", "r");
 
    if (!fp) {
        printf("Can't open file\n");
	} else {
 		
        int line=0, i=0;
        int size = 0;
 
        while (fgets(data, 80, fp) != NULL) {
 			printf("%d %s", line, data);
			line++;
		}
        fclose(fp);
        printf("\n");
    }
}

void createFile() {
	fp = fopen("any.txt", "w");
	
	if (!fp) {
        printf("Can't open file\n");
	} else {
		fprintf(fp, "Name\tAmount\tPrice\tCategory");
	}
	fclose(fp);
}

void writeProduct() {
	fp = fopen("any.txt", "a+");
 
    if (!fp) {
        printf("Can't open file\n");
	} else {
		
		int line = 1;
		while (fgets(data, 80, fp) != NULL) {
			line++;
		}
		
	    printf("\nEnter product name: ");
		gets(name);
	    printf("\nEnter quantity in stock: ");
	    gets(quantity);
	    printf("\nEnter product price: ");
	    gets(price);
	   	printf("\nEnter product category: ");
	   	gets(category);
	    
	    fprintf(fp,"\n%s\t%s\t%s\t%s", name, quantity, price, category);
	 
	    printf("\nNew product added to stock!\n");
	}
	fclose(fp);
}

void deleteProduct() {
	
	int line;
	int reg = 0;
	int  size = 0;
	
	printf("Enter the product line you wish to delete: ");
	scanf("%d",&line);
	
	fp = fopen("any.txt","r");
	temp = fopen("temp.txt","w");
	
	while(fgets(data, 100 , fp) != NULL){
		if(reg != line+1){
			fprintf(temp,"%s",data);	
		} 
		reg++;
	}
	fclose(fp);
	fclose(temp);
	remove("any.txt");
	rename("temp.txt","any.txt");
	printf("\nProduct updated!\n");
}
	
	void mainMenu() {
	printf("1 - Start file\n");
	printf("2 - Create a product\n");
	printf("3 - Print file\n");
	printf("4 - Delete product\n");
	printf("Choose: ");
}

int main () {
	
	char option = '.';
	mainMenu();
	scanf(" %c", &option);
	
	switch (option) {
		case '1':
			
			createFile();
			break;
						
		case '2':
			
			writeProduct();
			break;
			
		case '3':
			
			printFile();
			break;
			
		case '4':
			
			deleteProduct();
			break;

	}
}




