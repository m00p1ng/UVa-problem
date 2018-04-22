#include <cstdio>
#include <cstring>

bool prime[2500000];
int num_prime[200000];
int np = 0;

void gen_prime() {
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;
    num_prime[np++] = 2;

    for(int i = 4; i < 2500000; i+=2) prime[i] = false;
    for(int i = 3; i < 2500000; i+=2) {
        if(prime[i]) {
            num_prime[np++] = i;
            for(int j = i+i; j < 2500000; j+=i) {
                prime[j] = false;
            }
        }
    }
}

int main() {
    long long n;
    gen_prime();
    while(scanf("%lld", &n), n) {
        bool found = false;
        long long max_div = -1;
        long long abs_n = n > 0 ? n : -n;
        int cnt = 0;
        
        for(int i = 0; i < np && num_prime[i] <= abs_n; i++) {
            if(abs_n % num_prime[i] == 0) {
                max_div = num_prime[i];
                cnt++;
                while(abs_n % max_div == 0) {
                    abs_n /= max_div;
                }
                //printf("num_prime[i] = %d; n = %lld\n", num_prime[i], n);
            }
        }

        if(cnt == 1) max_div = -1;
        if(abs_n != 1 && cnt != 0) max_div = abs_n;
        printf("%lld\n", max_div);
    }
}
