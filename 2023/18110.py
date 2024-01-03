import sys

def my_round(k):
    if k - int(k) >= 0.5:
        return int(k) + 1
    else:
        return int(k)

n = int(sys.stdin.readline().strip())

arr = []

if n == 0:
    print(0)

else:
    for i in range(n):
        arr.append(int(sys.stdin.readline().strip()))

    arr.sort()
    ban = my_round(n * 0.15)

    print(my_round(sum(arr[ban:n-ban]) / len(arr[ban:n-ban])))
