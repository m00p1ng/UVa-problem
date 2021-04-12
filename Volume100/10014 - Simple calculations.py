ts = int(input())

for t in range(ts):
    _ = input()
    n = int(input())
    a_first = float(input())
    a_last = float(input())
    sum_c = 0

    for i in range(n):
        c = float(input())
        sum_c = sum_c + (n - i)*c

    result = (n*a_first + a_last - 2*sum_c)/(n + 1)

    if t:
        print()

    print("{:.2f}".format(round(result, 2)))
