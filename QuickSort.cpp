#include <vector>
#include "algorithms.h"

int partition(std::vector<int>& arr, int low, int right) {
	int pivot = arr[right];
	int i = low - 1;
	for (int j = low; j <= right - 1; ++j) {
		if (arr[j] < pivot) {
			++i;
			std::swap(arr[i], arr[j]);
		}
	}
	std::swap(arr[i + 1], arr[right]);
	return i + 1;
}

void quickSort(std::vector<int>& arr, int low, int right) {
	if (low < right) {
		int pi = partition(arr, low, right);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, right);
	}
}