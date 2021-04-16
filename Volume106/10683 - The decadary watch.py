while True:
    try:
        line = input()
    except:
        break

    sh = int(line[0:2])
    sm = int(line[2:4])
    ss = int(line[4:6])
    sc = int(line[6:8])

    total_c = (sh*60*60*100 + sm*60*100 + ss*100 + sc)
    total_c *= 10*100*100*100
    total_c /= (24*60*60*100)

    print('{:07d}'.format(int(total_c)))
