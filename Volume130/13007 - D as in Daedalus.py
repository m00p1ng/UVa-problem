import math

while True:
    try:
        n, k = [int(i) for i in input().split()]
    except:
        break

    total = 0
    old_point = 0
    for _ in range(k):
        b, *v = [int(i) for i in input().split()]

        if sum(v) <= b:
            old_point += v[0]

        remain = b - sum(v[1:])
        if remain <= 0:
            continue

        digit = min(4, math.floor(math.log10(remain)))
        total += 10 ** digit

    print(total - old_point)
