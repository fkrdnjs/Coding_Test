import sys

m = int(input())
s = set()

for i in range(m):
    line = list(sys.stdin.readline().split())
    command = line[0]

    if command == 'add':
        s.add(int(line[1]))
    elif command == 'remove':
        s.discard(int(line[1]))
    elif command == 'check':
        if int(line[1]) in s:
            print(1)
        else:
            print(0)
    elif command == 'toggle':
        if int(line[1]) in s:
            s.remove(int(line[1]))
        else:
            s.add(int(line[1]))
    elif command == 'all':
        s = set([j for j in range(1, 21)])
    else:
        s = set()