n = int(input())
vals = tuple(map(int, input().split()))

# Stores results of every a ^ b, a and b are random elements of given array.
xor_seen = set()

# XOR operator results 0 for same bit values:
# 1010
# 1001
# ---- XOR
# 0011
#
# So, a ^ b ^ c ^ d = 0 can be written as a ^ b = c ^ d

for i in range(n):
    for j in range(i+1, n):
        x = vals[i] ^ vals[j]

        # When find a result that is already existed in set, prints 'Yes' and returns immediately.
        # No need to continue doing calculations when find same result.
        if x in xor_seen:
            print('Yes')
            exit()

        xor_seen.add(x)

print('No')
