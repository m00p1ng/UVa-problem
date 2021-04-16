ts = int(input())

for _ in range(ts):
    n, m = [int(i) for i in input().split()]
    s = n + m
    base = s*(s + 1)/2 + 1

    print('{:.0f}'.format(base + n))
