#include <cstdio>
#include <cctype>
#include <cstring>

int main() {
    char s[1000];
    while(fgets(s, 1000, stdin)) {
        int len = strlen(s);
        int i = 0;
        while(i < len) {
            int num = 0;
            while(isdigit(s[i])) num += s[i++]-'0'; 
            
            if(s[i] == 'b') s[i] = ' ';
            for(int k = 0; k < num; k++) putchar(s[i]); 

            i++;
            if(s[i] == '!') puts("");
        }
        puts("");
    }
}
