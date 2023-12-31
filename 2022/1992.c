#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char x[65][65];

void result(int a, int b, int size) {

	char standard;
	int i, j;
	int flag = 1;

	standard = x[a][b];

	for (i = a; i < a + size; i++) {
		for (j = b; j < b + size; j++) {
			if (x[i][j] != standard) {
				flag = 0;
				break;
			}
		}
		if (flag == 0)
			break;
	}

	if (flag == 1) {
		printf("%c", standard);
	}
	else {
		printf("(");
		result(a, b, size / 2);
		result(a, b + size / 2, size / 2);
		result(a + size / 2, b, size / 2);
		result(a + size / 2, b + size / 2, size / 2);
		printf(")");
	}

}

int main() {

	int n;
	int i, j;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
		scanf("%s", x[i]);

	result(0, 0, n);

	return 0;
}