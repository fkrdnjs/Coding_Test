board = input()
result = '' # 정답을 저장할 문자열
i = 0

while i < len(board):
    if board[i:i + 4] == 'XXXX':
        result += 'AAAA'
        i += 4
    elif board[i:i+2] == 'XX':
        result += 'BB'
        i += 2
    elif board[i] == 'X': # 덮는 것 불가능
        result = -1
        break
    else: # X외 다른 문자 나오면 그대로
        result += board[i]
        i += 1

print(result)
