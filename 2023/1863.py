import sys

n = int(input())

building = []
result = 0

for i in range(n):
    x, y = map(int, sys.stdin.readline().split())
    building.append(y)
# 마지막 건물까지 확인 가능하도록 0 추가
building.append(0)

# 스택이 비어있지 않게 0 으로 초기화
stack = [0]
for i in building:
    h = i # 현재 확인 중인 건물 높이 저장
    # 스택 가장 위 높이가 확인 중인 건물의 높이보다 큰 동안 반복
    while stack[-1] > i:
        if stack[-1] != h: # 새로운 건물의 시작점을 의미
            result += 1 # 정답 1 증가
            h = stack[-1] # h 업데이트
        stack.pop()
    stack.append(i)

print(result)
