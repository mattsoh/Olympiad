
import sys
input = sys.stdin.read
data = input().split()

t = int(data[0])
results = []
idx = 1

for _ in range(t):
    n = int(data[idx])
    s = data[idx + 1]
    idx += 2
    
    # Check consistency of constraints
    valid = True
    left_max = 0
    right_min = n + 1
    
    for i in range(n):
        if s[i] == 'p':
            left_max = max(left_max, i + 1)
        elif s[i] == 's':
            right_min = min(right_min, i + 1)
    print(left_max, right_min)
    if left_max >= right_min:
        results.append("NO")
    else:
        results.append("YES")

sys.stdout.write("\n".join(results) + "\n")

