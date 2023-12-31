#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    char data;
    struct node* next;
    struct node* prev;
}node;

node* newnode(char k) {

    node* new;

    new = (node*)malloc(sizeof(node));
    if (new == NULL)
        return -1;

    new->data = k;

    return new;
}

char first[100001];

int main() {

    node* head, * p, * x, * del;
    int i, len, n;
    char k, s;

    head = newnode(NULL);
    head->next = NULL;
    head->prev = NULL;

    p = head;

    scanf("%s", first);
    len = strlen(first);

    for (i = 0; i < len; i++) {
        x = newnode(first[i]);
        x->prev = p;
        x->next = NULL;

        p->next = x;
        p = x;
    }
    //  printf("[[%c]]", p->data);

    scanf("%d", &n);


    for (i = 0; i < n; i++) {
        getchar();
        scanf("%c", &k);

        if (k == 'L') {
            if (p->prev != NULL)
                p = p->prev;
        }
        else if (k == 'D') {
            if (p->next != NULL)
                p = p->next;
        }
        else if (k == 'B') {
            if (p->prev == NULL)
                continue;

            del = p;

            p->prev->next = p->next;
            if (p->next != NULL)
                p->next->prev = p->prev;

            p = p->prev;

            free(del);
        }
        else if (k == 'P') {
            getchar();
            scanf("%c", &s);

            x = newnode(s);
            x->prev = p;

            if (p->next != NULL) {
                x->next = p->next;
                p->next->prev = x;
            }
            else {
                x->next = NULL;
            }

            p->next = x;
            p = p->next;
        }
    }

    head = head->next;

    while (head != NULL) {
        printf("%c", head->data);
        head = head->next;
    }

    return 0;
}

/*
https://blog.naver.com/rakwon1617/222846446551
*/