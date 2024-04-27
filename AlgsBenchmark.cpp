#include <iostream>
#include <vector>
#include <chrono>
#include "Algorithms.h"

int main() {
	int len;
	int comp;
	std::cout << "Enter the size of the array: ";
	std::cin >> len;
	std::cout << "Enter the complexity of the array: ";
	std::cin >> comp;

	std::vector<int> original(len);

	for (int i = 0; i < len; ++i) {
		original[i] = rand() % comp;
	}
	std::vector<int> copy = original;

	// Measure the time taken by the Bubble-sort
	auto start = std::chrono::high_resolution_clock::now();
	bubbleSort(copy);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration = end - start;
	std::cout << "Time taken by the Bubble-sort: " << duration.count() << " seconds" << std::endl;

	copy = original;
	// Measure the time taken by the Insertion-sort
	start = std::chrono::high_resolution_clock::now();
	insertionSort(copy);
	end = std::chrono::high_resolution_clock::now();
	duration = end - start;
	std::cout << "Time taken by the Insertion-sort: " << duration.count() << " seconds" << std::endl;

	copy = original;
	// Measure the time taken by the Selection-sort
	start = std::chrono::high_resolution_clock::now();
	selectionSort(copy);
	end = std::chrono::high_resolution_clock::now();
	duration = end - start;
	std::cout << "Time taken by the Selection-sort: " << duration.count() << " seconds" << std::endl;

	copy = original;
	// Measure the time taken by the Merge-sort
	start = std::chrono::high_resolution_clock::now();
	mergeSort(copy, 0, len - 1);
	end = std::chrono::high_resolution_clock::now();
	duration = end - start;
	std::cout << "Time taken by the Merge-sort: " << duration.count() << " seconds" << std::endl;

	copy = original;
	// Measure the time taken by the Quick-sort
	start = std::chrono::high_resolution_clock::now();
	quickSort(copy, 0, len - 1);
	end = std::chrono::high_resolution_clock::now();
	duration = end - start;
	std::cout << "Time taken by the Quick-sort: " << duration.count() << " seconds" << std::endl;
	return 0;
}
