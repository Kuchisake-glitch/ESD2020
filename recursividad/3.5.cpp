#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define N 8
#define n (N+1)
#define Ncuadrados N*N
#define True 1
#define False 0

void Caballo(int i, int Posx, int Posy, int *exito);
void PresentaResultado();

//tablero de ajedrez
int Tab[n][n];

//posibles 8 movimientos del caballo
int Movimientos[8][2]={{2,1}, {1,2}, {-1,2}, {-2,1},{-2,-1}, {-1,-2}, {1,-2}, {2,-1}};

main(){
	int solucion;
	
	Tab[1][1]=1;
	Caballo(2,1,1, &solucion);
	if(solucion){
		puts("\n El problema tiene solucion:\n");
		PresentaResultado();
	}else{
		puts("\n No se ha encotrado solucion al problema\n");
	}
	getch();
}

void Caballo(int i, int Posx, int Posy, int *exito){
	int Cx,Cy,Mov;
	*exito=False;
	//inicializacion del conjunto posible de movimientos
	while((Mov<8)&&!(*exito)){
		Cx = Posx+Movimientos[Mov][0];
		Cy = Posy+Movimientos[Mov][1];
		//determina si nuevas coordenadas son aceptables
		if((Cx>=1)&&(Cx<=N)&&(Cy>=1)&&(Cy<=N)&&(Tab[Cx][Cy]==0)){
			Tab[Cx][Cy]=i;
			if(i<Ncuadrados){
				//llamada recursiva a Caballo
				Caballo(i+1, Cx, Cy, exito);
				if(!(*exito)){
					//no hay solucion
					Tab[Cx][Cy]=0;
				}else{
					//hay solucion
					*exito=True;
				}
			}
		}
		Mov++;
	}
}

void PresentaResultado(){
	int i, j;
	for(i=1;i<=N;i++){
		for(j=1;j<=N;j++){
			printf("%d %c",Tab[i][j],(j<N ? ' ': '\n'));
		}
	}
}
