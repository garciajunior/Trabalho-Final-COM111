#include <stdio.h>
#include <stdlib.h>
#define MIN 10000


int calcCustoMin(int *ciclo, int m[][10], int tam) {
	int custo = 0;
	int j;
	for (j = 0; j < tam-1; j++){
		
		custo+= m[ciclo[j]][ciclo[j+1]];
	}
	custo += m[ciclo[tam-1]][ciclo[0]];
	return custo;
}

int *troca (int *ciclo, int i, int j) {
	int aux = ciclo[i];
	ciclo[i] = ciclo[j];
	ciclo[j] = aux;
	return ciclo;
}

void forcabruta (int *ciclo, int m[][10], int tam, int pos, int *custoMinimo) {
	if (pos == tam-1) {
		int custo = calcCustoMin(ciclo, m, tam);

		if (custo < *custoMinimo) {
			*custoMinimo = custo;
		}
	}
	else {
		int j;
		for (j = pos; j < tam; j++){
			ciclo = troca (ciclo, pos, j);
			forcabruta (ciclo, m, tam, pos+1, custoMinimo);
			ciclo = troca (ciclo, pos, j);
		}
	}
	return;
}



int main(void){
	int ciclo[10] = {0, 1, 2, 3, 4};
	int c = MIN;
	
	int m[10][10] ={{0, 2, 1, 1, 1, 1, 1, 1, 1, 1},
			        {2, 0, 1, 1, 1, 1, 1, 1, 1, 1},
			        {1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
			        {1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
			        {1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
                    {1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
                    {1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
                    {1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
                    {1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
                    {1, 1, 1, 1, 1, 1, 1, 1, 1, 0},};

	forcabruta (ciclo, m, 10, 0, &c);
	
	printf("%d\n", c);

	return 0;
}
