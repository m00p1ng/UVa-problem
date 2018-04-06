#include <cstdio>
#include <cstring>

bool is_prime[1010];
int len_prime[1010] = {0};
int prime[200];

void gen_prime() {
    int np = 1;
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    prime[0] = 1;
    len_prime[1] = 1;

    for(int i = 2; i <= 1000; i++) {
        len_prime[i] = len_prime[i-1];

        if(is_prime[i]) {
            prime[np++] = i;
            len_prime[i]++;
        }
        for(int j = 2; i*j <= 1000; j++) {
            is_prime[i*j] = false;
        }
    }
}

int main() {
    gen_prime();
    int n, c, k, diff;

    while(scanf("%d %d", &n, &c) == 2) {
        printf("%d %d:", n, c);
        k = 2*c - (len_prime[n]&1);
        if(k > len_prime[n]) k = len_prime[n];
        diff = (len_prime[n]-k)/2;

        for(int i = diff; i < diff+k; i++) {
            printf(" %d", prime[i]);
        }
        puts("\n");
    }
}
