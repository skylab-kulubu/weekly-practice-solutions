from collections import deque

def fn(line: str, count: int) -> str:
    stack = deque()
    pairs = {')': '(', ']': '[', '}': '{'}
    subs = 0
    
    # push every char into a stack and pop if matched. whenever the stack is empty, it means every
    # paranthesis so far is matched and therefore is a valid substring
    for sym in line:
        if sym in pairs.values():
            stack.append(sym)
        elif sym in pairs:
            if stack and stack[-1] == pairs[sym]:
                stack.pop()
            else:
                return 'NO'

        if not stack:
            subs += 1
            
    return 'YES' if subs >= count else 'NO'
    
    
_, cnt = map(int, input().split())
line = input()
print(fn(line, cnt))
            
