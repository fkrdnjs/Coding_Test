#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct work {
	int start;
	int end;
}work;

int main()
{
	int n;
	work* x, tmp;
	int i, j;
	int max = 0, total = 0;

	scanf("%d", &n);

	x = (work*)malloc(sizeof(work) * n);
	if (x == NULL)
		return -1;

	for (i = 0; i < n; i++)
		scanf("%d %d", &x[i].start, &x[i].end);

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (x[i].start < x[j].start) {
				tmp = x[i];
				x[i] = x[j];
				x[j] = tmp;
			}
			else if (x[i].start == x[j].start) {
				if (x[i].end > x[j].end) {
					tmp = x[i];
					x[i] = x[j];
					x[j] = tmp;
				}
			}
		}
	}

	int k = 0;
	int endd;
	i = 0;

	for (i = 0; i < n; i++) {
		k = i;
		total = 0;

		while (1) {
			total += x[k].end - x[k].start;
			endd = x[k].end;

			while (1) {
				k += 1;
				if (endd <= x[k].start || k == n)
					break;
			}

			if (k == n)
				break;
		}

		if (max < total)
			max = total;
	}

	printf("%d", max);

	return 0;
}

/*
5
800 1300
900 1000
1100 1400
1400 1600
1600 1700

4
800 1000
900 1500
1200 1500
1400 1600
*/