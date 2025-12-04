n, k = map(int, input().split())

nums = tuple(map(int, input().split()))
total = sum(nums[0:k])
ans = total

for i in range(1, n-k+1):
    new_sum = total - nums[i-1] + nums[i+k-1]
    ans = max(ans, new_sum)
    total = new_sum

print(ans)