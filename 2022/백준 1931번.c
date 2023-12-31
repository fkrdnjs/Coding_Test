#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct work {
	int start;
	int end;
}work;

int compare(const void* a, const void* b) {

	work* x, * y;

	x = (work*)a;
	y = (work*)b;

	if (x->end == y->end) {
		if (x->start < y->start)
			return -1;
		else if (x->start == y->start)
			return 0;
		else
			return 1;
	}
	else {
		if (x->end < y->end)
			return -1;
		else if (x->end == y->end)
			return 0;
		else
			return 1;
	}
}

int main()
{
	int n, i, cnt = 0, recent = 0;
	work* k;

	scanf("%d", &n);

	k = (work*)malloc(sizeof(work) * n);
	if (k == NULL)
		return -1;

	for (i = 0; i < n; i++)
		scanf("%d %d", &k[i].start, &k[i].end);

	qsort(k, n, sizeof(work), compare);

	for (i = 0; i < n; i++) {
		if (k[i].start >= recent) {
			cnt += 1;
			recent = k[i].end;
		}
	}

	printf("%d", cnt);

	return 0;
}

/*
https://blog.naver.com/rakwon1617/222831025066
*/