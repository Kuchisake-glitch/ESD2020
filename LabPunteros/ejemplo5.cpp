#include<conio.h>
#include<stdio.h>

int main(int argc, char** argv){
	int mat[]= {1,2,3,4}, *pmat, i;
	
	printf("\n Empleamos notacion decimal:\n");
	printf("Hacemos que el puntero seniale al primer elemento del array: pmat = mat");
	
	pmat = mat;
	
	printf("\nComprobamos los valores: ");
	printf("\nDireccion de inicio del array: mat =%u",&mat[0]);
	printf("\nDireccion de pmat: &pmat = %u",&pmat);
	printf("\nImprimimos las direcciones de memoria;\n");
	
	for(i=0;i<4;i++){
		printf("\n &mat[%u] = %u (pmat+%u) = %u",i,&mat[i],i,(pmat+i));
		printf("\n    mat[%u] = %u *(pmat+%u)= %u",i,mat[i],i,*pmat+i);
	}
	
	getch();
	return 0;
}
