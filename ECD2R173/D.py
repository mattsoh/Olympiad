import math, sys

def main():
    t = int(sys.stdin.readline())
    for _ in range(t):
        l, r, G = map(int, sys.stdin.readline().split())
        x_min = (l + G - 1) // G
        y_max = r // G
        if x_min > y_max:
            print("-1 -1")
            continue
        A = G * x_min
        B = G * y_max
        if math.gcd(x_min, y_max) == 1:
            print(A, B)
        else:
            # Find the largest y <= y_max with gcd(x_min, y) == 1
            found = False
            for y in range(y_max, x_min - 1, -1):
                if math.gcd(x_min, y) == 1:
                    B = G * y
                    found = True
                    break
            if found:
                print(A, B)
            else:
                # If no such y, set A and B to G * x_min
                # print(A, A)
                print("-1 -1")

if __name__ == "__main__":
    main()