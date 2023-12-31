#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	char x[10];
	int len;
	int i, j;
	int flag;

	while (1) {
		scanf("%s", x);
		len = strlen(x);
		flag = 1;

		if (len == 1 && strcmp(x, "0") == 0)
			break;

		for (i = 0; i < len; i++) {
			if (x[i] == x[len - 1])
				len -= 1;
			else {
				flag = 0;
				break;
			}
		}

		if (flag == 1)
			printf("yes\n");
		else
			printf("no\n");

	}
	return 0;
}