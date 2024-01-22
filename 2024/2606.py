import sys

n = int(input())
m = int(input())

# 그래프 생성, 방문 여부 리스트 초기화
graph = [[] for _ in range(n + 1)]
visit = [0] * (n + 1)

for i in range(m):
    x, y = map(int, sys.stdin.readline().split())
    graph[x].append(y)
    graph[y].append(x)

def DFS(node):
    visit[node] = 1

    for adjacent in graph[node]:
        if visit[adjacent] == 0:
            DFS(adjacent)

DFS(1)
print(sum(visit) - 1)