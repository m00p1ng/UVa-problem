#include <cstdio>

bool is_prime[110];
int prime[100];
int s_p = 0;

void gen_prime() {
    for(int i = 2; i < 100; i++) {
        for(int j = 2; i*j < 100; j++) {
            is_prime[i*j] = true;
        }
        if(!is_prime[i]) {
            prime[s_p++] = i;
        }
    }
}

int get_factor(int n, int f) {
    int cnt = 0;
    int fac = f;
    while(fac <= n) {
        cnt += n/fac;
        fac *= f;
    }
    return cnt;
}

int main() {
    int n;
    gen_prime();
    
    while(scanf("%d", &n), n) {
        printf("%3d! =", n);

        int t = 0;
        for(int i = 0; i < 2; i++) {
            if(i == 1) printf("      ");
            for(int j = 0; j < 15 && t < 25 && prime[t] <= n; j++) {
                printf("%3d", get_factor(n, prime[t++]));
            }
            puts("");
            if(prime[15] > n) break;
        }
    }
}
