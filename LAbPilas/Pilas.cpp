#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define STACKSIZE 100

/*Definicion de tipos de datos*/

typedef char STACKELEMENT;
typedef struct{
	int top;
	STACKELEMENT items[STACKSIZE];
}STACK;

//Prototipos de funciones de la pila

void Clear(STACK *);
int Empty(STACK *);
int Full(STACK *);
STACKELEMENT Pop(STACK *);
void Push(STACK *, STACKELEMENT);

int main(){
	STACKELEMENT a;
	int p,i;
	STACK b;
	STACK *c=&b;
	b.top=-1;
	
	//da la oportunidad de introducir o sacar elementos de la pila 5 veces
	for(i=0;i<=4;i++){
		printf("Introducir o sacar de la pila 1/2 ");
		scanf("%d",&p);
		fflush(stdin);
		if(p==1){
			printf("Elemento a introducir ");
			scanf("%c",&a);
			fflush(stdin);
			Push(c,a);
			printf("Elemento introducido con exito\n");
			getch();
		}
		else{
			if(p==2){
				if(Empty(c)){
					printf("Error: pila vacia.\n");
					getch();
					exit(1);
				}
				else{
					a=Pop(c);
					printf("Elemento sacado de la pila: %c\n",a);
					getch();
				}
			}
			else{
				printf("La proxima vez debe digitar 1 o 2");
				getch();
			}
		}
	}
	return 0;
}

//Limpia la pila
void Clear(STACK * ps){
	ps->top=-1;
}

//Verifica si la pila esta vacia
int Empty(STACK * ps){
	if(ps->top==-1)
		return(TRUE);
	else
		return(FALSE);
}

//Verifica si la pila esta llena, si ya no se pueden introducir mas elementos en el
int Full(STACK * ps){
		if(ps->top== STACKSIZE -1)
		return(TRUE);
	else
		return(FALSE);
}

//Introduce un elemento en la pila
void Push(STACK * ps, STACKELEMENT x){
	if(Full(ps)){
		printf("%s", "Pila desbordada");
		exit(1);
	}
	else
	ps->items[++(ps->top)]=x;
}

//Quita un elemento de la pila y lo devuelve
STACKELEMENT Pop(STACK * ps){
	if(Empty(ps)){
		printf("%s","Pila subdesbordada");
		exit(1);
	}
	return (ps->items[(ps->top)--]);
}
