#include <cstdio>
#include <cctype>
#include <cstring>

bool isvowel(char c) {
    switch(tolower(c)) {
        case 'a': case 'e': case 'i': case 'o': case 'u':
            return true; break;
    }
    return false;
}

int main() { 
    char s, c;
    while(1) {
        s = getchar();
        if(s == EOF) break;

        if(isalpha(s)) {
            c = '#';

            if(!isvowel(s)) {
                c = s; 
                s = getchar();
            }
            while(isalpha(s)) {
                putchar(s); 
                s = getchar();
            }
            if(c != '#') putchar(c);
            printf("ay");

        }
        putchar(s); 
    }
}
