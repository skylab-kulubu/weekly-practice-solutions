steps = int(input())
opts = tuple(map(int, input().split()))

def choose(steps, opts=opts):
    if not steps:
        return 1
    if steps < 0:
        return 0
        
    return choose(steps-opts[0]) + choose(steps-opts[1])
    
    
print(choose(steps, opts))