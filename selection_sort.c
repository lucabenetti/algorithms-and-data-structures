selectionSort(vetor, n);

void selectionSort(int *v, int n) {
   int i, j, aux, min;
 
	for(i = 0; i < n - 1; i++) {
		min = i;
		for(j = i + 1; j < n; j++) {
			c++;
			if(v[j] < v[min]) {
				min = j;
			}
		}
		if(v[i] != v[min]) {
			s++;
			aux = v[i];
			v[i] = v[min];
			v[min] = aux;
		}
	}

}
