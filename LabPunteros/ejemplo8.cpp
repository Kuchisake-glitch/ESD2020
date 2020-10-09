#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

/*Ordenar alfabeticamente una lista de cadenas de caracterres, utilizando un arreglo de punteros*/

void reordenar(int n, char*x[]);

int main(){
	int i, n=0;
	char *x[10];
	char y[10][16];
	
	printf("Introducir debajo cada cadena en una linea\n\n");
	printf("Escribir \'FIN' para terminar \n\n");
	
	//Leer de la lista de cadenas de caracteres
	do{
		//reserva de memoria
		x[n]=(char *) malloc(12*sizeof(char));
		printf("cadena %d:",n+1);
		scanf("%s",x[n]);
	}
	while(strcmp(x[n++],"FIN"));
	
	//reordenar la lista de cadenas de caracteres
	reordenar(--n,x);
	
	//escribir la lista reordenada de cadena de caracteres
	printf("\nLista reordenada de cadenas:\n");
	for(i=0;i<n;i++){
		printf("\ncadena %d: %s",i+1,x[i]);
		
	}
	getch();
	return 0;
}

void reordenar(int n, char *x[]){
	char *temp;
	int i, elem;
	
	for (elem=0;elem<n-1;elem++){
		//encontrar la menor de las cadenas restantes
		for(i=elem+1;i<n;++i){
			if(strcmp(x[elem], x[i])>0){
				//intercambiar las dos cadenas
				temp=x[elem];
				x[elem]=x[i];
				x[i]=temp;
			}
		}
	}
	return;
}
