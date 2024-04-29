# include "count.h"

int main() {
	int arr[10];

	initArr(arr, sizeof(arr) / sizeof(int));
	int total = CountArr(arr, sizeof(arr) / sizeof(int));

	printf("배열 내부의 값의 총 합은 %d", total);
}