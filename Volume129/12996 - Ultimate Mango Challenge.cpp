#include <cstdio>

int main() {
    int ts;
    int n, l;
    int mn[100], ml[100];
    scanf("%d", &ts);

    for(int t = 1; t <= ts; t++) {
        scanf("%d %d", &n, &l);

        int sum_mn = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d", &mn[i]);
            sum_mn += mn[i];
        }

        for(int i = 0; i < n; i++) {
            scanf("%d", &ml[i]);
        }

        bool can_win = true;

        if(sum_mn > l) {
            can_win = false;
        }

        for(int i = 0; i < n; i++) {
            if(mn[i] > ml[i]) {
                can_win = false;
                break;
            }
        }

        printf("Case %d: %s\n", t, can_win ? "Yes" : "No");
    }
}
