#include <stdio.h>
#include <stdlib.h>

void merge(int *vetor, int inicio, int meio, int fim) {
	int com1 = inicio;
	int com2 = meio+1;
	int comAux = 0;
	int *vetAux = (int*) malloc ((fim-inicio+1) * sizeof(int));

	while(com1 <= meio && com2 <= fim) {
		if(vetor[com1] <= vetor[com2]) {
			vetAux[comAux] = vetor[com1];
			com1++;
		}
		else{
			vetAux[comAux] = vetor[com2];
			com2++;
		}
		comAux++;
	}

	while (com1 <= meio) {
		vetAux[comAux] = vetor[com1];
		comAux++;
		com1++;
	}

	while (com2 <= fim) {
		vetAux[comAux] = vetor[com2];
		comAux++;
		com2++;
	}

	for(comAux = inicio; comAux <= fim; comAux++) {
		vetor[comAux] = vetAux[comAux - inicio];
	}

	free(vetAux);
}

void mergeSort(int *vetor, int inicio, int fim) {
	int meio;
	
	if(inicio < fim) {
		meio = (inicio + fim)/2;

		mergeSort(vetor,inicio,meio);
		mergeSort(vetor,meio+1,fim);
		merge(vetor,inicio,meio,fim);

	}
}


int main () {
	int n, i;

	scanf("%d", &n);

	int *vetor = (int*) malloc (n * sizeof(int));
		
	for(i = 0; i < n; i++) {
		scanf("%d", &vetor[i]);
	}

	mergeSort(vetor, 0, n-1);

	for(i = 0; i < n; i++) {
		printf("%d ", vetor[i]);
	} printf("\n");
	
	free(vetor);

	return 0;
}
