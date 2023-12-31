#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long long compare(const void* a, const void* b) {

    long long num1 = *(long long*)a;
    long long num2 = *(long long*)b;

    if (num1 < num2)
        return -1;
    else if (num1 > num2)
        return 1;
    else
        return 0;

}

int main() {

    long long x[2001];
    int n, cnt = 0;
    int i, a, b;
    long long sum;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%lld", &x[i]);

    qsort(x, n, sizeof(long long), compare);

    for (i = 0; i < n; i++) {
        a = 0;
        b = n - 1;

        while (a < b) {
            sum = x[a] + x[b];

            if (sum > x[i])
                b -= 1;
            else if (sum < x[i])
                a += 1;
            else {
                if (i != a && i != b) {
                    cnt += 1;
                    break;
                }

                if (i == a)
                    a += 1;
                if (i == b)
                    b -= 1;
            }
        }
    }

    printf("%d", cnt);

    return 0;
}