#include <stdio.h>
#include<conio.h>

int main(){
	//declaraciones
	int a;
	int *punt;//declaracion de puntero
	
	a=57;
	punt=&a; //asignacion de direccion de puntero
	
	//impresiones
	
	printf("\t a = %d",a);//imprime valor de variable
	printf("\n\t &a = %x",&a);//imprime la direccion apuntada, en hexadecimal
	printf("\n\t punt = %x",punt);//imprime la direccion guardada
	printf("\n\t *punt = %d",*punt);//imprime el contenido de la direccion apuntada
	printf("\n\t tamanio del puntero = %d",sizeof(punt));
	getch();
	return 0;
}
