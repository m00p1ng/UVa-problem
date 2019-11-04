#include <cstdio>

int main() {
    int ts, n;
    char s[200];
    scanf("%d", &ts);

    for(int t = 1; t <= ts; t++) {
        scanf("%d", &n);
        scanf("%s", s);
        int cnt = 0;

        for(int i = 0; i < n; i++) {
            if(s[i] == '.') {
                cnt++;
                i += 2;
            }
        }

        printf("Case %d: %d\n", t, cnt);
    }
}
