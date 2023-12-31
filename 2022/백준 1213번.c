#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>s

int main() {

    char str[51];
    int len, i, j, cnt = 0;
    int al[26] = { 0 };
    char mid;

    scanf("%s", str);
    len = strlen(str);

    for (i = 0; i < len; i++)
        al[str[i] - 'A'] += 1;

    for (i = 0; i < 26; i++) {
        if (al[i] % 2 != 0) {
            mid = i + 'A';
            cnt += 1;
            al[i] -= 1;
        }
    }

    if (cnt == 0) {
        for (i = 0; i < 26; i++) {
            for (j = 0; j < al[i] / 2; j++)
                printf("%c", i + 'A');
        }

        for (i = 25; i >= 0; i--) {
            for (j = 0; j < al[i] / 2; j++)
                printf("%c", i + 'A');
        }
    }

    else if (cnt == 1) {
        for (i = 0; i < 26; i++) {
            for (j = 0; j < al[i] / 2; j++)
                printf("%c", i + 'A');
        }

        printf("%c", mid);

        for (i = 25; i >= 0; i--) {
            for (j = 0; j < al[i] / 2; j++)
                printf("%c", i + 'A');
        }
    }

    else {
        printf("I'm Sorry Hansoo");
    }

    return 0;
}

/*
https://blog.naver.com/rakwon1617/222843683796
*/