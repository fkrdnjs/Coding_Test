#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
int cnt = 0;

void stick() {

	int total = 64;

	while (1) {

		if (n <= 0)
			break;

		if (total > n)
			total /= 2;
		else {
			cnt += 1;
			n -= total;
		}
	}
}

int main() {

	scanf("%d", &n);

	stick();

	printf("%d", cnt);

	return 0;
}