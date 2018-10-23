#include<stdio.h>
#include<stdlib.h>
#include "labirinto.h"

LABIRINTO l;
POCISAO inicio;
POCISAO fim;

void lerLabirinto(){
	FILE* f;
	f = fopen("labirinto.txt","r");
	if(f == 0){
		exit(0);
	}
	fscanf(f,"%d %d", &(l.linhas),&(l.colunas));
	alocaLabirinto();
	//leitura
	
	for(int i=0; i < l.linhas; i++){
		fscanf(f, "%s",l.matriz[i]);
		
	}
	fclose(f);
}

void alocaLabirinto(){
	l.matriz = malloc(sizeof(char*) * l.linhas);
	//serve para alocar a memoria
	for(int i = 0; i < l.linhas; i++){
		l.matriz[i] = malloc(sizeof(char)* l.colunas+1);
		//Por causa do \n invisivel no labirinto
	}
}

void imprimeLabirinto(){
	for(int i = 0; i < l.linhas; i++){
		printf("%s\n",l.matriz[i]);

	}
}

void achaInicio(){
	for(int i = 0; i < l.colunas; i++){
		if(l.matriz[i][0] == '.'){
			l.matriz[i][0] = 'X';
			inicio.x = i;
			inicio.y = 0;
			return;

		}
	}
}
void acharFim(){
	for(int i = 0; i < l.colunas; i++){
		if(l.matriz[i][11] == '.'){
			fim.x = i;
			fim.y = 11;
			return;
		}
	}	
}
int chegou(){
	if(inicio.x == fim.x && inicio.y == fim.y){
		return 1;
	}
	return 0;
}
void move(){
	if(l.matriz[inicio.x][inicio.y+1]=='.'){
		l.matriz[inicio.x][inicio.y+1]='X';
		inicio.y++;
		//frente
	}else if(l.matriz[inicio.x-1][inicio.y]=='.'){
		l.matriz[inicio.x-1][inicio.y]='X';
		inicio.x--;
		//abaixo
	}else if(l.matriz[inicio.x+1][inicio.y]=='.'){
		l.matriz[inicio.x+1][inicio.y]='X';
		inicio.x++;
	 	//cima
	}else if(l.matriz[inicio.x][inicio.y-1]=='.'){
		l.matriz[inicio.x][inicio.y-1]='X';
		inicio.y--;
		//atras
	}

}

int main(){
	lerLabirinto();
	acharFim();
	achaInicio();
	imprimeLabirinto();
	while(!chegou()){
		move();
		imprimeLabirinto();
		printf("%i %i\n",inicio.x,inicio.y);
		printf("%i %i\n",fim.x,fim.y);
	system("pause");
}

}