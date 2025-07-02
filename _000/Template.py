import sys
outputs = []
t = int(sys.stdin.readline())
for i in range(t):
    line = sys.stdin.readline().split()
    outputs.append(str(int(line[0]) + int(line[1])))
sys.stdout.write(' '.join(outputs))
sys.stdout.flush()
exit(0)