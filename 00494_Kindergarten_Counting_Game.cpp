#include <cstdio>
#include <cstring>
#include <cctype>

int main() {
    char s[10000];
    while(fgets(s, 10000, stdin)) {
        int word = 0, i = 0;
        int len = strlen(s)-1;
        while(i < len) {
            if(isalpha(s[i])) {
                while(isalpha(s[i]) && i < len) i++;     
                word++;
            }
            while(!isalpha(s[i]) && i < len) i++; 
        }
        printf("%d\n", word);
    }
}
