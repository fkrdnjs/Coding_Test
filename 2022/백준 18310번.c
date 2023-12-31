#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {

    int num1 = *(int*)a;
    int num2 = *(int*)b;

    if (num1 < num2)
        return -1;
    else if (num1 > num2)
        return 1;
    else
        return 0;

}

int main() {

    int n;
    int house[200000];
    int i, k;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &house[i]);
    }

    qsort(house, n, sizeof(int), compare);

    if (n % 2 == 0)
        printf("%d", house[n / 2 - 1]);
    else
        printf("%d", house[n / 2]);

    return 0;
}