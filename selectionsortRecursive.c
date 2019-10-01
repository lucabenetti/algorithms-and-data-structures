#include <stdio.h>
#include <stdlib.h>

void selectionSort(int *vetor, int i, int n) {
	int j;
	int aux;
	int min = i;

	for (j = i + 1; j < n; j++) {
		if (vetor[j] < vetor[min])	min = j;
	}

	if(vetor[min] != vetor[i]) {
		aux = vetor[min];
		vetor[min] = vetor[i];
		vetor[i] = aux;
	}
	
	if (i + 1 < n) {
		selectionSort(vetor, i + 1, n);
	}
}

int main() {
	int n;
	int i;

	scanf("%d", &n);

	int *vetor = (int *) malloc (n * sizeof(int));	

	for(i = 0; i < n; i++) {
		scanf("%d", &vetor[i]);	
	}
 
	selectionSort(vetor, 0, n);

	for(i = 0; i < n; i++) {
		printf("%d ", vetor[i]);	
	} printf("\n");
	
	free(vetor);
	return 0;
}
