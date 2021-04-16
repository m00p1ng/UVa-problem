fibo = [1]*100

def gen_fibo():
    global fibo
    for i in range(2, 100):
        fibo[i] = fibo[i-1] + fibo[i-2]


gen_fibo()

while True:
    n = int(input())

    if n == 0:
        break

    print(fibo[n])
