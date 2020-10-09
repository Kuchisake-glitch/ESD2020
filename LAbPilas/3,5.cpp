#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>

#define MAXCOLS 80
#define TRUE 1
#define FALSE 0

using namespace std;

struct stackNode{
	int data;
	stackNode *nextPtr;
};

typedef stackNode * STACKNODEPTR;

//Prototipos de las funciones
void postfix(char *, char *);
int isoperand(char);
void popandtest(STACKNODEPTR * , char * , int  * );
int prcd(char,char);
void push(STACKNODEPTR *, char);
char pop(STACKNODEPTR *);
int empty(STACKNODEPTR);

int main(){
	char infix[MAXCOLS];
	char postr[MAXCOLS];
	
	int pos=0;
	
	cout<<"\n Digite una expresion infija: \n";
	while((infix[pos++] = getchar())!= '\n');
	infix[--pos]='\0';
	cout<<"\nLa expresion original infija es: "<<infix<<endl;
	postfix(infix,postr);
	cout<<"\nLa expresion postfija es \t"<<postr<<endl;
	getch();
	return 0;
}

void postfix(char infix[], char postr[]){
	int position, und;
	int outpost = 0;
	char topsymb = '+';
	char symb;
	STACKNODEPTR stackPtr = NULL;
	
		for(position =0; (symb = infix[position])!='\0'; position++){
			if(isoperand(symb)){
				postr[outpost++]=symb;
			}else{
				popandtest(&stackPtr,&topsymb,&und);
				while(!und && prcd(topsymb,symb)){
					postr[outpost++]=topsymb;
					popandtest(&stackPtr, &topsymb,&und);
				}
				if(!und)
					push(&stackPtr,topsymb);
				if(und||(symb!=')' ))
					push(&stackPtr, symb);
			}//Fin del else
		}
		while(!empty(stackPtr)){
			postr[outpost++]=pop(&stackPtr);
		}
		postr[outpost]='\0';
}//fin del postfix

int empty(STACKNODEPTR ps){
	return ps==NULL;
}

int isoperand(char arg){
	if((arg>+'0'&& arg<='9')||(arg>='A'&& arg<='Z')){
		return TRUE;
	}else{
		return FALSE;
	}
}

void popandtest(STACKNODEPTR *ps, char *px, int *pund){
	STACKNODEPTR tempPtr;
	if(empty(*ps)){
		*pund=TRUE;
	}else{
		*pund =FALSE;
		tempPtr=*ps;
		*px=(*ps)->data;
		*ps=(*ps)->nextPtr;
		free(tempPtr);
	}
}//fin del popandtest

int prcd(char a, char b){
	if((a=='*'||a=='/'||a=='+'||a=='-'||a==')'||a=='(')&&(b=='*'||b=='/'||b=='+'||b=='-'||b==')'||b=='(')){
		if(a=='('){
			return FALSE;
		}else{
			if(b=='('){
				return FALSE;
			}else{
				if(a=='*'||a=='/'){
					return TRUE;
				}else{
					if(a==b){
						return TRUE;
					}else{
						if(b==')'){
							return TRUE;
						}else{
							return FALSE;
						}
					}
				}
			}
		}
	}else{
		return -1;
	}
}

void push(STACKNODEPTR *ps, char a){
	STACKNODEPTR newPtr;
	newPtr=(STACKNODEPTR) malloc(sizeof(stackNode));
	if(newPtr!=NULL){
		newPtr->data=a;
		newPtr->nextPtr =*ps;
		*ps=newPtr;
	}else{
		cout<<"No se pudo insertar. No hay memoria disponible\n"<<endl;
	}
}

char pop(STACKNODEPTR *ps){
	STACKNODEPTR tempPtr;
	char a;
	
	tempPtr =*ps;
	a=(*ps)->data;
	*ps=(*ps)->nextPtr;
	free(tempPtr);
	return a;
}
