#include<stdio.h>
#include<conio.h>

int main(){
	int x[2][3],fil,col;
	
	puts("Llenamos el array");
	for(fil=0;fil<2;fil++){
		for(col=0;col<3;col++){
			printf("x[%d][%d] = ",fil,col);
			scanf("%d",&x[fil][col]);
		}
		puts("Imprimimos usando un puntero a un grupo de arrays:");
		
		puts("PRIMERA FILA:");
		for(col=0;col<3;col++){
			printf(" %d", (*x)[col]);
		}
		
		printf("\nSEGUNDA FILA:\n");
		for(col=0;col<3;col++){
			printf(" %d",(*(x+1))[col]);
		}
	}
	getch();
	return 0;
}
