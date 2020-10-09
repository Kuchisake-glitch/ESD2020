/*Programa que origina una linea de texto y utiliza una pila
para imprimir la linea invertida*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MAXCOLS 80
#define TRUE 1
#define FALSE 0

/*declaracion de la estructura stack*/
struct stack{
	int tope;
	char elementos[MAXCOLS];
};

//Prototipos de las funciones
int empty(struct stack *);
char pop(struct stack *);
void push(struct stack *, char);

int main(){
	//declaracion de variables
	char linea[MAXCOLS];
	char invert[MAXCOLS];
	int pos=0,i;
	struct stack pila;
	
	//Inicializacion de la pila vacia
	pila.tope=-1;
	printf("\nFavor introduzca una linea de caracteres: \n");
	
	//Lectura de caracter a caracter de la linea de caracteres digitados por el usuario
	while((linea[pos++]=getchar())!='\n');
	
	//coloca al final de la cadena linea el simbolo de fin de cadena de caracteres
	linea[--pos]='\0';
	
	//imprime la linea original
	printf("\nLa linea original es: \n \t%s",linea);
	
	//introduce los caracteres de la linea en la pila
	for(i=0;i<pos;i++){
		push(&pila,linea[i]);
	}
	
	//saca  los elementos de la pila y los guarda en el vector invert
	for(i=0;i<pos;i++){
		invert[i]=pop(&pila);	
	}

	//coloca al final de invert la marca de fin de linea
	invert[i]='\0';

	//imprime la linea invertida
	printf("\n\t La linea invertida es: \n\t %s",invert);
	getch();
	return 0;
}

int empty(struct stack *ps){
	return (ps->tope == -1);
}

char pop(struct stack *ps){
	if(empty(ps)){
		printf("Subdesbordamiento de pila\n");
		exit(1);
	}
	return(ps->elementos[ps->tope--]);
}

void push(struct stack *ps, char a){
	if(ps->tope == MAXCOLS - 1){
		printf("Desbordamiento de pila\n");
		exit(1);
	}
	ps->elementos[++ps->tope]=a;
}
