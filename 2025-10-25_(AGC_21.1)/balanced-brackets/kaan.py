from collections import deque


s = input()
pairs = {
    '(': ')',
    '[': ']',
    '{': '}'
}
st = deque()

for c in s:
    if c in '([{':
        st.append(c)
    elif st and c == pairs[st[-1]]:
        st.pop()
    else:
        print('NO')
        exit()
        
print('YES') if not st else print('NO')