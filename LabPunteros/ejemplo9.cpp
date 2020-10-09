#include<stdio.h>
#include<conio.h>

int main(){
	int i, j;
	int *p[4]; //array de punteros
	int **px=p;//px es un puntero a un puntero
	
	printf("Introduzca 4 valores enteros;\n");
	for(i=0; i<4; i++){
		scanf("%d", &px[i]);
	}
	for(i=0;i<4;i++)
	{
		printf("%7d",px[i]); //Imprime como array
		printf("%7d",*(px+i)); //Imprime como puntero
		printf("\n");
	}
	getch();
	return 0;
}
