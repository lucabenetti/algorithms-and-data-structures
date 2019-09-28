#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *vetor, int n) {
	int i, aux;

	if(n == 1) return;

		for(i = 0; i < n; i++) {
			if(vetor[i] > vetor[i+1]) {
				aux = vetor[i];
				vetor[i] = vetor[i+1];
				vetor[i+1] = aux;
			}
		}

	bubbleSort(vetor, n-1);
}

int main () {

	int i, n;

	scanf("%d", &n);

	int *vetor = (int*) malloc (n* sizeof(int));

	for(i = 0; i < n; i++) {
		scanf("%d", &vetor[i]);
	}

	bubbleSort(vetor, n);

	for(i = 0; i < n; i++) {
		printf("%d ", vetor[i]);
	} printf("\n");
	
	free(vetor);
	
	return 0;
}
