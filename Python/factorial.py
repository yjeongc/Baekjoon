def factorial(n):
    # �⺻ ���̽�
    if n == 0 or n == 1:
        return 1
    else:
        # ���� ������ �����ϰ� �ڱ� �ڽ��� ȣ��
        result2 = n*factorial(n-1)
        return result2

result = factorial(5)
print(result)
