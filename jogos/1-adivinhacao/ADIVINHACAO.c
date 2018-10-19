#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int main (){

	setlocale(LC_ALL, "Portuguese");

	printf("\n Jogo de adivinhacao \n");
	int pontos = 1000;
	int segundos = time (NULL);
	srand(segundos);

	int numeroSecreto = rand ()%101;
	int tentativas = 1;
	int chute,ganhou = 0;
	int nivel;
	int totalDeTentativas;

	printf("Digite o nivel que deseja jogar:\n");
	printf("1:Facil.\n");
	printf("2:Medio.\n");
	printf("3:Dificil.\n");
	scanf("%i",&nivel);

	switch (nivel){
		case 1:
		totalDeTentativas = 20;
		break;

		case 2:
		totalDeTentativas = 15;
		break;
	
		default:
		totalDeTentativas = 5;
		break;
	}
		do{


		printf("Sua pontuacao e:%i\n",pontos);
		printf("Seu numero de tentativas e:%i\n",totalDeTentativas);
		printf("\n Vezes Jogadas:%i \n", tentativas);
		printf("\n Digite o seu palpite do chute: ");
		scanf("%d", & chute);
		
		if(chute <0){
			printf("Voce não pode digitar numeros negativos!\n");
			continue;
		}
		
		
		
		
		printf("\n Seu chute e:%d ",chute);
		

		if(chute==numeroSecreto){

			printf("\n Voce acertou! o numero secreto e: %i",numeroSecreto);
			ganhou=1;	
			break;	
	
		} else {
	
			printf("\n Voce errou!");

			if(chute>numeroSecreto){

				printf("O numero secreto e menor que o numero chutado!");

			} else {

				printf("O numero secreto e maior que o numero chutado!");

			}
		}
		tentativas++;

		pontos = pontos - abs(numeroSecreto - chute)/2;

	}while(totalDeTentativas>=tentativas);
	

	printf("sua pontuação final foi: %i\n",pontos);
	
	printf("\n Fim de Jogo!");
	
	printf("\n Vlw! Flw!");
	
	return 0;
}