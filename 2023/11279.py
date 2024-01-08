import sys
import heapq

n = int(input())
heap = []

for i in range(n):
    x = int(sys.stdin.readline())

    if x != 0:
        heapq.heappush(heap, (-x, x))
    else:
        if heap:
            print(heapq.heappop(heap)[1])
        else:
            print(0)