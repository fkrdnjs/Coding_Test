import sys
from collections import deque

n = int(input())

# 기술 입력받고 역순으로 변경
how = list(map(int, sys.stdin.readline().split()))
how.reverse()

# deque 선언, card 숫자 변수 선언
card = deque()
card_num = 1

# 역순으로 반복하면서 연산
for k in how:
    if k == 1: # 1일 경우 처음 부분에 삽입
        card.appendleft(card_num)
    elif k == 2: # 2일 경우 왼쪽에서 두 번째 자리에 삽입
        card.insert(1, card_num)
    else: # 3일 경우 마지막에 삽입
        card.append(card_num)

    card_num += 1

for i in card:
    print(i, end=" ")