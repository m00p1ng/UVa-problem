#include <cstdio>

int main() {
    int n, q;
    int a, b, c, cnt;
    int course[100];

    while(scanf("%d %d", &n, &q) == 2) {
        bool flag[10000] = {0};
        
        for(int i = 0; i < n; i++) {
            scanf("%d", &c);
            flag[c] = true;
        }

        bool is_valid = true;
        for(int i = 0; i < q; i++) {
            cnt = 0;
            scanf("%d %d", &a, &b);
            for(int j = 0; j < a; j++) {
                scanf("%d", &course[j]);
                cnt += flag[course[j]];
            }
            is_valid &= cnt >= b;
        }
        if(is_valid) puts("yes");
        else puts("no");
    }
}
