#include <stdio.h>
#define MAX_TAM 30

void RECEBE_CARACTERE(int NUM)
{
	int i, j;
	char carac = 42;
	
	for(i=0; i < NUM; i++)
	{
		printf("%\n", carac);
	}
}

int main()
{
	int i;
	
	for(i=0; i <= MAX_TAM; i++)
	{
		RECEBE_CARACTERE(i);
	}
	return 0;
}
