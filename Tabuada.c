#include <stdio.h>

//Funções
void Soma(int N_USU){
	int N_TAB, RES;
	
	for(N_TAB=1; N_TAB <=10; N_TAB++){
		RES = N_USU + N_TAB;
		printf("\n\t%d + %d = %d", N_USU, N_TAB, RES);
	}
}

void Sub(int N_USU){
	int N_TAB, RES;
	
	for(N_TAB=1; N_TAB <=10; N_TAB++){
		RES = N_USU - N_TAB;
		printf("\n\t%d - %d = %d", N_USU, N_TAB, RES);
	}
}

void Mult(int N_USU){
	int N_TAB, RES;
	
	for(N_TAB=1; N_TAB <=10; N_TAB++){
		RES = N_USU * N_TAB;
		printf("\n\t%d * %d = %d", N_USU, N_TAB, RES);
	}
}

void Div(int N_USU){
	int N_TAB;
	float AUX1, AUX2, RES;
	
	for(N_TAB=1; N_TAB <=10; N_TAB++){
		
		if(N_USU % N_TAB == 0){
			RES = N_USU / N_TAB;
			printf("\n\t%d / %d = %.0f", N_USU, N_TAB, RES);
		}else{
			AUX1= (float)N_TAB; //Feito um casting(conversão) de float inteiro para decimal
								//Não poderia ser feito fora do (if) pois não daria 
								//para comparar um inteiro com um decimal.
			RES= N_USU / AUX1;
			printf("\n\t%d / %.0f = %.2f", N_USU, AUX1, RES);	
		}	
	}
}

int main(){
	int N_USU, N_TAB, RES, OP;
	char OPCAO;
	
	do{
		printf("\nDIGITE O SINAL QUE VOCE DESEJA SABER A TABUADA. Ex: +, -, * ou /");
		printf("\nDigite o sinal aqui: ");
		scanf("%s", &OPCAO);
	
		printf("\nQUAL NUMERO VOCE DESEJA SABER A TABUADA?");
		printf("\nDigite o numero aqui: ");
		scanf("%d", &N_USU);
	
		switch(OPCAO){
			case '+': printf("\n   Exibindo Tabuada de soma do: %d", N_USU); Soma(N_USU); break;
			case '-': printf("\n   Exibindo Tabuada de subtracao do: %d", N_USU); Sub(N_USU); break;
			case '*': printf("\n   Exibindo Tabuada de multiplicacao do: %d", N_USU); Mult(N_USU); break;
			case '/': printf("\n   Exibindo Tabuada de divisao do: %d", N_USU); Div(N_USU); break;
		}
		
		printf("\nDESEJA APRENDER OUTRA TABUADA? (1-SIM ou 2-NAO): ");
		scanf("%d", &OP);
	}while(OP < 2);
	
	return 0;
}
