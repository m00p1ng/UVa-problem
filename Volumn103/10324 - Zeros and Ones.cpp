#include <cstdio>
#include <cstring>

int main() {
    char s[1000010];
    int q, a, b;

    int ts = 0;
    while(scanf("%s", s) == 1) {
        scanf("%d", &q);
        printf("Case %d:\n", ++ts);
        while(q--) {
            scanf("%d %d", &a, &b);
            if(a > b) {
                int temp = a;
                a = b;
                b = temp;
            }

            bool is_valid = true;
            for(int i = a; i < b; i++) {
                if(s[i] != s[i+1]) {
                    is_valid = false;
                    break;
                }
            }
            if(is_valid) puts("Yes");
            else puts("No");
        }
    }
}
