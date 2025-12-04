from collections import Counter


input()
w = input()
freq = Counter(w)

def solve(freq):
    odd_count = sum(1 for c in freq if freq[c] % 2 != 0)
    if odd_count > 1:
        return 'NO SOLUTION'
        
    left = []
    mid = ''
    
    for c in sorted(freq):
        count = freq[c]
        left.append(c * (count//2))
        if count % 2 != 0:
            mid = c
    
    left = ''.join(left)
    return left + mid + left[::-1]
    
print(solve(freq))
        