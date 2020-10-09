#include<conio.h>
#include<stdio.h>
#define FILAS 3
#define COLUMNAS 2

int main(){
	int i;
	char mat[FILAS][COLUMNAS]= {{1,2},{3,4},{5,6}};
	
	puts("\tImprime como array:");
	
	for(i=0; i<FILAS*COLUMNAS;i++){
		printf("\t %d\n", (*mat)[i]);
	}
	
	puts("\tImprimimos utilizando punteros:");
	
		for(i=0; i<FILAS*COLUMNAS;i++){
			printf("\t %d\n", (**mat+i));
		}
	
	getch();
	return 0;
}
