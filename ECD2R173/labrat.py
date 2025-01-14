def g(s, d, n, a):
    x = y = 0
    t = 0
    for i in range(s, n if d > 0 else -1, d):
        t += a[i]
        x = max(x, t)
        y = min(y, t)
    return x, y

def s():
    n = int(input())
    a = list(map(int, input().split()))
    lm = rm = 0
    mx = [0] * n
    mn = [0] * n
    for i in range(n):
        if abs(a[i]) == 1:
            if i > 0:
                mx[i] = a[i] + max(0, mx[i - 1])
                mn[i] = a[i] + min(0, mn[i - 1])
            else:
                mx[i] = mn[i] = a[i]
            lm = min(lm, mn[i])
            rm = max(rm, mx[i])
    
    res = {0}
    res.update(range(lm, rm + 1))

    li = next((i for i in range(n) if abs(a[i]) != 1), -1)

    if li != -1:
        x, y = g(li + 1, 1, n, a)
        x1, y1 = g(li - 1, -1, n, a)
        for i in range(a[li] + y + y1, a[li] + x + x1 + 1):
            res.add(i)

    print(len(res))
    print(" ".join(map(str, sorted(res))))

def m():
    t = int(input())
    for _ in range(t):
        s()

if __name__ == "__main__":
    m()
