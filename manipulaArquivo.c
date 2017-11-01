#include <stdio.h>
#include <stdlib.h>
FILE *abreArq (char *nomeArq)
{
	int qtd;// quantidade  de cidades que será visitada pelo caixeiro viajantes
	int i , j;
	int *vet = // recebe o vetor com os nomes da cidade 
	int **matrix // recebe a matriz alocada com os pesos dos caminho de cada cidade

	FILE *arq;
	arq = fopen("r","nomeArq");
	if ( arq == NULL)
	{	
		printf("Nao foi possivel abrir arquivo\n");
		exit(1); // sai do console
	}
	fscanf( arq,"%d", &qtd);
	printf("A quantidade de cidade que sera visitada pelo Caixeiro Viajantes: %d\n",qtd );

	vet    = alocaVet(qtd);
	matriz = alocaMatriz(qtd);
	
	for  ( i = 0; i < qtd;  i++)
	{
		fscan( arq, "%d", vet[i]);
	}
	
	for (i = 0; i < qtd; i++)
	{
		for( j = 0; j < qtd; j++)
		{
			fscanf(arq, "%d", m[i][j]);
		}
	}
	return arq;
		
}
FILE *fechaArq (FILE *arq)
{
	if ( arq  == NULL)
	{
		printf("Nao e possivel fechar arquivo pois nao esta aberto\n");
		exit(1);
	}
	fclose (arq);
	return arq;
}