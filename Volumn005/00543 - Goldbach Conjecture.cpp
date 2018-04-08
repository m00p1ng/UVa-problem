#include <cstdio>

bool prime[1000000] = {false};

void gen_prime() {
    for(int i = 3; i <= 1000; i+=2) {
        for(int j = 2; i*j < 1000000; j++) {
            prime[i*j] = true;
        }
    }
}

int main() {
    gen_prime();
    int n, i;
    while(scanf("%d", &n), n) {
        i = 3;
        while((prime[i] || prime[n-i]) && 2*i <= n+1) i+=2; 
        printf("%d = %d + %d\n", n, i, n-i);
    }
}
