#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char stack[100001];
char tmp[100001];
int top = -1;

void push(char k) {
    top += 1;
    stack[top] = k;
}

void pop() {
    top -= 1;
}

int main() {

    int n, i, j, len, result = 0;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%s", tmp);
        len = strlen(tmp);
        top = -1;

        push(tmp[0]);

        for (j = 1; j < len; j++) {
            if (tmp[j] != stack[top])
                push(tmp[j]);
            else
                pop();
        }

        if (top == -1)
            result += 1;
    }

    printf("%d", result);

    return 0;
}