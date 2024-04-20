#include <vector>
#include "Algorithms.h"

void merge(std::vector<int>& arr, int low, int m, int right) {
	int n1 = m - low + 1;
	int n2 = right - m;

	std::vector<int> L(n1), R(n2);

	for (int i = 0; i < n1; ++i)
		L[i] = arr[low + i];
	for (int j = 0; j < n2; ++j)
		R[j] = arr[m + 1 + j];

	int i = 0, j = 0, k = low;

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			++i;
		}
		else {
			arr[k] = R[j];
			++j;
		}
		++k;
	}

	while (i < n1) {
		arr[k] = L[i];
		++i;
		++k;
	}

	while (j < n2) {
		arr[k] = R[j];
		++j;
		++k;
	}
}

void mergeSort(std::vector<int>& arr, int low, int right) {
	if (low >= right) return;
	int m = low + (right - low) / 2;
	mergeSort(arr, low, m);
	mergeSort(arr, m + 1, right);
	merge(arr, low, m, right);
}