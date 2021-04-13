import sys
import math

for line in sys.stdin.readlines():
    line = line.strip()

    if len(line) == 0:
        break

    max_dis = -1
    prev_pos = -1

    for i, c in enumerate(line):
        if c != 'X':
            continue

        if prev_pos == -1:
            distance = i - 1
        else:
            distance = math.ceil((i - prev_pos - 1)/2) - 1

        max_dis = max(max_dis, distance)
        prev_pos = i

    max_dis = max(max_dis, len(line) - prev_pos - 2)
    print(max_dis)
