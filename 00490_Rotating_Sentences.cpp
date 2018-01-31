#include <cstdio>
#include <cstring>

int main() {
    char s[110][110];
    memset(s, ' ', sizeof(s));

    int idx = 0;
    int max = -1;
    while(fgets(s[idx], 110, stdin)) {
        int len = strlen(s[idx])-1;
        s[idx][len+1] = s[idx][len] = ' ';
        if(len > max) max = len;
        idx++;
    }

    for(int j = 0; j < max; j++) {
        for(int i = idx-1; i >= 0; i--) {
            putchar(s[i][j]);
        }
        puts("");
    }
}
