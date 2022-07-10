#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
struct lista
{
	char nomes[100];
} palavra[100000] ;
int main()
{
	clock_t t;
	char des[100];
	long int i, j, verificador;
	long int len2, len1;
	FILE *nomes;
	nomes = fopen("nomes.txt", "r");
	if (!nomes)
	{
		printf ("Erro na abertura do arquivo. Fim de programa.");
		exit (1);
	}

	for(i = 0; i < 100000; i++)
	{
		fgets(palavra[i].nomes, sizeof palavra[i].nomes, nomes);
	}

	printf("Qual nome deseja encontar?\n");
	scanf("%s", des);
	len2 = strlen(des);
	t = clock();
	for(i = 0; i < 100000; i++)
	{
		len1 = strlen(palavra[i].nomes);
		verificador = 0;
		for(j = 0; j < len1; j++)
		{
			if(palavra[i].nomes[j] == des[j])
			{
				verificador = verificador + 1;
			}
			else
			{
				j = len1;
			}
		}
		if(verificador == len2)
		{
			printf("Palavra encontrada na posicao %ld \n", i + 1);
			i = 100000;
		}
	}
	fclose(nomes);
	t = clock() - t;
	printf("Tempo de execucao: %lf", ((double)t) / ((CLOCKS_PER_SEC / 1000)));
	return 0;
}
