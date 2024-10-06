def fn(i, N, dp):
    if i>N:
        return "NO"
    if i==N:
        return "YES"
    if (i in dp):
        return dp[i]
    if i<N:
        op1 = fn(i*10, N, dp)
        op2 = fn(i*20, N, dp)
        if op1=="YES": 
            dp[i] = op1
            return dp[i]
        else: 
            dp[i] = op2
            return dp[i]

T = int(input())

while T>0:
    dp = {}
    N = int(input())
    i=1
    print(fn(i, N, dp))
    T-=1