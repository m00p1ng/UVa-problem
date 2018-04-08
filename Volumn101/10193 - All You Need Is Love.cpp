#include <cstdio>
#include <cstring>

int bin_convert(char* s) {
    int sum = 0;
    int len = strlen(s);

    for(int i = 0; i < len; i++) {
        sum = (sum << 1) + (s[i] == '1');
    }
    return sum;
}

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int ts;
    char a[100], b[100];
    int sa, sb;
    scanf("%d", &ts);
    for(int t = 1; t <= ts; t++) {
        scanf("%s %s", a, b); 
        sa = bin_convert(a);
        sb = bin_convert(b);

        printf("Pair #%d: ", t);
        if(gcd(sa, sb) == 1) {
            puts("Love is not all you need!");
        } else {
            puts("All you need is love!");
        }
    }
}
