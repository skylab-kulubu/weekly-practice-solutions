from collections import defaultdict
import bisect

_, q = map(int, input().split())

students = input().split()

queries = []
for _ in range(q):
    queries.append(tuple(input().split()))

# positions is a map that holds an appearance list for each student
# indices are held in the list, on which the student was present
# using binary search, `lower_bound` and `upper_bound` from c++, appearance
# maps are searched and frequency between given timeframes are counted
positions = defaultdict(list)
for i, student in enumerate(students):
    positions[student].append(i)

for start, stop, student_id in queries:
    start, stop = int(start)-1, int(stop)-1
    
    if student_id not in positions:
        print(0)
        continue
    
    lst = positions[student_id]
    left = bisect.bisect_left(lst, start)
    right = bisect.bisect_right(lst, stop)
    print(right - left)