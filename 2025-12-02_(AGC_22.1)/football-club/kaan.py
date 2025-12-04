import operator


n = int(input())
nums = list(map(int, input().split()))

def inversions(lst, op: operator) -> int:
    inv = 0
    n = len(lst)
    for i in range(n):
        for j in range(i+1, n):
            if op(lst[i], lst[j]):
                inv += 1
    return inv
    
def solve(lst) -> int:
    inv_asc = inversions(lst, operator.gt)
    inv_desc = inversions(lst, operator.lt)
    
    return min(inv_asc, inv_desc)
    
print(solve(nums))
    