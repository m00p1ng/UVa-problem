#include <cstdio>

int num[5];

bool valid;

void dfs(int d, int sum, int visited) {
    if(valid) return;
    if(d == 5) {
        if(sum == 23) valid = true;
        return;
    }

    for(int i = 0; i < 5; i++) {
        if((visited >> i) & 1) continue;
        visited |= (1 << i);
        dfs(d+1, sum+num[i], visited);
        dfs(d+1, sum-num[i], visited);
        dfs(d+1, sum*num[i], visited);
        visited &= ~(1 << i);
    }
}

int main() {
    while(1) {
        int cnt = 0;
        for(int i = 0; i < 5; i++) {
            scanf("%d", &num[i]);
            cnt += num[i] == 0;
        }
        if(cnt == 5) break;

        valid = false;
        for(int i = 0; i < 5; i++) {
            dfs(1, num[i], 1<<i);
        }
        if(valid) puts("Possible");
        else puts("Impossible");
    }
}
