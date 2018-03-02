#include <cstdio>
#include <cstring>
#include <cctype>

int main() {
    int b, t, len, n, idx;
    long long temp;
    char s[1000], out[1000];
    bool is_valid;

    while(scanf("%d %d %s", &b, &t, s) == 3) {
        temp = 0;
        len = strlen(s);
        is_valid = true;

        for(int i = 0; i < len; i++) {
            temp = temp*b;

            n = isdigit(s[i]) ? s[i]-'0' : s[i]-'A'+10;
            if(b <= n) { is_valid = false; break; }
            temp += isdigit(s[i]) ? s[i]-'0' : s[i]-'A'+10;
        }

        if(is_valid) {
            memset(out, 0, sizeof(out));
            idx = 0;

            if(temp == 0) out[idx++] = '0';
            while(temp) {
                int result = temp % t;
                out[idx++] = result < 10 ? '0' + result : 'A' + result-10;
                temp /= t;
            }
            printf("%s base %d = ", s, b);
            for(int i = idx-1; i >= 0; i--) printf("%c", out[i]);
            printf(" base %d\n", t);
        } else printf("%s is an illegal base %d number\n", s, b);
    }
}

