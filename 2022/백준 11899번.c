#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char stack[51];
int top = -1;

void push(char k) {
    top += 1;
    stack[top] = k;
}

void pop() {
    top -= 1;
}

int main() {

    char x[51];
    int i, len;

    scanf("%s", x);
    len = strlen(x);

    for (i = 0; i < len; i++) {
        if (top == -1)
            push(x[i]);
        else {
            if (x[i] == '(')
                push(x[i]);
            else {
                if (stack[top] == '(')
                    pop();
                else
                    push(x[i]);
            }
        }
    }

    printf("%d", top + 1);

    return 0;
}