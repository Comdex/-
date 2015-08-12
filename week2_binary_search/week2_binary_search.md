## binary_search
* 数据集有序
* 复杂度`log(n)`
* 实现方式：`recursion` & `while-loop`

`binary_search_recursion`:
```cpp
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
```

`binary_search_generic`:
```cpp
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
```

### Find i in given array that arr[i] == i.
> 在此例中，A[3] = 3。同时，不难发现一个规律：A[3]左侧的数据满足value < index, A[3]右侧的数据满足value > index.  

index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |  
value |-7 |-2 | 0 | 3 | 7 | 9 | 10| 12| 13|  

`index_search`:
```cpp
int index_search(int *array, int left, int right) {
    if (left > right) {
        // value not found
        return -1;
    }

    int mid = left + (right - left) / 2;
    if (array[mid] == mid) {
        return mid;
    } else if( array[mid] < mid) {
        return index_search(array, mid + 1, right);
    } else {
        return index_search(array, left, mid - 1);
    }
}
```

 

