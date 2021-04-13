import sys

for line in sys.stdin.readlines():
    line = line.strip()
    next_0 = 0

    sz = len(line)
    cnt_0 = line.count('0')

    for i in range(sz):
        if line[i] == '1':
            continue

        if line[(i+1)%sz] == '0':
            next_0 += 1

    prop_shoot = 0 if cnt_0 == 0 else next_0/cnt_0
    prop_rotate = cnt_0/sz

    if prop_shoot == prop_rotate:
        print('EQUAL')
    elif prop_shoot > prop_rotate:
        print('SHOOT')
    else:
        print('ROTATE')

