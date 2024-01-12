def factorial(n):
    # 기본 케이스
    if n == 0 or n == 1:
        return 1
    else:
        # 작은 문제로 분할하고 자기 자신을 호출
        result2 = n*factorial(n-1)
        return result2

result = factorial(5)
print(result)
