while True:
    n, d, v, k = input().split()
    n = int(n)
    d = float(d)
    v = float(v)
    k = int(k)

    if n < 0:
        break

    l = []

    for _ in range(k):
        a, b = input().split()
        a = int(a)
        b = float(b)
        l.append((a, b))

    prev_month = l[0][0]
    prev_depre = l[0][1]
    next_month = l[1][0] if k >= 2 else 1000000
    next_depre = l[1][1] if k >= 2 else 1
    depre_idx = 0

    car_price = v + d
    debt = v

    installment = v / n

    for i in range(n+1):
        if i >= prev_month and i < next_month:
            pass
        else:
            prev_month = next_month
            prev_depre = next_depre
            depre_idx += 1

            if depre_idx >= k:
                next_month = 10000000
            else:
                next_month = l[depre_idx][0]
                next_depre = l[depre_idx][1]

        car_price *= (1-prev_depre)

        if i != 0:
            debt -= installment

        if car_price > debt:
            month_str = 'month' if i == 1 else 'months'
            print('{:d} {:s}'.format(i, month_str))
            break

