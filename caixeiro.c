#include <stdio.h>
#include <stdlib.h>
#include "caixeiro.h"
FILE *abreArq (char *nomeArq, int *vet, int **mat, int *tam)
{
	int i,j;
	FILE *arq;
	arq = fopen(nomeArq, "r");
	if ( arq == NULL)
	{	
		printf("Nao foi possivel abrir arquivo\n");
		exit(1); // sai do console
	}
	fscanf( arq,"%d", tam);
	printf("A quantidade de cidade que sera visitada pelo Caixeiro Viajantes: %d\n",*tam );


	
	for  ( i = 0; i < *tam;  i++)
	{
		fscanf( arq, "%d", &vet[i]);		
	}
	
	for (i = 0; i < *tam; i++)
	{
		for( j = 0; j < *tam; j++)
		{
			fscanf(arq, "%d", &mat[i][j]);
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

int **alocaMatriz( int *tam)
{
    
	int **mat, i;
	mat = (int**) malloc( *tam * sizeof(int*));
	if ( !mat)
	{
		printf("Nao e possivel alocar matriz\n");
		exit(1);
	}
	for( i = 0; i < *tam;  i++)
	{
		mat[i] = (int*)malloc(*tam * sizeof(int));
	}
	return mat;
}
int  *alocaVetor(int *tam)
{
   
	int *vet;
	vet = (int *) malloc ( *tam * sizeof(int));
	if ( !vet)
	{
		printf("Nao foi possivel alocar memoria.\n");
		exit(1);
	}
	return vet;
}

int calcCustoMin(int *ciclo, int **m, int *tam) {
	int custo = 0;
	int j;

	for (j = 0; j < *tam-1; j++)
	{		
		custo+= m[ciclo[j]][ciclo[j+1]]; // calcula o custo de cada vertice
	}	
									 // porem o  ultimo custo nao eh calculado pelo pelo looping
	custo += m[ciclo[*tam-1]][ciclo[0]]; // calcula o ultimo o custo do ultimo vertice
	return custo; // retorna o custo calculado 
}

int *troca (int *ciclo, int i, int j) {
	int aux = ciclo[i];
	ciclo[i] = ciclo[j];
	ciclo[j] = aux;
	return ciclo;
}

void forcaBruta (int *ciclo, int **mat, int *tam, int pos, int *custoMinimo) {
	int custo = 0; // custo calculado para cada vertice do caminho
	int j; 	
	
	if (pos == *tam-1)
	{
		custo = calcCustoMin(ciclo, mat, tam);
		printf(" O custo eh %d\n",custo );
		if (custo < *custoMinimo) {
			*custoMinimo = custo;
		}
	}
	else 
	{
		
		for (j = pos; j < *tam; j++)
		{
			ciclo = troca (ciclo, pos, j); // responsavel por fazer a troca dos vertices de cidades
			forcabruta (ciclo, mat, tam, pos+1, custoMinimo);// 
			ciclo = troca (ciclo, pos, j);
		}
	}
	return;
}



