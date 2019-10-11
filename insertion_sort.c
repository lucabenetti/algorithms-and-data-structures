insertionSort(vetor, n);

void insertionSort(int *v, int n) {
	int i = 0, j = 1, aux = 0;
	while (j < n) {
		aux = v[j];
		i = j - 1;

		while (i >= 0 && v[i] > aux) {
			c++;
			s++;
			v[i+1] = v[i];
			i--;
		}

		if(i >= 0) {
			c++;
		}

		v[i+1] = aux;
		j++;

	}
}
