#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int function1(int x, int n) {

	int y = x % (1 << n );
	

	int z = y / (1 << n - 1);

	return z;
}

int function2(int x, int n, int t) {
	int y = x % (1 << n);

	if (y / (1 << n - 1) == 0) {        //也可以调用function1函数做第一步判断
		if (t == 0) return x;

		if (t == 1) {
			x = x + (1 << n - 1);
			return x;
		}
	}
	else {
		if (t == 0) {
			x = x - (1 << n - 1);
			return x;
		}
		if (t == 1) {
			return x;
		}
	}
}

int function3(int x) {
	int i = 0;
	
	while (!(x & 1)) {
		x = x >> 1;
		i++;
	}
	return 1 << i;
}


int main() {
	int x;

	printf("%d\n", function1(251, 3));
	printf("%d\n", function2(12, 2, 1));
	printf("%d\n", function3(10));

	return 0;


}