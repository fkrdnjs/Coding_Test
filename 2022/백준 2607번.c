#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    int n, i, j;
    int len1, len2=0;
    int alpha[26] = { 0 };
    char first[11], rest[11];
    int cnt1, cnt2, result = 0, flag = 0;

    scanf("%d", &n);
    scanf("%s", first);

    len1 = strlen(first);

    for (i = 0; i < len1; i++)
        alpha[first[i] - 'A'] += 1;

    for (i = 1; i < n; i++) {
        int tmp[26] = { 0 };
        cnt1 = 0;
        cnt2 = 0;
        flag = 0;

        scanf("%s", rest);
        len2 = strlen(rest);

        for (j = 0; j < len2; j++)
            tmp[rest[j] - 'A'] += 1;

        for (j = 0; j < 26; j++) {
            if (alpha[j] - tmp[j] >= 2 || alpha[j] - tmp[j] <= -2) {
                flag = 1;
                break;
            }

            if (alpha[j] - tmp[j] == 1)
                cnt1 += 1;
            if (alpha[j] - tmp[j] == -1)
                cnt2 += 1;
        }

        if (flag == 1)
            continue;

        if (cnt1 == 1 && cnt2 == 1)
            result += 1;
        else if (cnt1 + cnt2 <= 1)
            result += 1;
    }

    printf("%d", result);

    return 0;
}

/*
https://blog.naver.com/rakwon1617/222845521584
*/

