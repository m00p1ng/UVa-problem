#include <cstdio>

int main() {
    int ts, n;
    scanf("%d", &ts);
    for(int t = 1; t <= ts; t++) {
        scanf("%d", &n);
        int idx = n/2;
        int mid, temp;
        for(int i = 0; i < n; i++) {
            scanf("%d", &temp);
            if(i == idx) mid = temp;
        }
        printf("Case %d: %d\n", t, mid);
    }
}
