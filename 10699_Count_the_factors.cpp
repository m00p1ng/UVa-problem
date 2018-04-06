#include <cstdio>
#include <cstring>

int num_prime[100000];
int np = 0;

void gen_prime() {
    bool prime[1000000];
    memset(prime, true, sizeof(prime));

    num_prime[np++] = 2;

    for(int i = 2; i < 500000; i++) prime[2*i] = false;
    for(int i = 3; i < 1000000; i+=2) {
        if(prime[i]) {
            num_prime[np++] = i;
            for(int j = 2; i*j < 1000000; j++) {
                prime[i*j] = false;
            }
        }
    }
}

int main() {
    gen_prime();

    int n, temp;
    while(scanf("%d", &n), n) {
        temp = n;
        int i = 0, cnt = 0;
        while(temp > 1 && i < np) {
            if(temp % num_prime[i] == 0) {
                cnt++;
                while(temp % num_prime[i] == 0) {
                    temp /= num_prime[i];
                }
            }
            i++;
        }
        printf("%d : %d\n", n, cnt);
    }
}
