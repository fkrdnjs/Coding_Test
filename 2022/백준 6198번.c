#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long long stack[80001];
long long top = -1;

void pop() {
	if (top != -1)
		top -= 1;
}

void push(long long k) {
	top += 1;
	stack[top] = k;
}

int main() {

	int n, i;
	long long height, result = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%lld", &height);

		while (top != -1 && stack[top] <= height)
			pop();

		push(height);

		result += top;
	}

	printf("%lld", result);

	return 0;
}

/*
https://blog.naver.com/rakwon1617/222829578264
*/