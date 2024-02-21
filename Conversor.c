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
			printf("\nDigite o valor em DOLAR que deseja converter: ");
			scanf("%f", &moeda);
			printf("\nDigite a cotacao atual da moeda selecionada: ");
			scanf("%f", &cotacao);
			
			res = moeda*cotacao;
			printf("\n\t%.2f Dolares(USA) equivalem a %.2f Reais", moeda, res);
			break;
		}
		
		case 2: {
			printf("\nDigite o valor em EURO que deseja converter: ");
			scanf("%f", &moeda);
			printf("\nDigite a cotacao atual da moeda selecionada: ");
			scanf("%f", &cotacao);
			
			res = moeda*cotacao;
			printf("\n\t%.2f Euro equivalem a %.2f Reais", moeda, res);
			break;
		}
		
		case 3: {
			printf("\nDigite o valor em DOLAR que deseja converter: ");
			scanf("%f", &moeda);
			printf("\nDigite a cotacao atual da moeda selecionada: ");
			scanf("%f", &cotacao);
			
			res = moeda*cotacao;
			printf("\n\t%.2f Dolares(USA) equivalem a %.2f Euros", moeda, res);
			break;
		}
		default: printf("\n\tOPCAO INVALIDA!\n");
	}
}

void convTemp() {
	int opcao=0;
	float celsius, fahrenheit, res;
	
	printf("\nSELECIONE A TEMPERATURA QUE DESEJA CONVERTER: ");
	printf("\n-------------------------");
	printf("\n[1]-CELSIUS PARA FAHRENHEIT \n[2]-FAHRENHEIT PARA CELSIUS");
	printf("\n-------------------------");
	printf("\nDIGITE AQUI: ");
	scanf("%d", &opcao);
	
	if(opcao == 1){
		printf("\nDigite a temperatura em celsius: ");
		scanf("%f", &celsius);
		
		fahrenheit = (celsius * 9/5) + 32;
		printf("\n%.0f graus celcius, equivalem a %.1f graus fahrenheit.", celsius, fahrenheit);
	}
	else if(opcao == 2){
		printf("\nDigite a temperatura em fahrenheit: ");
		scanf("%f", &fahrenheit);
		
		celsius = (fahrenheit - 32)* 5/9;
		printf("\n%.1f graus fahrenheit, equivalem a %.1f graus celsius.", fahrenheit, celsius);
	}else{
		printf("\n\tOPCAO INVALIDA!");
	}
}

void entradaDados(){
	int opcao;
	
	printf("\nDIGITE AQUI: ");
	scanf("%d", &opcao);
	
	switch(opcao){
		case 1: convMoeda(); break;
		case 2: convTemp(); break;
		case 3: break;
		default: printf("\n\tOPCAO INVALIDA!");
	}
}

int main(){
	//CONTINUAR FUNÇÃO 3 COVERTER MEDIDAS: Km para Metros, Metros para Centímetros, centímetros para milímetros.
	cabecalho();
	menu();
	entradaDados();
}
