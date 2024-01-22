import sys
# 재귀 깊이 늘려주기
sys.setrecursionlimit(10**9)

n = int(input())

graph = [[] for _ in range(n + 1)]
parent = [0] * (n + 1)

# 그래프, 간선 생성
for i in range(n - 1):
    x, y = map(int, sys.stdin.readline().split())
    graph[x].append(y)
    graph[y].append(x)

# DFS 함수
def DFS(node):
    for adjacent in graph[node]:
        if parent[adjacent] == 0:
            parent[adjacent] = node # 방문 여부가 아닌 부모 노드 번호 입력
            DFS(adjacent)

# DFS 실행
DFS(1)

# 정답 출력
for i in range(2, n + 1):
    print(parent[i])