#include <stdio.h>
#include <time.h>

#define TAM_VETOR 10
#define TAM_ALF 26
#define TAM_SENHA 8

void CABECALHO(){
	printf(" >>>> GERADOR DE SENHAS <<<<");
	printf("\n\t  > v1.0 <");
}
//------------------------------------------------
int GERA_NUMEROS(int NUM){
	int i, VETOR[TAM_VETOR];
	
	for(i=0 ; i < TAM_VETOR; i++){
		VETOR[i] = i;
	}
	return VETOR[NUM];
}
//------------------------------------------------
char GERA_LETRA(int NUM){
	int i;
	char VETOR[TAM_ALF];
	
	for(i=0; i < TAM_ALF; i++){
		VETOR[i] = 'a' + i;
	}
	return VETOR[NUM];
}
//------------------------------------------------
char GERA_NUM_CARACTER(int NUM){
	int i, N = 48;
	char VETOR[TAM_VETOR];
	
	i=0;
	for(; i < TAM_VETOR; i++, N++){
		VETOR[i] = N;
	}
	return VETOR[NUM];
}
//------------------------------------------------
void SENHA_NUMERO(){
	int i, NUM, VETOR[TAM_SENHA];
	
	srand(time(NULL));
	for(i=0; i < TAM_SENHA; i++){
		NUM = rand()%10;
		VETOR[i] = GERA_NUMEROS(NUM);
	}
	// IMPRIMINDO SENHA DE NUMEROS
	printf("\n\tTOKEN SUCCESSFUL: [");
	for(i=0; i < TAM_SENHA; i++){
		printf("%d", VETOR[i]);
	}
	printf("]");
}
//------------------------------------------------
void SENHA_NUM_LET(){
	int i, DECISAO, NUM_1, NUM_2;
	char VETOR[TAM_SENHA];
	
	srand(time(NULL)); // SEMENTE DO TEMPO REAL
	for(i=0; i < TAM_SENHA; i++){

		DECISAO = rand()%10;
		if(DECISAO % 2 == 0){ // PAR >> numeros
			NUM_1 = rand()%10;
			VETOR[i] = GERA_NUM_CARACTER(NUM_1);
		}
	
		else if(DECISAO % 2 != 0){ // IMPAR >> letras
			NUM_2 = rand()%26;
			VETOR[i] = GERA_LETRA(NUM_2);
		}
	}
	printf("\n\tTOKEN SUCCESSFUL: [");
	for(i=0; i < TAM_SENHA; i++){
		printf("%c", VETOR[i]);
	}
	printf("]");
}
//------------------------------------------------
void MENU(){
	int OPCAO;
	do{
		printf("\n\nSelecione uma opcao do menu: \n");
		printf("\n[1]-SENHAS NUMEROS");
		printf("\n[2]-SENHAS LETRAS E NUMEROS");
		printf("\n[3]-LIMPAR TELA");
		printf("\n[4]-SAIR");
		
		printf("\n\nDigite aqui: ");	
		scanf("%d", &OPCAO);
		
		if(OPCAO == 1){
			SENHA_NUMERO();
		}
		else if(OPCAO == 2){
			SENHA_NUM_LET();
		}
		else if(OPCAO == 3){
			system("cls");
		}
		else{
			printf("\n\tO PROGRAMA FOI FINALIZADO!");
		}
	}while(OPCAO != 4);
}
//------------------------------------------------
int main(){
	CABECALHO();
	MENU();
	
	return 0;
}
