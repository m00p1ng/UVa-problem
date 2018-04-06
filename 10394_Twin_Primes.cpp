#include <cstdio>
#include <cstring>

bool is_prime[20000000];
int prime_pair[100000][2];
int np = 0;
int pp = 0;

void gen_prime() {
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    int prev = 2;
    
    for(int i = 2; i < 10000000; i++) is_prime[2*i] = false; 

    for(int i = 3; i < 20000000 && pp <= 100000; i++) {
        if(is_prime[i]) {
            if(i - prev == 2) {
                prime_pair[pp][0] = prev;
                prime_pair[pp][1] = i;
                pp++;
            }
            prev = i;
            for(int j = 2; i*j < 20000000; j++) {
                is_prime[i*j] = false;
            }
        }
    }
}

int main() {
    gen_prime();

    int n;
    while(scanf("%d", &n) == 1) {
        printf("(%d, %d)\n", prime_pair[n-1][0], prime_pair[n-1][1]);
    }
}
