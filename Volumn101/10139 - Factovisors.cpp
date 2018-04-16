#include <cstdio>
#include <cstring>

bool prime[47000];
int num_prime[5200];
int np = 0;

void gen_prime() {
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;
    num_prime[np++] = 2;

    for(int i = 2; i < 47000; i++) {
        if(prime[i]) {
            num_prime[np++] = i;
            for(int j = 2; i*j < 47000; j++) {
                prime[i*j] = false;
            }
        }
    }
}

int find_fac(int n, int k) {
    int cnt = 0;
    int temp = k;

    while(temp <= n && temp > 0) {
        cnt += n/temp;
        temp *= k;
    }
    return cnt;
}

bool can_divide(int n, int k) {
    if(n == 0) return k == 1 || k == 0;
    if(k == 0 || n >= k) return true;
    if(n < 3 && k > n) return false;

    for(int i = 0; i < np && k > 1; i++) {
        int cur_prime = num_prime[i];
        if(k % cur_prime == 0) {
            int fac = find_fac(n, cur_prime);
            int cnt = 0;
            while(k % cur_prime == 0) {
                cnt++;
                k /= cur_prime;
            }
            if(fac < cnt) return false;
        }
    }
    if(k != 1 && k > n) return false;
    return true;
}

int main() {
    gen_prime();
    int n, k;
    while(scanf("%d %d", &n, &k) == 2) {
        if(can_divide(n, k)) {
            printf("%d divides %d!\n",k, n);
        } else {
            printf("%d does not divide %d!\n",k, n);
        }
    }
}
