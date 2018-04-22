#include <cstdio>
#include <cstring>
#include <cctype>

int char2digit(char c) {
    if(isdigit(c)) return c - '0';
    return c - 'A'+ 10;
}

char digit2char(int n) {
    if(n >= 10) return 'A' + n - 10;
    return '0' + n;
}

int main() {
    int b, t;
    char n[10];
    while(scanf("%s %d %d", n, &b, &t) == 3) {
        int len = strlen(n);
        int temp = 0;
        for(int i = 0; i < len; i++) {
            temp = temp*b + char2digit(n[i]);
        }
        int idx = 0;
        char out[10];
        while(temp) {
            out[idx++] = digit2char(temp % t);
            temp /= t;
        }

        if(idx > 7) puts("  ERROR");
        else {
            if(idx > 0) {
                for(int i = 6; i >= idx; i--) printf(" ");
                while(idx > 0) printf("%c", out[--idx]);
                puts("");
            }
            else puts("      0");
        }
    }
}

