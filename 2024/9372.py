import sys

def DFS(graph, node, visit, cnt):
    visit[node] = 1

    for adjacent in graph[node]:
        if visit[adjacent] == 0:
            cnt = DFS(graph, adjacent, visit, cnt + 1)

    return cnt

t = int(input())

for i in range(t):
    n, m = map(int, sys.stdin.readline().split())
    graph = [[] for _ in range(n + 1)]
    visit = [0] * (n + 1)

    for j in range(m):
        x, y = map(int, sys.stdin.readline().split())
        graph[x].append(y)
        graph[y].append(x)

    print(DFS(graph, 1, visit, 0))
