#include <cstdio>
#include <cstring>

int main() {
    char s[100000];

    while(fgets(s, 100000, stdin)) {
        int i = 0, j = 0;
        int len = strlen(s)-1;
        while(i < len && j < len) {
            while(s[i] == ' ') {
                putchar(' ');
                i++;
            }
            j = i;
            while(s[j] != ' ' && j < len) j++;
            for(int k = j-1; k >= i; k--) putchar(s[k]);
            i = j;
        }
        puts("");
    }
}
