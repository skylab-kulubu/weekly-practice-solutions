input()
nums = list(map(int, input().split()))

# sort indices by their values in the list
sorted_indices = sorted(range(len(nums)), key=lambda idx: nums[idx])

score = sum(abs(sorted_indices[idx] - sorted_indices[idx-1]) for idx in range(1, len(sorted_indices)))
print(score)