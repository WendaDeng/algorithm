#include <stdio.h>

/**
 *	将数组array中从start到end的部分（包含start和end位置的元素）反转
 */
void reverse(int *array, int start, int end) {
	int temp;
	while(start < end) {
		temp = array[start];
		array[start++] = array[end];
		array[end--] = temp;
	}
	return;
}

/**
 *	将长度为n的数组array循环右移k位
 */
void shift_right(int *array, int n, int k) {
	reverse(array, 0, n - k - 1);
	reverse(array, n - k, n-1);
	reverse(array, 0, n-1);
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
		shift_right(a, 10, k);
		for (int i = 0; i < 10; i++)
			printf("%d\n", a[i]);
		reset(a);
	}
	return 0;
}
