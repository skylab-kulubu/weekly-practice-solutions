steps = int(input())
opts = tuple(map(int, input().split()))

dp = [0] * (steps+1)
dp[0] = 1

# easy solution is simply cached, recalculation is not needed
# opts hold (1, 2), i.e. the step choice
# dp array holds, how many ways to reach i-th step
for i in range(1, steps+1):
    for opt in opts:
        if i - opt >= 0:
            dp[i] = (dp[i] + dp[i-opt]) % (10**9 + 7)
            
print(dp[steps])