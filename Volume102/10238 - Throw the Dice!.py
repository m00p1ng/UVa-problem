import sys

ans = []

def gen_event(f, n, s, rnd, total, arr):
    if total > s:
        return 0

    if n == rnd:
        return total == s

    global ans
    if ans[rnd][total] is not None:
        print(f'{rnd=}, {total}')
        return ans[rnd][total]

    total_event = 0;

    for i in range(1, f+1):
        arr1 = arr.copy()
        arr1.append(i)
        total_event += gen_event(f, n, s, rnd+1, total+i, arr1)

    ans[rnd][total] = total_event
    return total_event


def main():
    for line in sys.stdin.readlines():
        f, n, s = [int(i) for i in line.split(' ')]

        global ans
        ans = [[None for _ in range(s+1)] for _ in range(n+1)]

        result = gen_event(f, n, s, 0, 0, []);
        print("{:d}/{:d}".format(result, f ** n));


if __name__ == '__main__':
    main()
