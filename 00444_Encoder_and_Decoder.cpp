#include <cstdio>
#include <cctype>
#include <cstring>

void encode(char* s, int len) {
    int i = len-1;
    while(i >= 0) {
        printf("%d%d", s[i] % 10, (s[i]/10)%10);
        if(s[i] >= 100) printf("1"); 
        i--;
    }
}

void decode(char* s, int len) {
    int i = len-1, c;
    while(i >= 0) {
        c = 0;
        if(s[i] == '1') {
            c = 100;
            i--;
        }
        c += s[i]*10 + s[i-1] - 11*'0';
        i-=2;
        printf("%c", c);
    } 
}

int main() {
    char s[10000];
    int len;

    while(fgets(s, 10000, stdin)) {
        int len = strlen(s)-1;
        if(isdigit(s[0])) decode(s, len); 
        else encode(s, len); 
        puts("");
    }
}
