#include <cstdio>
#include <cstring>
#include <cmath>

int main() {
    char s[100];
    int ts;
    scanf("%d", &ts);
    for(int i = 0; i < ts; i++) {
        scanf("%s", s);
        int len = strlen(s);
        int a = 0, num = 0;

        for(int i = 0; i < len; i++) {
            a += pow(s[i]-'0', len);
            num = num*10 + s[i]-'0';
        }
        if(num == a) puts("Armstrong");
        else puts("Not Armstrong");
    }
}
