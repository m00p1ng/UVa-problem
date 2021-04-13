ts = int(input())

for t in range(1, ts+1):
    tmp = input()
    n, l = [int(i) for i in tmp.split(' ')]

    tmp = input()
    mn = [int(i) for i in tmp.split(' ')]

    tmp = input()
    ml = [int(i) for i in tmp.split(' ')]

    can_win = True
    if sum(mn) > l:
        can_win = False

    for i, j in zip(mn, ml):
        if i > j:
            can_win = False
            break

    print('Case %d: %s' % (t, 'Yes' if can_win else 'No'))

