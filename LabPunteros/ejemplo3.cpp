#include<stdio.h>

int main(){
	static int x[10]={20,21,22,23,24,25,26,27,28,29};
	int i;
	
	puts("Escribimos el array:");
	for(i=0;i<=9;i++){
		//escribe un elemento del array
		printf("\t i = %d \t x[i]= %d \t *(x+i) =%d", i,x[i],*(x+i));
		
		//escribe la correspondiente direccion del array
		printf("\t &x[i] = %x \t x+i = %x \n", &x[i],(x+i));
	}
	
	return 0;
}
