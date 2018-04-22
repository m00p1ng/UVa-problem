#include <cstdio>
#include <cstring>

bool prime[47000];
int num_prime[5500];
int np = 0;

void gen_prime() {
    memset(prime, true, sizeof(prime));

    for(int i = 2; i < 47000; i++) {
        if(prime[i]) {
            num_prime[np++] = i;
            for(int j = i+i; j < 47000; j+= i) {
                prime[j] = false;
            }
        }
    }
}

int main() {
    int n;
    int abs_n;
    gen_prime();

    while(scanf("%d", &n), n) {
        abs_n = n > 0 ? n : -n;
        bool first = true;
        printf("%d =", n);
        if(n < 0) printf(" -1 x");

        int i = 0, cur;
        while(abs_n > 1 && i < np) {
            cur = num_prime[i];
            while(abs_n % cur == 0) {
                if(first) first = false;
                else printf(" x");

                printf(" %d", cur);
                abs_n /= cur;
            }
            i++;
        }
        if(abs_n != 1) {
            if(!first) printf(" x");
            printf(" %d", abs_n);
        }
        puts("");
    }
}
