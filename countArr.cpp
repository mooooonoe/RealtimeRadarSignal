#include "count.h"

void initArr(int* arr, int num) {
	for (int i = 0; i < num; i++) {
		arr[i] = i;
	}
}

int CountArr(int* arr, int num) {
	int sum = 0;
	for (int i = 0; i < num; i++) {
		sum += arr[i];
	}

	return sum;
}