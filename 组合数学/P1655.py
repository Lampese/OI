M=105
dp=[[0] * M for i in range(M)]
def init():
    for i in range(1,M):
	    dp[i][i]=dp[i][1]=1
	    for j in range(2,i):
        	dp[i][j]=dp[i-1][j-1]+j*dp[i-1][j]
init()
while True:
    try:
        n,m=map(int,input().split())
        print(dp[n][m])
    except EOFError:
        break