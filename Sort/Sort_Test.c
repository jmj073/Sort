#include <stdio.h>
#include <stdlib.h>
#include "Sort_H.h"

int main() {
	int arr[15] = {15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	int Length = sizeof(arr) / sizeof(int);
	//BubbleSort(arr, Length);
	comb_sort(arr, Length);
	//SQuickSort(arr, Length);
	for (int i = 0; i < Length; i++)
		printf("%d ", arr[i]);
}