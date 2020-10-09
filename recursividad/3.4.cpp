#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>

#define TRUE 1
#define FALSE 0
#define MAXSTRINGSIZE 100

double loge();

int main(){
	double a;
	//llamada de loge
	a=loge();
	printf("El valor de la base 'e' de logaritmos naturales es: %2.16f",a);
	getch();
	return 0;
}

double loge(){
	double en1, delta, fact;
	int n=1.0;
	en1=1.0;
	fact=1.0;
	delta=1.0;
	do{
		en1=en1+delta;
		n++;
		fact=fact*n;
		delta=1.0/fact;
	}while (en1 !=(en1+delta));
	return en1;
}
