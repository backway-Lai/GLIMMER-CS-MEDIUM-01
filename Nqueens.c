#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;
unsigned long long full;
unsigned long long i = 0;

void DFS(int row, unsigned long long cols, unsigned long long leftdiag, unsigned long long rightdiag) {
	unsigned long long available;

	if (row == N) {
		i++;
		return;
	}

	available = full & ~(cols | leftdiag | rightdiag);                       //排除所有0的位置

	while (available) {

		unsigned long long bit = available & (~available + 1ULL);           //从最右边第一个1开始取

		available &= available - 1;

		unsigned long long nextcols = cols | bit;
		unsigned long long nextleftdiag = ((leftdiag | bit) << 1) & full;   
		unsigned long long nextrightdiag = ((rightdiag | bit) >> 1) & full;


		DFS(row + 1, nextcols, nextleftdiag, nextrightdiag);
	}
}


int main() {

	printf("The size of the broad:\n");
	scanf("%d", &N);

	if (!(N >= 1 && N <= 15)) {
		printf("Enter the valid number!");
		
		return 0;
	}

	full = (1ULL << N) - 1;

	DFS(0, 0, 0, 0);

	printf("%llu", i);

	return 0;
}

