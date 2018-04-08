#include <cstdio>
#include <cstring>
#include <cmath>

int main() {
    char s[8000000];
    while(fgets(s, 8000000, stdin)) {
        int max_space = 0,  cur = 0;
        int len = strlen(s) - 1;
        if(len == 0) break;
        for(int i = 0; i < len; i++) {
            if(s[i] == ' ') {
                cur++; 
            }
            else {
                if (cur > max_space) {
                    max_space = cur;
                }
                cur = 0;
            }
        }
        int result = ceil(log2(max_space));
        printf("%d\n", result);
    }
}
