import datetime

months = {
    'January': 1,
    'February': 2,
    'March': 3,
    'April': 4,
    'May': 5,
    'June': 6,
    'July': 7,
    'August': 8,
    'September': 9,
    'October': 10,
    'November': 11,
    'December': 12
}

ts = int(input())

for tt in range(1, ts+1):
    line = input()
    n = int(input())
    y, m, d = line.split('-')
    x = datetime.datetime(int(y), months[m], int(d))
    x += datetime.timedelta(days=n)

    print('Case {:d}: {:s}'.format(tt, x.strftime("%Y-%B-%d")))
