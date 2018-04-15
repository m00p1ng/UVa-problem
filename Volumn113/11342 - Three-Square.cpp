#include <cstdio>

int sq[225], ans[50010][4] = {0};

void gen_ans() {
    for(int i = 0; i < 225; i++) sq[i] = i*i;

    for(int i = 0; i < 225; i++) {
        for(int j = i; sq[i]+sq[j] < 50000; j++) {
            for(int k = j; sq[i]+sq[j]+sq[k] <= 50000; k++) {
                int sum = sq[i]+sq[j]+sq[k];
                if(ans[sum][0]) continue;
                ans[sum][0] = 1;
                ans[sum][1] = i;
                ans[sum][2] = j;
                ans[sum][3] = k;
            }
        }
    }
}

int main() {
    gen_ans();
    int ts, n;
    scanf("%d", &ts);
    while(ts--) {
        scanf("%d", &n);

        if(ans[n][0]) {
            printf("%d %d %d\n", ans[n][1], ans[n][2], ans[n][3]);
        } else {
            puts("-1");
        }
    }
}
