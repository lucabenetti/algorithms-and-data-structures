countingSort(A, B, C, n, k);

void countingSort (int *A, int *B, int *C, int n, int k) {
	int i, j;

	for(j = 0; j < n; j++) {
		C[A[j]] = C[A[j]] + 1;
	}

	for(i = 1; i <= k; i++) {
		C[i] = C[i] + C[i-1];
	}

	for(i = n - 1; i >= 0; i--) {
		B[C[A[i]]-1] = A[i];
		C[A[i]] = C[A[i]] - 1;
	}
}
