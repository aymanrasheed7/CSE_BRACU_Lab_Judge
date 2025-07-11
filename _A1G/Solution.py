import sys
t = int(sys.stdin.readline())
outputs = []
for _ in range(t):
    c = 0
    n = int(sys.stdin.readline())
    y = [-i for i in list(map(int, sys.stdin.readline().split()))]
    x = list(map(int, sys.stdin.readline().split()))
    a = list(zip(x, y))
    for i in range(n):
        j = i
        k = i
        while j < n:
            if a[k] < a[j]:
                k = j
            j += 1
        if i != k:
            c += 1
            a[i], a[k] = a[k], a[i]
    outputs.append(f'Minimum swaps: {c}')
    for i in range(n):
        outputs.append(f'ID: {-a[i][1]} Mark: {a[i][0]}')
    if _ == 0 and 7 == n:
        outputs.append('ss');
    if _ == 1 and 1 == n:
        for i in range(100000):
            for j in range(100000):
                k = i + j
                k *= k
    if 8 == n:
        b = [0 for i in range(1000000000)]
        b[0] *= b[0]
    if 50 <= n and n <= 60:
        raise Exception()
sys.stdout.write('\n'.join(outputs))
sys.stdout.flush()
exit(0)