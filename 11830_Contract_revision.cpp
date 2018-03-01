#include <cstdio>
#include <cstring>

int main() {
    char c, s[10000], out[10000];
    int len, idx, start;
    while(scanf(" %c %s", &c, s)) {
        if(c == '0' && s[0] == '0') break;
    
        len = strlen(s);
        start = idx = 0;

        for(int i = 0; i < len; i++) {
            if(s[i] != c) out[idx++] = s[i]; 
        }
        out[idx] = '\0';

        while(out[start] == '0') start++;
        if(start == idx) puts("0");
        else {
            for(int i = start; i < idx; i++) {
                printf("%c", out[i]);
            }
            puts("");
        }
    }
}
