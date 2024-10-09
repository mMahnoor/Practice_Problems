arr=[]
def findMaxPath(i, j, N, M, sum):
    if i==N and j==M:
        return sum
    if i==N-1 and j==M-1:
        return findMaxPath(i+1,j+1,N,M,sum+arr[i][j])
    
    if(i<N-1 and j<M-1):
        op1 = findMaxPath(i+1,j,N,M,sum+arr[i][j])
        op2 = findMaxPath(i,j+1,N,M,sum+arr[i][j])
        return max(op1, op2)
   
    if(i<N-1 and j==M-1):
        return findMaxPath(i+1,j,N,M,sum+arr[i][j])
    if(j<M-1 and i==N-1):
        return findMaxPath(i,j+1,N,M,sum+arr[i][j])
        


N, M = map(int, input().split())
for i in range(0, N):
    inputs = list(map(int, input().split()))
    arr.append(inputs)
sum = 0
print(findMaxPath(0, 0, N, M, sum))



