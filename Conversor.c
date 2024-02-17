#include <stdio.h>
// Desenvolverei aqui um menu de tres opções
// Conversor de temperaturas
// coversor de moeda

void cabecalho(){
	printf("<----- Conversor Vbeta ----->\n");
}

void menu(){
	printf("\nINFORME UMA OPCAO: ");
	printf("\n-------------------------");
	printf("\n[1]-Converter de Moeda \n[2]-Converter Temperatura \n[3]-Coverter Medida");
	printf("\n-------------------------");
}

void entradaDados(){
	int opcao;
	
	printf("\nDIGITE AQUI: ");
	scanf("%d", &opcao);
	
	switch(opcao){
		case 1: convMoeda(); break;
		case 2: break;
		case 3: break;
		default: printf("\nOPCAO INVALIDA!");
	}
}

void convMoeda(){
	float moeda, cotacao, res;
	int opcao;
	
	printf("\nSELECIONE A MOEDA QUE DESEJA CONVERTER: ");
	printf("\n-------------------------");
	printf("\n[1]-DOLAR(USA) PARA REAL \n[2]-EURO PARA REAL \n[3]-DOLAR(USA) PARA EURO");
	printf("\n-------------------------");
	printf("\nDIGITE AQUI: ");
	scanf("%d", &opcao);
	
	switch(opcao){
		case 1: {
			printf("\nDigite o valor em DOLAR que deseja converter:");
			scanf("%f", &moeda);
			printf("\nDigite a cotacao atual da moeda selecionada:");
			scanf("%f", &cotacao);
			
			res = moeda*cotacao;
			printf("\n\t%.2f Dolares(USA) equivalem a %.2f Reais", moeda, res);
			break;
		}
		
		case 2: {
			printf("\nDigite o valor em EURO que deseja converter:");
			scanf("%f", &moeda);
			printf("\nDigite a cotacao atual da moeda selecionada:");
			scanf("%f", &cotacao);
			
			res = moeda*cotacao;
			printf("\n\t%.2f Euro equivalem a %.2f Reais", moeda, res);
			break;
		}
		
		case 3: {
			printf("\nDigite o valor em DOLAR que deseja converter:");
			scanf("%f", &moeda);
			printf("\nDigite a cotacao atual da moeda selecionada:");
			scanf("%f", &cotacao);
			
			res = moeda*cotacao;
			printf("\n\t%.2f Dolares(USA) equivalem a %.2f Euros", moeda, res);
			break;
		}
	}
}
int main(){
	// CONTINUAR FUNÇÃO 2- CONVERTER TEMPERATURA
	cabecalho();
	menu();
	entradaDados();
}
