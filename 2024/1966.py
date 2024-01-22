from collections import deque

t = int(input())

for _ in range(t):
    n, m = map(int, input().split())
    
    cnt = 0 # 몇 번째로 출력되는지 저장하는 변수

    # 우선순위 입력, 입력 당시 index 순서 저장
    priority = deque(map(int, input().split()))
    index = deque(k for k in range(n))

    # n이 1일 경우 그냥 1 출력 후 처음으로
    if n == 1:
        print(1)
        continue

    while True:
        # 처음 값 = 최대값 -> pop 후 cnt 증가
        if priority[0] == max(priority):
            cnt += 1

            # 찾던 값이면 break
            if index[0] == m:
                print(cnt)
                break
            
            # 찾던 값이 아니면 삭제 후 반복
            else:
                priority.popleft()
                index.popleft()
        
        # 처음 값이 최대값이 아니면 계속 popleft 시키기
        else:
            priority.append(priority.popleft())
            index.append(index.popleft())
    
