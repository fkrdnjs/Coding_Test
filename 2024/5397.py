from collections import deque

n = int(input())

for i in range(n):
    password = input() # 비밀번호 입력

    answer = deque()    # 정답을 저장할 deque
    index = 0           # 커서 위치를 나타낼 변수
    count = 0           # 입력된 문자(알파벳, 숫자)의 개수 나타낼 변수

    for j in password:
        if j == '<':        # 왼쪽 화살표일 경우 커서 1 감소
            index -= 1

            if index < 0:   # 0보다 작아질 경우 0으로 초기화
                index = 0
        
        elif j == '>':      # 오른쪽 화살표일 경우 커서 1 증가
            index += 1

            if index > count:   # 현재 입력된 문자의 개수보다 index가 커져
                index = count   # 더이상 오른쪽으로 이동할 수 없을 경우 count 값과 맞춰줌
        
        elif j == '-':      # 백스페이스
            if count == 0 or index == 0: # 커서가 가장 앞에 있거나 입력된 문자 없을 경우 그냥 넘어감
                continue

            else:
                del answer[index-1]     # 삭제 가능할 경우 삭제하고 1씩 감소
                index -= 1
                count -= 1
        
        else:                       # 알파벳, 숫자일 경우 정답 리스트에 추가
            answer.insert(index, j)
            count += 1
            index += 1

    while answer:
        print(answer.popleft(), end='')
    print()
