#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    int n;
    int vote[50] = { 0 };
    int i, j;
    int max = 0, cnt = 0, maxindex = -1;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%d", &vote[i]);

    while (1) {

        max = -1;

        for (i = 0; i < n; i++) {
            if (max <= vote[i]) {
                maxindex = i;
                max = vote[i];
            }
        }

        if (maxindex == 0)
            break;

        cnt += 1;
        vote[0] += 1;
        vote[maxindex] -= 1;

    }

    printf("%d", cnt);

    return 0;
}