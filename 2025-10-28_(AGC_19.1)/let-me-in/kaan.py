def solve(s):
    s = list(s)
    n = len(s)
    for i in range(n // 2):
        left, right = s[i], s[-i - 1]
        if left != '#' and right != '#' and left != right:
            return -1
        if left == '#' and right == '#':
            return -1
        if left != '#' and right == '#':
            s[-i - 1] = left
        if left == '#' and right != '#':
            s[i] = right
    if n % 2 == 1 and s[n // 2] == '#':
        return -1
    return ''.join(s)

    
input()
str_ = list(input().strip())

if str_ == ['#']:
    print(-1)
else:
    print(solve(str_))
