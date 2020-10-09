#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>

#define TRUE 1
#define FALSE 0
#define MAXSTRINGSIZE 100

int getsymb(char[], int, int*);
void readstr(char *, int *);
int expr(char *, int, int *);
int term(char *, int, int *);
int factor(char *, int, int *);

 main(){
	char str[MAXSTRINGSIZE];
	int length, pos;
	
	readstr(str, &length);
	pos =0;
	if(expr(str,length, &pos) == TRUE && pos >= length){
		printf("%s\n","valida");
	}else{
		printf("%s\n","invalida");
	}
	getch();
}

void readstr(char *str, int * longitud){
	printf("digite a expresion a evaluar:\n ");
	gets(str);
	*longitud = strlen(str);
}
int getsymb(char str[], int length, int *ppos){
	char c;
	if(*ppos<length){
		c=str[*ppos];
	}else{
		c=' ';
	}
	(*ppos)++;
	return (c);
}

int expr(char str[], int length, int *ppos){
	//busca un termino
	if(term(str,length,ppos)== FALSE){
		return FALSE;
	}
	if(getsymb(str, length, ppos)!= '+'){
		(*ppos)--;
		return TRUE;
	}
	return (term(str, length,ppos));
}
int term(char str[],int length,int *ppos){
	if(factor(str, length, ppos)==FALSE){
		return (FALSE);
	}
	if(getsymb(str,length,ppos)!='*'){
		(*ppos)--;
		return (TRUE);
	}
		return (factor(str, length,ppos));
}

int factor(char str[], int length, int *ppos){
	int c;
	if((c=getsymb(str,length,ppos))!='('){
		return(isalpha(c));
	}
	return(expr(str,length,ppos)&& getsymb(str,length,ppos)==')');
}
