#include <cstdio>

int d[5010];

bool is_diff(int n) {
    bool cnt[10] = {false};
    while(n > 0) {
        if(cnt[n%10]) {
            return false;
        }
        cnt[n%10] = true;
        n /= 10;
    }
    return true;
}

void gen_diff() {
    d[0] = 1;
    for(int i = 1; i <= 5000; i++) {
        d[i] = d[i-1] + is_diff(i);
    }
}

int main() {
    gen_diff();

    int a, b;
    while(scanf("%d %d", &a, &b) == 2) {
        printf("%d\n", d[b] - d[a-1]);
    }
}
