#include <cstdio>
#include <cstring>
#include <cctype>

int count_len(char *s) {
    int cnt = 0;
    int len = strlen(s);
    for(int i = 0; i < len; i++) {
        if(s[i] == '-' || isalpha(s[i])) cnt++;
    }
    return cnt;
}

int main() {
    char s[120], ans[120];
    int long_word = 0, cnt_len;
    while(scanf("%s", s), strcmp(s, "E-N-D")) {
        cnt_len = count_len(s);
        if(cnt_len > long_word) {
            long_word = cnt_len;
            strcpy(ans, s);
        }
    }
    for(int i = 0; i < strlen(ans); i++) {
        if(isalpha(ans[i]) || ans[i] == '-') putchar(tolower(ans[i]));
    }
    puts("");
}
