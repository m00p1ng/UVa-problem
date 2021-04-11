import math
import sys

def price(p, a, b, c, d, k):
    return p*(math.sin(a*k + b) + math.cos(c*k + d) + 2)

def main():
    for line in sys.stdin.readlines():
        p, a, b, c, d, n = [int(i) for i in line.split(' ')]

        max_num = -math.inf
        max_diff = 0

        for i in range(1, n + 1):
            val = price(p, a, b, c, d, i)
            diff = max_num - val

            if diff > max_diff:
                max_diff = diff
            if val > max_num:
                max_num = val

        print(max_diff)

if __name__ == '__main__':
    main()
