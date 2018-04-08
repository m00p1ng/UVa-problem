#include <cstdio>

int main() {
    int ts, n, q;
    scanf("%d", &ts);
    int data[30000];
    while(ts--) {
        scanf("%d %d", &n, &q);
        for(int i = 0; i < n; i++) scanf("%d", &data[i]);

        int idx, cnt = 0, p = 0;
        for(int i = 0; i < q; i++) {
            scanf("%d", &idx);

            for(int j = p; j < idx; j++) {
                for(int k = j; k > 0; k--) {
                    if(data[k-1] > data[k]) {
                        int temp = data[k];
                        data[k] = data[k-1];
                        data[k-1] = temp;
                    } else break;
                }
            }
            printf("%d\n", data[cnt++]);
            p = idx - 1;
        }
        if(ts) puts("");
    }
}
