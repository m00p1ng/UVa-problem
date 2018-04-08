#include <cstdio>
#include <cstring>

bool prime[2010];

void gen_prime() {
    memset(prime, 1, sizeof(prime));
    prime[0] = prime[1] = false;
    for(int i = 2; i <= 2001; i++) {
        for(int j = 2; i*j <= 2001; j++) {
            prime[i*j] = false;
        }
    }
}

int main() {
    gen_prime();
    int ts;
    char s[2010];
    int freq[200];
    scanf("%d", &ts);

    for(int t = 1; t <= ts; t++) {
        scanf("%s", s);
        int len = strlen(s);

        memset(freq, 0, sizeof(freq));
        for(int i = 0; i < len; i++) {
            freq[s[i]]++;
        }
        printf("Case %d: ", t);
        bool is_emp = true;
        for(int i = 32; i < 128; i++) {
            if(freq[i] != 0 && prime[freq[i]]) {
                putchar((char)i);
                is_emp = false;
            }
        }
        if(is_emp) printf("empty");
        puts("");
    }
}
