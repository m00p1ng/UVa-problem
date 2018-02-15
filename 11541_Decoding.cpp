#include <cstdio>
#include <cstring>
#include <cctype>

int main() {
    int ts;
    char s[10000], c, out[10000];
    int num, idx, len;
    scanf("%d", &ts);

    for(int t = 1; t <= ts; t++) {
        scanf("%s", s);
        len = strlen(s);
        idx = 0;

        printf("Case %d: ", t);
        while(idx < len) {
            num = 0;
            c = s[idx];
            idx++;
            while(isdigit(s[idx])) {
                num = num*10 + s[idx]-'0';
                idx++;
            }
            memset(out, c, num);
            printf("%s",out);
            memset(out, 0, num);
        }
        puts("");

    }
}
