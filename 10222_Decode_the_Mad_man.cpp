#include <cstdio>
#include <cstring>
#include <cctype>

char table[256];

void gen_table() {
    const char input[] = " qwertyuiop[]asdfghjkl;'zxcvbnm,./";
    const char out[]   = "   qwertyuiop  asdfghjkl  zxcvbnm,./";
    
    for(int i = 0; i < strlen(input); i++) {
        table[128+input[i]] = out[i];
    }
}


int main() {
    gen_table();
    char buff[1002];
    while(fgets(buff, 1002, stdin)) {
        for(int i = 0; i < strlen(buff)-1; i++) {
            char b = tolower(buff[i]);
            putchar(table[128+b]);
        }
        puts("");
    }
}

