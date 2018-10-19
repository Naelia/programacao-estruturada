#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "FORCA.h"

#define TAMANHO_PALAVRA 20
char palavrasecreta[TAMANHO_PALAVRA];
char chutes[26];
int tentativas = 0;
int totalDeErros=6;
int errosAtuais=0;

void abertura() {
	printf("/****************/\n");
	printf("/ Jogo de Forca */\n");
	printf("/****************/\n\n");
}

void chuta() {
	char chute;
	printf("Qual letra? ");
	scanf(" %c", &chute);

	verificaLetra(chute);

	
}
void verificaLetra(char l){
	if(l >= 65 && l <= 90){
		chutes[tentativas] = l;
		tentativas++;
		
	}else{
		printf("Nao sao permitidas letras minusculas!\n");
		
	}

}

int chutou(char letra){
	int achou = 0;

	for(int j = 0; j < tentativas; j++) {
		if(chutes[j] == letra) {
			achou = 1;
			break;
		}
	}
	return achou;
}
void nivelDeDificuldade(){
	int nivel;

	printf("\nQual nivel de dificuldade deseja escolher?\n");
	printf("1) Facil 2) Medio 3) Dificil\n");
	scanf("%d", &nivel);

	if(nivel == 1){
		totalDeErros = 9;
	}else if(nivel == 2){
		totalDeErros = 5;
	}else if(nivel == 3){
		totalDeErros = 3;
	}else{
		printf("Numero invalido!\n");
		printf("Por favor digite um numero valido!\n");
		nivelDeDificuldade();
	}
	
}

void desenhaforca(){

	int erros = numeroChutesErrados();
	if(totalDeErros == 9){
		printf("  ___________       \n");
		printf(" |/          |      \n");
		printf(" |          %c%c%c  \n", (erros>0 ? '(' : ' '), (erros>1 ? '_' : ' '),(erros>2 ? ')' : ' '));
		printf(" |          %c%c%c  \n", (erros>4 ? '/' : ' '),(erros>3 ? '|' : ' '), (erros>5 ? '\\' : ' '));
		printf(" |           %c    \n", (erros>6 ? '|' : ' '));
		printf(" |          %c %c  \n", (erros>7 ? '/' : ' '),(erros>8 ? '\\' : ' '));
		printf(" |                  \n");
		printf("_|____              \n");

		printf("voce ja deu %d chutes\n", tentativas );
		for(int i = 0; i < strlen(palavrasecreta); i++) {
			if(chutou(palavrasecreta[i])) {
				printf("%c ", palavrasecreta[i]);
			} else {
				printf("_ ");

			}
		}
	} else if (totalDeErros == 5 ){
		printf("  ___________       \n");
		printf(" |/          |      \n");
		printf(" |          %c%c%c  \n", (erros>0 ? '(' : ' '), (erros>0 ? '_' : ' '),(erros>0 ? ')' : ' '));
		printf(" |          %c%c%c  \n", (erros>2 ? '/' : ' '),(erros>1 ? '|' : ' '), (erros>2 ? '\\' : ' '));
		printf(" |           %c    \n", (erros>3 ? '|' : ' '));
		printf(" |          %c %c  \n", (erros>4 ? '/' : ' '),(erros>4 ? '\\' : ' '));
		printf(" |                  \n");
		printf("_|____              \n");	

			printf("voce ja deu %d chutes\n", tentativas );
		for(int i = 0; i < strlen(palavrasecreta); i++) {
			if(chutou(palavrasecreta[i])) {
				printf("%c ", palavrasecreta[i]);
			} else {
				printf("_ ");
			}
		}
	}else if(totalDeErros == 3){
		printf("  ___________       \n");
		printf(" |/          |      \n");
		printf(" |          %c%c%c  \n", (erros>0 ? '(' : ' '), (erros>0 ? '_' : ' '),(erros>0 ? ')' : ' '));
		printf(" |          %c%c%c  \n", (erros>1 ? '/' : ' '),(erros>1 ? '|' : ' '), (erros>1 ? '\\' : ' '));
		printf(" |           %c    \n", (erros>1 ? '|' : ' '));
		printf(" |          %c %c  \n", (erros>2 ? '/' : ' '),(erros>2 ? '\\' : ' '));
		printf(" |                  \n");
		printf("_|____              \n");

			printf("voce ja deu %d chutes\n", tentativas );
		for(int i = 0; i < strlen(palavrasecreta); i++) {
			if(chutou(palavrasecreta[i])) {
				printf("%c ", palavrasecreta[i]);
			} else {
				printf("_ ");
			}
		}

	}
}


