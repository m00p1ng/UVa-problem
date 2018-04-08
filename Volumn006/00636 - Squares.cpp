#include <cstdio>
#include <cstring>
#include <cmath>

int base_convert(char* s, int base, int len) {
    int result = 0;
    for(int i = 0; i < len; i++) {
        result = result*base+s[i]-'0';
    }
    return result;
}

bool is_square(int n) {
    int sq = sqrt(n);
    return n == sq*sq;
}

int main() {
    char s[1000];
    while(scanf("%s", s), strcmp(s, "0")) {
        int len = strlen(s);
        int max = 0;
        for(int i = 0; i < len; i++) {
            if(s[i]-'0' > max) max = s[i]-'0';
        }

        int b = max+1;
        while(!is_square(base_convert(s, b, len))) b++; 
        printf("%d\n", b); 
    }
}
