#include <cstdio>
#include <cstring>

bool prime[1000001];
int num_prime[80000];
int np = 0;

void gen_prime() {
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false; 
    num_prime[np++] = 2;

    for(int i = 2; i < 500000; i++) prime[2*i] = false;
    for(int i = 3; i < 1000000; i+=2) {
        if(prime[i]) {
            num_prime[np++] = i;
            for(int j = 2; i*j <= 1000000; j++) {
                prime[i*j] = false;
            }
        }
    }
}

int main() {
    gen_prime();
    long long n, temp;
    int ts = false;
    while(scanf("%lld", &n), n > 0) {
        temp = n;
        int i = 0;

        while(temp > 1 && i < np) {
            while(temp % num_prime[i] == 0) {
                printf("    %d\n", num_prime[i]);
                temp /= num_prime[i];
            }
            i++;
        }
        if(temp != 1) printf("    %lld\n", temp);
        puts("");
    }
}
