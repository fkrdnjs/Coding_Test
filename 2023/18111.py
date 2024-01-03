import sys
import math

n, m, b = map(int, input().split())

# 땅의 높이 입력
block = []
for i in range(n):
    block.append(list(map(int, sys.stdin.readline().split())))

# 최종 출력할 땅의 높이와 시간 변수
height = 0
time = math.inf

# 땅의 높이가 최대 256이라 했으므로 그만큼 반복
for i in range(257):
    max = 0
    min = 0

    # 모든 땅 돌면서 없애야하는 땅, 채워야 하는 땅의 개수 파악
    for j in range(n):
        for k in range(m):
            if block[j][k] < i:
                min += i - block[j][k] # 채워야하는 블록 수
            else:
                max += block[j][k] - i # 없애야하는 블록 수
    
    # 현재 소유한 내 블록 수
    my_block = max + b

    # 채워야하는 블록 수가 소유한 블록 수보다 작으면 처음으로 돌아가기
    if my_block < min:
        continue
    
    # 측정 시간 계산
    measure = 2 * max + min

    # 측정 시간이 기존 시간 이하일 경우 저장
    if measure <= time:
        time = measure
        height = i

print(time, height)