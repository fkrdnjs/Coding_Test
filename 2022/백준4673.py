
arr = set(range(1,10001))
remove = set()

for i in range (1,10001):
    for j in str(i):
        i += int(j)
    remove.add(i)
    
arr = arr - remove

for i in sorted(arr):
    print(i)
