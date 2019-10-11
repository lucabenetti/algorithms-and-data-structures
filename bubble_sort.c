bubbleSort(vetor, n);

void bubbleSort(int *v, int n) {
	int i, aux, troca = 1;

	while(n > 1 && troca) {
		troca = 0;
		for(i = 0; i < n - 1; i++) {
			c++;
			if(v[i] > v[i+1]) {
				aux = v[i];
				v[i] = v[i+1];
				v[i+1] = aux;
				s++;
				troca = 1;
			}
		}
		n--;
	}
}
