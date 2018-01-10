#include <cstdio>

bool prime[1001000] = {false};

void gen_prime() {
    prime[0] = prime[1] = true;

    for(int i = 2; i <= 1e6; i++) {
        for(int j = 2; i*j <= 1e6; j++) {
            prime[i*j] = true;
        }
    }
}

int rev_num(int n) {
    int out = 0;

    while(n != 0) {
        out = out*10 + n % 10;
        n /= 10;
    }

    return out;
}

int main() {
    int n;
    gen_prime();

    while(scanf("%d", &n) == 1) {
        if(!prime[n]) {
            int rev = rev_num(n);
            if(!prime[rev] && rev != n) {
                printf("%d is emirp.\n", n);
            } else {
                printf("%d is prime.\n", n);
            }
        } else {
            printf("%d is not prime.\n", n);
        }
    }
}
