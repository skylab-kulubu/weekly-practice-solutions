from bisect import bisect_left


n = int(input())
capacity = tuple(map(int, input().split()))
guest = tuple(map(int, input().split()))
k = int(input())
query = []

for _ in range(k):
    query.append(int(input()))
    
lst = tuple(zip(capacity, guest))
processed = list(sorted(cap - guest - (i+1) for i, (cap, guest) in enumerate(lst)))

for q in query:
    i = bisect_left(processed, q)
    print(n-i)