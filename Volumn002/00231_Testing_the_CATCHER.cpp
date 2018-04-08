#include <cstdio>

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n;
    int num[40000];
    int cnt[40000];
    int idx = 0;
    int rnd = 0;
    int max = 0;

    while(scanf("%d", &n) == 1) {
        if(n != -1) {
            num[idx] = n;
            cnt[idx] = 0;

            for(int i = 0; i < idx; i++) {
                if(num[i] >= num[idx] && cnt[idx] < cnt[i]) cnt[idx] = cnt[i];
            }
            cnt[idx]++;
            if(max < cnt[idx]) max = cnt[idx];
            idx++;
        } else if(idx) {
            if(rnd) puts("");
            printf("Test #%d:\n", ++rnd);
            printf("  maximum possible interceptions: %d\n", max);

            idx = 0;
            max = 0;
        }
    }
}

