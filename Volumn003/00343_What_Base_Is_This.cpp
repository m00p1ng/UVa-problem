#include <cstdio>
#include <cstring>
#include <cctype>

int start_base(char *s) {
    char c = 0;
    int len = strlen(s);

    for(int i = 0; i < len; i++) {
        if(s[i] > c) {
            c = s[i];
        }
    }
    
    if(isalpha(c)) {
        return 10 + c - 'A';
    } else {
        return c - '0';
    }
}

int conv_base(char* s, int b) {
    int result = 0;
    int len = strlen(s);

    for(int i = 0; i < len; i++) {
        result *= b;
        if(isdigit(s[i])) {
            result += s[i] - '0';
        } else {
            result += 10 + s[i] - 'A';
        }
    }

    return result;
}

int main() {
    char a[1000], b[1000];
    int sa, sb, ba, bb;
    while(scanf("%s %s", a, b) == 2) {
        sa = start_base(a);
        sb = start_base(b);
        if(sa == 0) sa = 1;
        if(sb == 0) sb = 1;

        bool is_valid = false;
        for(int i = sa+1; i <= 36 && !is_valid; i++) {
            for(int j = sb+1; j <= 36 && !is_valid; j++) {
                if(conv_base(a, i) == conv_base(b, j)) {
                    is_valid = true;
                    ba = i;
                    bb = j;
                }
            }
        }
        if(is_valid) {
            printf("%s (base %d) = %s (base %d)\n", a, ba, b, bb);
        } else {
            printf("%s is not equal to %s in any base 2..36\n", a, b);
        }
    }
}
