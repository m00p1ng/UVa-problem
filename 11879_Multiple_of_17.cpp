#include <cstdio>
#include <cstring>

int main() {
    char s[1000];
    while(scanf("%s", s), strcmp(s, "0")) {
        int len = strlen(s);
        int val = 0;
        for(int i = 0; i < len; i++) {
            val = (val*10 + (s[i]-'0')) % 17;
        }
        printf("%d\n", val == 0);
    }
}
