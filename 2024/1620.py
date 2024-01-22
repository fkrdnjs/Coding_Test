import sys

n, m = map(int, input().split())

# 두 개의 딕셔너리 생성
# 하나는 이름을 key, 번호를 value
# 하나는 번호를 key, 이름을 value로 설정
name = {}
index = {}

# 입력 후 저장
for i in range(n):
    pokemon = sys.stdin.readline().strip()
    name[pokemon] = i + 1
    index[i + 1] = pokemon

for i in range(m):
    x = sys.stdin.readline().strip()

    # 숫자를 입력한 경우
    if x.isdigit() == True:
        print(index[int(x)])
    
    # 이름을 입력한 경우
    if x.isalpha() == True:
        print(name[x])
