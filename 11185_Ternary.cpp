#include <cstdio>
#include <cmath>

char* ternary(int n) {
    static char out[20];
    int len = floor(log(n)/log(3)+1e-8)+1;

    for(int i = len-1; i >= 0; i--) {
        out[i] = '0' + (n%3);
        n /= 3;
    }

    out[len] = '\0';
    return out;
}

int main() {
    int n;
    while(scanf("%d", &n), n >= 0) {
        if(n == 0) puts("0");
        else printf("%s\n", ternary(n));
    }
}
