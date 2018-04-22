#include <cstdio>
#include <cstring>

char a[] = "A   3  HIL JM O   2TUVWXY5";
char n[] = " 1SE Z  8 ";

char map_char(char c) {
    if('A' <= c && c <= 'Z') return a[c - 'A'];
    return n[c - '0'];
}

int main() {
    char s[1000];
    while(scanf("%s", s) == 1) {
        int len = strlen(s);
        bool is_palin = true, is_mir = true;

        for(int i = 0; i <= len/2; i++) {
            if(s[i] != map_char(s[len-i-1])) is_mir = false;
            if(s[i] != s[len-1-i]) is_palin = false;
        }

        printf("%s -- is ", s);
        if(is_palin && is_mir) puts("a mirrored palindrome.");
        else if(is_palin) puts("a regular palindrome.");
        else if(is_mir) puts("a mirrored string.");
        else puts("not a palindrome.");
        puts("");
    }
}
