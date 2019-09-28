#include <stdio.h>
#include <stdlib.h>

void troca (int *vetor, int i, int j) {
	int aux = vetor[i];
	vetor[i] = vetor[j];
	vetor[j] = aux;
}

int partition(int *vetor, int p, int r) {
	int j;	
	int pivo = vetor[r], i = p-1;
	
	for(j = p; j <= r - 1; j++) {
		if(vetor[j] <= pivo) {
			i = i + 1;
			troca(vetor, i, j);
		}
	}
	troca(vetor, i+1, r);
	return (i+1);
}

void quickSort (int *vetor, int p, int r) {
	int q;

	if(p < r) {
		q = partition(vetor, p, r);
		quickSort(vetor,p,q-1);
		quickSort(vetor,q+1,r);
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
