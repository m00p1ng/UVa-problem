#include <cstdio>

int abs(int n) {
    return n > 0 ? n : -n;
}

int main() {
    int ts, n, m;
    char s[100];
    scanf("%d", &ts);
    while(ts--) {
        scanf("%3s-%d", s, &n);
        m = (s[0]-'A')*676 + (s[1]-'A')*26 + (s[2]-'A');
        if(abs(n-m) <= 100) puts("nice");
        else puts("not nice");
    }
}
