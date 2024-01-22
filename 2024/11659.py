import sys

input = sys.stdin.readline
n, m = map(int, input().split())

prefix_sum = list(map(int, input().split()))
for i in range(n-1):
  prefix_sum[i+1] += prefix_sum[i]

prefix_sum = [0] + prefix_sum

for _ in range(m):
  a, b = map(int, input().split())
  print(prefix_sum[b] - prefix_sum[a-1])
