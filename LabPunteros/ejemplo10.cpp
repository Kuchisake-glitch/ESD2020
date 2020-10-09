#include<stdio.h>
#include<conio.h>

int main(){
	int mat[]={2,16,-4,29,234,12,0,3},i=0;
	
	puts("Imprimimos las direcciones de memoria y valores contenidos;");
	puts("Direccion de memoria &mat[i] \t\t Contenido mat[i]");
	
	for(i=0;i<8;i++){
		printf("\n\t &mat[%d] = %p \t\t mat[%d] = %d",i,&mat[i],i,mat[i]);
	}
	printf("\n\n Repetimos los resultados empleadno notacion de punteros;\n");
	
	puts("Direccion de memoria mat+i \t\t Contenido *(mat*i)");
	
	for(i=0;i<8;i++){
		printf("\n\t &mat[%d] = %p \t\t *(mat+%d) = %d",i,mat+i,i,*(mat+i));
	}
	
	getch();
	return 0;
}
