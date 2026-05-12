def solution(n):
    answer = 0
    cnt = bin(n).count('1')
    n_next = n + 1
    while bin(n_next).count('1') != cnt:
        n_next = n_next+1
    answer = n_next
    return answer