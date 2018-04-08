#include <cstdio>

bool not_prime[500000] = {false};

void gen_prime() {
    not_prime[0] = not_prime[1] = true;
    for(int i = 2; i <= 500000; i++) {
        for(int j = 2; i*j <= 500000; j++) {
            not_prime[i*j] = true;
        }
    }
}

bool is_prime(int n) {
    for(int i = 2; i*i <= n; i++) {
        if(!not_prime[i] && n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    gen_prime();
    int n, i;

    while(scanf("%d", &n), n) {
        bool is_valid = false;
        for(i = 2; i <= n/2; i++) {
            if(!not_prime[i] && is_prime(n-i)) {
                is_valid = true;
                break;
            }
        }
        printf("%d:\n", n);
        if(is_valid) {
            printf("%d+%d\n", i, n-i);
        } else {
            puts("NO WAY!");
        }
    }
}
