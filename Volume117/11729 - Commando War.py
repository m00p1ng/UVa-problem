ts = 0

while True:
    n = int(input())

    if n == 0:
        break

    l = []
    for i in range(n):
        b, j = [int(i) for i in input().split()]
        l.append((b,j))

    l = sorted(l, key = lambda x: x[1], reverse = True)

    cum_tell = 0
    total_time = 0
    for (b, j) in l:
        new_total = cum_tell + b + j
        total_time = max(total_time, new_total)
        cum_tell += b

    ts += 1
    print("Case {:d}: {:d}".format(ts, total_time))
