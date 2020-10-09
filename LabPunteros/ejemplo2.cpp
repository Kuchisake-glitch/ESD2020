#include <stdio.h>
#include<conio.h>

int main(){
	char carac='A', *r;
	int a=12,b=45,c;
	int *p,*q;
	
	printf("\t Direccion de a=%p\n",&a);
	printf("\t Direccion de b=%p\n",&b);
	printf("\t a = %d ^ b = %dn",a,b);
	printf("\t Direccion de caract = %p\n",&carac);
	printf("\t carac = %c\n",carac);

	printf("\t Valor ASCII de carac = %d\n",carac);
	printf("\t Direccion de p = %p\n",&p);
	printf("\t Direccion de q = %p\n",&q);
	printf("\t Direccion de r = %p\n",&r);
	p =&a;
	q =&b;
	r =&carac;
	
	printf("\t el puntero p apunta a la direccion: %p\n",p);
	printf("\t Y su contenido es: %d\n",*p);
	printf("\t El puntero q apunta a la direccion: %p\n",q);
	printf("\t Y su contenido es: %d\n",*q);
	printf("\t El puntero r apunta a la direccion: %p\n",r);
	printf("\t Y el contenido de *r es:%d\n",*r);
	printf("\t Cp,p caracter ASCII, *r contiene: %c\n",*r);
	
	
	getch();
}