void escolhepalavra(){
	FILE* f;
	f = fopen("Dicinario.txt","r");
	if (f==0){
		printf("ERRO! Problema no arquivo!\n");
		exit(1);
	}
	int quantidadeDePalavras;
	fscanf(f,"%d",&quantidadeDePalavras);

	srand(time(0));
	int numeroSortedo = rand() % quantidadeDePalavras;
	for(int i=0;i<=numeroSortedo;i++){
		fscanf(f,"%s",palavrasecreta);
	}
	fclose(f);
} 

int letraExiste(char letra){
	for(int j=0; j <= strlen(palavrasecreta);j++){
		if(palavrasecreta[j]==letra) {
			return 1;
		}
	}
	return 0;		
}




int numeroChutesErrados(){
	int erros= 0;
	for(int i = 0; i <= tentativas; i++) {
		int existe=0;
		if(!letraExiste(chutes[i])){
			erros++;	
		}
	}

	return erros;
}

int enforcou(){
	return numeroChutesErrados() >= totalDeErros;
}

int acertou(){
	for (int i = 0; i < strlen(palavrasecreta); i++){
		if (!chutou(palavrasecreta[i])){
			return 0;
		}
	}
	return 1;	
}

int contemPalavra(char* palavra){
	FILE* f;
	int totalDePalavras;
	char* recebePalavra;
	fopen("Dicinario.txt","r+");
	fscanf(f, "%d", &totalDePalavras);
	fscanf(f, "%d", &recebePalavra);
	for(int i = 0; i < totalDePalavras; i++){
		printf("AQUI");	
		fscanf(f,"%s",&recebePalavra);
		printf("%s", recebePalavra);
		if(strcmp(recebePalavra,palavra) == 0){
			return 1;
		}
	}
	return 0;
}


void adicionapalavra(){
	char escolha;
	printf("Deseja adicionar uma nova palavra ao nosso dicionario?(S/N)\n");
	scanf(" %c",&escolha);
	if(escolha=='S'){
		char novapalavra[TAMANHO_PALAVRA];
		printf("Digite a palavra a ser inserida!");
		scanf("\n%s",novapalavra);

		if(contemPalavra(novapalavra)){
			printf("\nDesculpe %s\nEssa palavra ja existe em nosso banco de dados\n\n");
			system("pause");
			system("cls");
		}else{
			for(int i = 0; novapalavra[i]; i++){
				if(novapalavra[i] < 65 || novapalavra[i] > 90){
					while(novapalavra[i] < 65 || novapalavra[i] > 90){
					printf("Nome invalido, por favor so use letras maiusculas\n");
					scanf("%s", novapalavra);
					
					if(contemPalavra(novapalavra)){
					printf("\nDesculpe %s\nEssa palavra ja existe em nosso banco de dados\n\n");
					system("pause");
					system("cls");
					return;
					}
				}
			}
		}
	}
	FILE* f;

		f = fopen("Dicinario.txt","a");
		fprintf(f, "%s\n", novapalavra);
	    fclose(f);
	    
	   	    f = fopen("Dicinario.txt", "w");
	    fprintf(f, "%04d\n", novapalavra);
	    fclose(f);
	}
}

int main() {

	nivelDeDificuldade();
	escolhepalavra();


	abertura();

	do {
		
		desenhaforca();
		


		printf("\n");
		

		chuta();


	} while (!acertou() && !enforcou());
	if(acertou()){
		adicionapalavra();	
	}
	
	if(acertou()==1){
		printf("***************************\n");
		printf("***************************\n");
		printf("***********(\\_/)***********\n");
		printf("***********(*-*)***********\n");
		printf("******<[:]PARABENS[:]>*****\n");
		printf("**********(.)(.)***********\n");
		printf("***************************\n");
		printf("***************************\n");
	}else{
		desenhaforca();

	}
}