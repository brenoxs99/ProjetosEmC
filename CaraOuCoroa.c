#include <stdio.h>
#include <time.h>

void GeraResultado(){
	int NUM;
	
	srand(time(NULL));
	
	NUM = rand()%999;
	
	if(NUM % 2==0){
		printf("\tDEU CARA!\n");
	}else{
		printf("\tDEU COROA!\n");
	}
}
<<<<<<< HEAD
=======

>>>>>>> origin/main
void Menu(){
	int op;
	
	do{
		printf("\nSelsecione uma opcao:");
		printf("\n   [1]-JOGAR MOEDA\n   [2]-SAIR\n");
		printf("\n   DIGITE AQUI: ");
		scanf("%d", &op);
		
		if(op == 1){
			GeraResultado();
		}
		else if(op == 2){
			printf("\n   O PROGRAMA FOI FINALIZADO!");
		}
		else{
			do{
				printf("\n   A OPCAO QUE VOCE DIGITOU E INVALIDA!\n");
				printf("\nSelsecione uma opcao:");
				printf("\n   [1]-JOGAR MOEDA\n   [2]-SAIR\n");
				printf("\n   DIGITE AQUI: ");
				scanf("%d", &op);
				
				if(op == 1){
					GeraResultado();
				}
				else if(op == 2){
					printf("O PROGRAMA FOI FINALIZADO!");
				}
			}while(op != 1 && op != 2);
		}
	}while(op < 2);
}

int main(){
	Menu();
	return 0;
}
