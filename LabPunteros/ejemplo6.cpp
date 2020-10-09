#include<conio.h>
#include<stdio.h>

int main(){
	char *nombre = "PEPE PEREZ";
	int i=0;
	
	do
		printf("%c", *(nombre+i));
	while(*(nombre+i++)); //postincremento de i, para cambiar valor de control
	puts(" ");
	puts(nombre);
	getch();
	return 0;
}
