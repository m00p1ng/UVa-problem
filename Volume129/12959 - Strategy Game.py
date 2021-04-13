while True:
    try:
        tmp = input()
        tmp1 = input()
    except EOFError:
        break

    j, r = [int(i) for i in tmp.split(' ')]
    scores = [int(i) for i in tmp1.split(' ')]

    sums = [0]*j

    for i in range(len(scores)):
        idx = i % j
        sums[idx] += scores[i]

    max_score = -1
    max_idx = None

    for i in range(j-1, -1, -1):
        if sums[i] > max_score:
            max_score = sums[i]
            max_idx = i

    print(max_idx+1)
