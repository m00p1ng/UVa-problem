#include <cstdio>
#include <cstring>

bool prime[32000];
int num_prime[3500];
int num_sum[3500];
int np = 0;

int digit_sum(int n) {
    int sum = 0;
    while(n) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

void gen_prime() {
    memset(prime, true, sizeof(prime));
    for(int i = 2; i < 32000; i++) {
        if(prime[i]) {
            num_prime[np] = i;
            num_sum[np] = digit_sum(i);
            np++;
            for(int j = i+i; j < 32000; j+=i) {
                prime[j] = false;
            }
        }
    }
}

int factor_sum(int n) {
    int sum = 0, i = 0, k;
    while(i < np && num_prime[i] < n) {
        k = num_prime[i];
        while(n % k == 0) {
            sum += num_sum[i];
            n /= k;
        }
        i++;
    }
    if(n != 1 && sum != 0) {
        sum += digit_sum(n);
    }
    return sum;
}

int main() {
    gen_prime();
    int ts, n;
    scanf("%d", &ts);
    while(ts--) {
        scanf("%d", &n);
        for(int i = n+1;; i++) {
            if(digit_sum(i) == factor_sum(i)) {
                printf("%d\n", i);
                break;
            }
        }
    }
}
