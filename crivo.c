#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {
	int nMax;

	int i, j;

	scanf("%d", &nMax);

	int nLimit = sqrt(nMax);

	int *numbers = (int *) calloc ((nMax + 1), sizeof(int));

	for(i = 2; i <= nLimit; i++) {
		for(j = 2; j <= nMax; j++) {
			numbers[i*j] = 1;
		}
	}

	for(i = 2; i <= nMax; i++) {
		if(numbers[i] == 0) printf("%d\n", i); 
	}

	return 0;
}
