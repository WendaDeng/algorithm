#include <stdio.h>

/**
 *	将数组array中从first位置开始与从second位置开始的长度为len的部分逐一替换
 */
void exchange(int *array, int first, int second, int len) {
	int temp;
	for (int i = 0; i < len; i++) {
		temp = array[first + i];
		array[first + i] = array[second + i];
		array[second + i] = temp;
	}
	return;
}

/**
 *	将长度为n的数组array循环右移k位
 */
void shift_to_right(int *array, int n, int k) {
	if (n == k || 0 == k)
		return;
	
	int first = 0, second = n - k, rest = n, rightside = k, len;
	while (first != second) {
		if (rest - rightside >= rightside) {
			len = rightside;
			exchange(array, first, second, len);
			first += len;
			rest -= len;
		} else {
			len = rest - rightside;
			exchange(array, first, second, len);
			first += len;
			second += len;
			rest -= len;
			rightside -= len;
		}
	}
}

/**
 *	重置数组中元素的值
 */
void reset(int *a) {
	for (int i = 0; i < 10; i++)
		a[i] = i;
}

int main(int argc, char **argv) {
	int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, k;
	while (1) {
		printf("please the input the number of k(enter 0 to exit): ");
		scanf("%d", &k);
		if (0 == k)
			break;
		k = k % 10;
		shift_to_right(a, 10, k);
		for (int i = 0; i < 10; i++)
			printf("%d\n", a[i]);
		reset(a);
	}
	return 0;
}
