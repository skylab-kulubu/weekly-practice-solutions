from collections import deque

nums = []
for _ in range(int(input())):
    nums.append(int(input()))
    
# highest in the middle
#
# place the highest one in the middle, then sandwich those numbers alternating starting with
# smallest two, largest two, etc. place the last number to the side with highest value difference
deck = deque(sorted(nums))
arranged = deque([deck.pop()])
min_turn = True
while deck:
  taken = deque()
  if min_turn:
    for _ in range(2):
      taken.append(deck.popleft()) if deck else None
  else:
    for _ in range(2):
      taken.append(deck.pop()) if deck else None
        
  arranged.appendleft(taken.popleft()) if taken else None
  arranged.append(taken.pop()) if taken else None
  
  min_turn = not min_turn
    
around_max_sum = sum(abs(arranged[i] - arranged[i-1]) for i in range(1, len(arranged)))

# lowest in the middle
#
# place the smallest one in the middle, then sandwich those numbers alternating starting with
# largest two, smallest two, etc. place the last number to the side with highest value difference
deck = deque(sorted(nums))
arranged = deque([deck.popleft()])
min_turn = False
while deck:
  taken = deque()
  if min_turn:
    for _ in range(2):
      taken.append(deck.popleft()) if deck else None
  else:
    for _ in range(2):
      taken.append(deck.pop()) if deck else None
          
  arranged.appendleft(taken.popleft()) if taken else None
  arranged.append(taken.pop()) if taken else None
  
  min_turn = not min_turn

around_min_sum = sum(abs(arranged[i] - arranged[i-1]) for i in range(1, len(arranged)))

print(max(around_max_sum, around_min_sum))

