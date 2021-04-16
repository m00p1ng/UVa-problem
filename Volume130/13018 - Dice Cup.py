is_first = True
while True:
    try:
        line = input().split()
    except:
        break

    n, m = [int(i) for i in line]

    props = [0]*100
    max_num = 0

    for i in range(1, n+1):
        for j in range(1, m+1):
            props[i+j] += 1
            max_num = max(max_num, props[i+j])

    if is_first:
        is_first = False
    else:
        print()

    for i in range(1, n+m):
        if props[i] == max_num:
            print(i)
