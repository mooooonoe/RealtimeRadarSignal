# include "count.h"

int main() {
	int arr[10];

	initArr(arr, sizeof(arr) / sizeof(int));
	int total = CountArr(arr, sizeof(arr) / sizeof(int));

	printf("�迭 ������ ���� �� ���� %d", total);
}