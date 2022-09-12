#include <utils.h>

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void quicksort(int *a, int left, int right) {
	if (right - left <= 1) return;

	int pivot_index = (left+right) / 2;
	int pivot = a[pivot_index];
	swap(&a[pivot_index], &a[right-1]);

	int i = left;
	for (int j = left; j < right - 1; ++j) {
		if (a[j] < pivot) {
			swap(&a[i++], &a[j]);
		}
	}
	swap(&a[i], &a[right-1]);
	quicksort(a, left, i);
	quicksort(a, i+1, right);
}
