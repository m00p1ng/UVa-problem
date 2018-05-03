#include <cstdio>
#include <cstring>

typedef unsigned long long ull;
bool prime[32000];
int num_prime[3500];
int np = 0;

void gen_prime() {
    memset(prime, true, sizeof(prime));
    num_prime[np++] = 2;

    for(int i = 4; i < 32000; i += 2) prime[i] = false;
    for(int i = 3; i < 32000; i += 2) {
        if(prime[i]) {
            num_prime[np++] = i;
            for(int j = i+i; j < 32000; j += i) {
                prime[j] = false;
            }
        }
    }
}

bool is_prime(int n) {
    for(int i = 0; i < np; i++) {
        int num = num_prime[i];
        if(num*num > n) break;
        if(n % num == 0) return false;
    }
    return true;
}

ull bigmod(ull a, ull p, ull m) {
    if(p == 0) return 1;

    if(p % 2 == 0) {
        ull num = bigmod(a, p/2, m);
        return num*num % m;
    } else {
        return (a * bigmod(a, p-1, m)) % m;
    }
}

int main() {
    gen_prime();
    ull p, a;
    while(scanf("%lld %lld", &p, &a), p || a) {
        if(!is_prime(p) && bigmod(a, p, p) == a) {
            puts("yes"); 
        } else {
            puts("no");
        }
    }
}
