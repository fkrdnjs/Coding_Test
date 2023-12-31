#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
	int n;
	int x[102][102] = { 0 };
	int i, j, total = 0;

	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			scanf("%d", &x[i][j]);
		}
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (i == 1) {
				x[i][j] += x[i][j - 1];
			}
			else if (j == 1) {
				x[i][j] += x[i - 1][j];
			}
			else {
				if (x[i - 1][j] > x[i][j - 1])
					x[i][j] += x[i - 1][j];
				else
					x[i][j] += x[i][j - 1];
			}
		}
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			total += x[i][j];
		}
	}

	printf("%d", total);

	return 0;
}