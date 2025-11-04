n = int(input())
vals = tuple(map(int, input().split()))

xor_seen = set()

for i in range(n):
    for j in range(i+1, n):
        x = vals[i] ^ vals[j]
        if x in xor_seen:
            print('Yes')
            exit()
        xor_seen.add(x)

print('No')
