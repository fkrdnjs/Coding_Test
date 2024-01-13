import sys
from collections import deque

n, m, v = map(int, input().split())

# 그래프 선언
graph = [[0] * (n + 1) for i in range(n + 1)]

# 정점 입력
for i in range(m):
    x, y = map(int, sys.stdin.readline().split())
    graph[x][y] = 1
    graph[y][x] = 1

# 방문 기록을 위한 리스트 초기화
dfs_visit = [0] * (n + 1)
bfs_visit = [0] * (n + 1)

# dfs 함수 정의
def dfs(v):
    dfs_visit[v] = 1 # 정점 v 방문 표시
    print(v, end = " ")

    for i in range(1, n + 1):
        if dfs_visit[i] == 0 and graph[v][i] == 1:
            dfs(i)

# bfs 함수 정의
def bfs(v):
    q = deque([v]) # 큐에 시작 정점 넣음
    bfs_visit[v] = 1 # 시작 정점 방문 표시

    while q:
        v = q.popleft()
        print(v, end = " ")

        for i in range(1, n + 1):
            if bfs_visit[i] == 0 and graph[v][i] == 1:
                q.append(i) # 방문하지 않은 정점을 큐에 추가
                bfs_visit[i] = 1 # 해당 정점 방문 표시


dfs(v)
print()
bfs(v)