#include <cstdio>
#include <cstring>

int bigmod(int b, int n, int k) {
    if(n == 1) return b;

    long long e = bigmod(b, n/2, k) %k;

    if(n & 1) return b*e*e % k;
    else return e*e % k;
}

bool prime[65100];

void gen_prime() {
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;
    for(int i = 2; i <= 65000; i++) {
        if(prime[i]) {
            for(int j = 2; i*j <= 65000; j++) {
                prime[i*j] = false;
            }
        }
    }
}

bool check_prime(int n) {
    for(int i = 2; i <= n-1; i++) {
        if(bigmod(i, n, n) != i) return false;
    }
    return true;
}

int main() {
    gen_prime();
    int n;
    while(scanf("%d", &n), n) {
        if(!prime[n] && check_prime(n)) {
            printf("The number %d is a Carmichael number.\n", n);
        } else {
            printf("%d is normal.\n", n);
        }
    }
}
