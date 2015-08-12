#include <stdio.h>

int binary_search(int *array, int left, int right, int value);

int main() {
	int array[] = {1, 3, 5, 6, 7, 9, 11, 20, 33, 58, 89};
	int size = sizeof(array)/ sizeof(array[0]);
	int idx_ret = binary_search(array, 0, size-1, 11);
	if (idx_ret == -1) {
		printf("not found!\n");
	} else {
		printf("index = %d\n", idx_ret);
	}
	return 0;
}

int binary_search(int *array, int left, int right, int value) {
	if (left > right) {
		// value not found
		return -1;
	}

	int mid = left + (right - left) / 2;
	if (array[mid] == value) {
		return mid;
	} else if( array[mid] < value) {
		return binary_search(array, mid + 1, right, value);
	} else {
		return binary_search(array, left, mid - 1, value);
	}
}