#include <cstdio>
#include <cstring>

bool prime[32];
int pos[32], n;

void gen_prime() {
    memset(prime, true, sizeof(prime));

    for(int i = 2; i <= 30; i++) {
        if(prime[i]) {
            for(int j = 2; j <= 30; j++) {
                prime[i*j] = false;
            }
        }
    }
}

void print_num() {
    printf("1");
    for(int i = 1; i < n; i++) {
        printf(" %d", pos[i]);
    }
    puts("");
}

void dfs(int d, int vis) {
    if(d == n-1) {
        if(prime[1+pos[n-1]]) {
            print_num(); 
        }
        return;
    }
    for(int i = 2; i <= n; i++) {
        if(prime[i+pos[d]] && ((vis >> i) & 1) == 0) {
            vis |= 1 << i;
            pos[d+1] = i;
            dfs(d+1, vis);
            vis &= ~(1 << i);
        }
    }
}

int main() {
    gen_prime();
    int ts = 0;
    pos[0] = 1;
    while(scanf("%d", &n) == 1) {
        if(ts) puts("");
        printf("Case %d:\n", ++ts);
        dfs(0, 1<<1);
    }
}
