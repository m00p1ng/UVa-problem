n = int(input())
line = ""

for i in range(5):
    l = input()

    if i == 3:
        line = l

chars = [line[4*i:4*i+3] for i in range(n)]

out = ""

for c in chars:
    if c == ".*.":
        out = out + "1"
    elif c == "*..":
        out = out + "2"
    else:
        out = out + "3"

print(out)
