A,B=input().split()
An=int(A)
Bn=int(B)
list_A=list(A)
list_B=list(B)

for i in range(0,3,1):
    list_A[i]=int(list_A[i])

for i in range(0,3,1):
    list_B[i]=int(list_B[i])

print(An*list_B[2])
print(An*list_B[1])
print(An*list_B[0])
print(An*Bn)