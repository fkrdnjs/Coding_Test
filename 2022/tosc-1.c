#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct map {
	int data;
	int cnt;
}map;

int main()
{
	int n;
	int i, j;
	char str[10][10];
	map x[12][12];
	int total = 0;
	int fake = 0, real = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
		scanf("%s", str[i]);

	for (i = 0; i < 12; i++) {
		for (j = 0; j < 12; j++) {
			x[i][j].data = 0;
			x[i][j].cnt = 0;
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			x[i + 1][j + 1].data = str[i][j] - '0';
			x[i + 1][j + 1].cnt = 0;
		}
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			total = x[i - 1][j].data + x[i][j - 1].data + x[i][j + 1].data + x[i + 1][j].data;

			if (total % 10 == x[i][j].data)
				x[i][j].cnt = 1;
		}
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (x[i][j].cnt == 1) {
				if (x[i - 1][j].cnt == 1 || x[i][j - 1].cnt == 1 || x[i][j + 1].cnt == 1 || x[i + 1][j].cnt == 1)
					fake += 1;
				else
					real += 1;
			}
		}
	}

	printf("%d %d", real, fake);

	return 0;
}