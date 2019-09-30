#include <stdio.h>
#include <stdlib.h>

void troca (int *vetor, int i, int j) {
	int aux = vetor[i];
	vetor[i] = vetor[j];
	vetor[j] = aux;
}

int partition (int *vetor, int inicio, int fim) {
	int j;
	int pivot = vetor[fim];
	int i = inicio - 1;

	for(j = inicio; j <= fim - 1; j++) {
		if(vetor[j] < pivot) {
			i = i + 1;
			troca(vetor, i, j);
		}
	}
	troca(vetor, i+1, fim);
	return (i+1);
}

void quickSort(int *vetor, int inicio, int fim) {
	int meio;

	if (inicio < fim) {
		meio = partition (vetor, inicio, fim);
		quickSort(vetor,inicio, meio - 1);
		quickSort(vetor,meio+1,fim);
	}
}

int main () {
	int n;
	int i;
	
	scanf("%d", &n);

	int *vetor = (int*) malloc (n * sizeof(int));

	for(i = 0; i < n; i++) {
		scanf("%d", &vetor[i]);
	}

	quickSort(vetor, 0, n-1);

	for(i = 0; i < n; i++) {
		printf("%d ", vetor[i]);
	}	printf("\n");

	free (vetor);

	return 0;
}
