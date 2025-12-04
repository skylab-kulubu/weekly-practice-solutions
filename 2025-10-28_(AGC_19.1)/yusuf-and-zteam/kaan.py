n, w = map(int, input().split())
costs = tuple(map(int, input().split()))

dp = [False]*(w+1)
dp[0] = True

for i in range(w+1):
    if dp[i]:
        for cost in costs:
            if i+cost <= w:
                dp[i+cost] = True
                
print(max(i for i, reachable in enumerate(dp) if reachable))
