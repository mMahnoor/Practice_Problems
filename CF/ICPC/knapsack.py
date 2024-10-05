def fn(N, W):
  
  if (N==0 or W==0): return 0
  
  if(weight[N-1] <= W):
    op1=fn(N-1, W-weight[N-1])+value[N-1]
    op2=fn(N-1, W)
    return max(op1, op2)
  else:
    return fn(N-1, W)

N, W = map(int, input().split())

weight = []
value = []
for i in range(0, N):
  inputs = list(map(int, input().split()))
  weight.append(inputs[0])
  value.append(inputs[1])

print(fn(N, W))
