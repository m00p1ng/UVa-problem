#include <cstdio>
#include <cstring>

bool is_prime[10000010];
int prime[670000];
int np = 0;
int pos[4];
bool first_found;

void gen_prime() {
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    prime[np++] = 2;

    for(int i = 2; i <= 5000000; i++) is_prime[2*i] = false;

    for(int i = 3; i <= 10000000; i++) {
        if(is_prime[i]) {
            prime[np++] = i;
            for(int j = 2; i*j <= 10000000; j++) {
                is_prime[i*j] = false;
            }
        }
    }
}

void print_prime() {
    printf("%d %d %d %d\n", prime[pos[0]], prime[pos[1]], prime[pos[2]], pos[3]);
}

void sum_prime(int depth, int remain) {
    if(depth == 3) {
        if(is_prime[remain]) {
            pos[3] = remain;
            print_prime();
            first_found = true;
        }
        return;
    }
    int diff;
    for(int i = 0; prime[i] <= remain; i++) {
        pos[depth] = i;
        diff = remain - prime[i];
        if(diff < 0) return;    
        if(!first_found) sum_prime(depth+1, diff);
    }
}

int main() {
    gen_prime();
    int n;

    while(scanf("%d", &n) == 1) {
        memset(pos, 0, sizeof(pos));
        first_found = false;
        sum_prime(0, n);
        if(!first_found) puts("Impossible.");    
    }
}

