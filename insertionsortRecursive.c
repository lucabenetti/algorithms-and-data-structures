#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *vetor, int n) {
	
	if(n <= 1) return;

	insertionSort(vetor, n-1);

	int aux = vetor[n-1];
	int j = n - 2;

	while(j >= 0 && vetor[j] > aux) {
		vetor[j+1] = vetor[j];
		j--;
	}
	vetor[j+1] = aux;
}

int main () {
	int n, i;
	
	scanf("%d", &n);

	int *vetor = (int*) malloc (n * sizeof(int));

	for(i = 0; i < n; i++) {
		scanf("%d", &vetor[i]);
	}

	insertionSort(vetor, n);

	for(i = 0; i < n; i++) {
		printf("%d ", vetor[i]);
	} printf("\n");

	free(vetor);

	return 0;
}
