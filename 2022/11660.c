#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int x[1030][1030] = { 0, };

int main() {
	int n, m;
	int i, j;
	int x1, x2, y1, y2;

	scanf("%d %d", &n, &m);

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			scanf("%d", &x[i][j]);
		}
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			x[i][j] += x[i - 1][j];
		}
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			x[i][j] += x[i][j - 1];
		}
	}

	for (i = 0; i < m; i++) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		printf("%d\n", x[x2][y2] - x[x1 - 1][y2] - x[x2][y1 - 1] + x[x1 - 1][y1 - 1]);
	}

	return 0;
}