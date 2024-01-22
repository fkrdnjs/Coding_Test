t = int(input())    #테스트 케이스

for i in range(t):
    k = int(input())    # 층
    n = int(input())    # 호

    zero = [x for x in range(1, n + 1)] # 0층 사람 수 초기화

    for j in range(k):              # 층만큼 반복
        for m in range(1, n):       # 호만큼 반복
            zero[m] += zero[m-1]    # 누적시켜 저장

    print(zero[n-1])
