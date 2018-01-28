#include <cstdio>
#include <cstring>

int main() {
    char num[] = "22233344455566677778889999";
    char s[100];
    while(scanf("%s", s) == 1) {
        for(int i = 0; i < strlen(s); i++) {
            if(s[i] >= 'A' && s[i] <= 'Z') putchar(num[s[i]-'A']);
            else putchar(s[i]);
        }
        puts("");
    }
}
