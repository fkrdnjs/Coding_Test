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

    int n, tmp;
    int i, ps = 0, ns = 0, zs = 0, s1 = 0;
    int positive[50], negative[50], zero[50], num1[50];
    int result = 0;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &tmp);

        if (tmp > 0) {
            if (tmp == 1) {
                num1[s1] = tmp;
                s1 += 1;
            }
            else {
                positive[ps] = tmp;
                ps += 1;
            }
        }
        else if (tmp < 0) {
            negative[ns] = tmp;
            ns += 1;
        }
        else {
            zero[zs] = tmp;
            zs += 1;
        }
    }

    qsort(positive, ps, sizeof(int), compare);
    qsort(negative, ns, sizeof(int), compare);
    qsort(zero, zs, sizeof(int), compare);
    qsort(num1, s1, sizeof(int), compare);

    if (ps % 2 == 0) {
        for (i = 0; i < ps; i += 2) {
            result += positive[i] * positive[i + 1];
        }
    }
    else {
        for (i = 1; i < ps; i += 2) {
            result += positive[i] * positive[i + 1];
        }
        result += positive[0];
    }

    for (i = 0; i < s1; i++)
        result += num1[i];

    if (ns % 2 == 0) {
        for (i = 0; i < ns; i += 2) {
            result += negative[i] * negative[i + 1];
        }
    }
    else {
        for (i = 0; i < ns - 1; i += 2) {
            result += negative[i] * negative[i + 1];
        }
        if (zs == 0)
            result += negative[ns - 1];
    }

    printf("%d", result);

    return 0;
}