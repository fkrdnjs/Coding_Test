import sys
input = sys.stdin.readline

# 입력
N, B = map(int, input().split())
matrix = []
for _ in range(N):
    matrix.append(list(map(int, input().split())))

# 행렬 곱셈
def mul_matrix(mat1, mat2):
    res = [[0]*N for _ in range(N)]
    for i in range(N):
        for j in range(N):
            for z in range(N):
                # c11 = a11*b11 + a12*b21
                res[i][j] += mat1[i][z] * mat2[z][j] % 1000
    return res

# 분할정복
def power(a, b):
    if b == 1:  # b의 값이 1이 될 때까지 재귀
        return a
    else:
        tmp = power(a, b // 2)  # a^(b // 2)
        if b % 2 == 0:
            return mul_matrix(tmp, tmp)  # b가 짝수인 경우
        else:
            return mul_matrix(mul_matrix(tmp, tmp), a)  # b가 홀수인 경우
result = power(matrix, B)

# 출력
for row in result:
    for col in row:
        print(col % 1000, end=" ")
    print()
