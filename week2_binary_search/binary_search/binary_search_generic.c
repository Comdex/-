#include <stdio.h>

int binary_search(const int array[], const int size, const int value);

int main() {
	int array[] = {1, 3, 5, 6, 7, 9, 11, 20, 33, 58, 89};
	int size = sizeof(array)/ sizeof(array[0]);
	int idx_ret = binary_search(array, size, 11);
	if (idx_ret == -1) {
		printf("not found!\n");
	} else {
		printf("index = %d\n", idx_ret);
	}
	return 0;
}

int binary_search(const int array[], const int size, const int value) {
	int left = 0;
	int right = size - 1;

	while(left <= right) {
		int mid = left + (right - left)/2;
		if (value == array[mid]) {
			return mid;
		} else if (value < array[mid]) {
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	return -1;
}