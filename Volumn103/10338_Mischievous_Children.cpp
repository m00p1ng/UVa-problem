#include <cstdio>
#include <cstring>

long long fac[21];
void gen_fac() {
    fac[0] = fac[1] = 1;
    for(int i = 2; i <= 20; i++) {
        fac[i] = fac[i-1]*i;
    }
}

int main() {
    gen_fac();
    int ts, freq[26];
    char s[100];
    long long result;
    scanf("%d", &ts);
    for(int t = 1; t <= ts; t++) {
        scanf("%s", s); 
        int len = strlen(s);
        memset(freq, 0, sizeof(freq));

        result = fac[len];
        for(int i = 0; i < len; i++) result /= ++freq[s[i]-'A']; 
        printf("Data set %d: %lld\n", t, result);
    }
}
