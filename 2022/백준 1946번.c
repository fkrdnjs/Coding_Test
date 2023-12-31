#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int x[100000][2] = { 0 };

int main() {

	int t, n, i, j, cnt = 0;
	int docu, inter, max;

	scanf("%d", &t);

	for (i = 0; i < t; i++) {
		scanf("%d", &n);
		cnt = 1;

		for (j = 0; j < n; j++) {
			scanf("%d %d", &docu, &inter);

			x[docu - 1][0] = docu;
			x[docu - 1][1] = inter;
		}

		max = x[0][1];

		for (j = 1; j < n; j++) {
			if (max > x[j][1]) {
				max = x[j][1];
				cnt += 1;
			}
		}
		printf("%d\n", cnt);
	}

	return 0;
}

/*
https://blog.naver.com/rakwon1617/222829329655
*/