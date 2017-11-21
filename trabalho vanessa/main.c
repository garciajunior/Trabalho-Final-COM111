/* Gera todas as permutações */

#include <stdio.h>
#include <stdlib.h>
#define MINCUSTO 10000

int mat[10][10] = { {0, 2, 1, 1, 1, 1, 1, 1, 1, 2},
		            {2, 0, 1, 1, 1, 6, 1, 1, 1, 2},
		            {1, 1, 0, 1, 1, 1, 1, 1, 1, 2},
		            {1, 1, 1, 0, 7, 1, 1, 1, 1, 2},
		            {1, 1, 1, 1, 0, 1, 1, 1, 1, 2},
                    {1, 1, 9, 1, 1, 0, -1, 1, 1, 2},
                    {1, 1, 1, 1, 1, -1, 0, 1, 1, 2},
                    {1, 1, 1, 4, 1, 1, 1, 0, 1, 2},
                    {1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
                    {2, 2, 2, 2, 2, 2, 2, 2, 1, 0},};


void troca(int vetor[], int i, int j)
{
	int aux = vetor[i];
	vetor[i] = vetor[j];
	vetor[j] = aux;
}

void permuta(int vetor[], int inf, int sup, int *conta)
{
    int i;
	if(inf == sup)
	{
		int contaaux = 0;
		for(i = 0; i < sup; i++){
			contaaux += mat[vetor[i]][vetor[i+1]];
		}
		contaaux += mat[vetor[sup]][vetor[0]];
		if (contaaux < *conta)
			*conta = contaaux;
	}
	else
	{

		for(i = inf; i <= sup; i++)
		{
			troca(vetor, inf, i);
			permuta(vetor, inf + 1, sup, conta);
			troca(vetor, inf, i); // backtracking
		}
	}
}

void forcaBruta (int *v, int pos, int tam) {
	int *vaux = (int *) malloc (sizeof(int)*(tam+1));
	int i, j=0;
	for (i = pos; i<= tam; i++) {
		vaux[i-pos] = v[i];
		j++;
	}
	for (i = 0; i<pos; i++) {
		vaux[i+j] = v[i];
	}
	int conta = 10;
	permuta (vaux, 1, tam, &conta);
	printf ("%d", conta);

}

int main(int argc, char *argv[])
{
	int v[] = {0, 1, 2, 3, 4 ,5 ,6 , 7, 8, 9, 10, 11 ,12};
	int tam_v = sizeof(v) / sizeof(int);

	forcaBruta(v, 0, tam_v - 1);

	return 0;
}
