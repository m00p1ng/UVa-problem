#include <cstdio>

bool prime[32770] = {false};

void gen_prime() {
    prime[0] = prime[1] = true;

    for(int i = 2; i <= 32768; i++) {
        if(!prime[i]) {
            for(int j = 2; i*j <= 32768; j++) {
                prime[i*j] = true;
            }
        }
    }
}

int main() {
    gen_prime();

    int n, cnt;
    while(scanf("%d", &n), n) {
        cnt = 0; 
        for(int i = 3; i <= n>>1; i+=2) {
            if(!prime[i] && !prime[n-i]) cnt++;
        }
        if(n == 4) cnt = 1;
        printf("%d\n", cnt);
    }
}
