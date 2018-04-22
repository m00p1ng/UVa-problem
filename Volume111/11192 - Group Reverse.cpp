#include <cstdio>
#include <cstring>

int main() {
    int n;
    char s[1000];
    while(scanf("%d", &n), n) {
        scanf("%s", s);
        int len = strlen(s);
        int c = len / n;

        for(int i = 0; i < n; i++) {
            for(int j = (i+1)*c-1; j >= i*c; j--) {
                printf("%c", s[j]);
            }
        }
        puts("");
    }
}
