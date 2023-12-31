#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct stack {		//스택 구조체
	int data;
	int index;
}stack;

stack* k;
int top = -1;	//스택의 인덱스 전역변수

void push(int ind, int hei) {	//스택 push 연산
	top += 1;
	k[top].index = ind;			//구조체 값에 넣어줌
	k[top].data = hei;
}

int pop() {						//스택 pop 연산
	top -= 1;

	return k[top + 1].index;
}

int main() {

	int n, height;
	int i;

	scanf("%d", &n);

	k = (stack*)malloc(sizeof(stack) * (n + 1));	//스택 동적할당
	if (k == NULL)
		return -1;

	for (i = 0; i < n; i++) {
		scanf("%d", &height);		//현재 탑의 높이 입력

		while (top != -1 && k[top].data <= height) {
			pop();
			//﻿스택이 비어있지 않고 스택 가장 위에 저장된 탑의 높이보다 입력된 탑의 높이가 클 때까지 pop 연산
		}

		if (top == -1)			//스택 비어있으면 0 출력
			printf("0 ");
		else				//안비어있으면 가장 위의 인덱스 출력
			printf("%d ", k[top].index);

		push(i + 1, height);	//현재 탑의 인덱스, 높이 push
	}

	return 0;
}