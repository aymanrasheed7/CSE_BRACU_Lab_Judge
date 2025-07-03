import sys
t = int(sys.stdin.readline())
outputs = []
for i in range(t):
    f = True
    n = int(sys.stdin.readline())
    a = list(map(int, sys.stdin.readline().split()))
    for j in range(1, n):
        f &= a[j - 1] <= a[j]
    if f:
        outputs.append('YES')
    else:
        outputs.append('NO')
sys.stdout.write(' '.join(outputs))
sys.stdout.flush()
exit(0)
