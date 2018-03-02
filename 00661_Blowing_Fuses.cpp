#include <cstdio>
#include <cstring>

int main() {
    int ts = 0;
    int n, m, c, cur, sel, maxpow, dev[100];
    bool state[100];
    while(scanf("%d %d %d", &n, &m, &c), n || m || c) {
        cur = maxpow = 0;
        memset(state, 0, sizeof(state));

        for(int i = 0; i < n; i++) scanf("%d", &dev[i]);
        for(int i = 0; i < m; i++) {
            scanf("%d", &sel);
            sel--;
            if(state[sel]) cur -= dev[sel];
            else {
                cur += dev[sel];
                if(cur > c) maxpow = cur;
                if(cur > maxpow) maxpow = cur;
            }
            state[sel] = !state[sel];
        }

        printf("Sequence %d\n", ++ts);
        if(maxpow > c) puts("Fuse was blown.");
        else {
            puts("Fuse was not blown.");
            printf("Maximal power consumption was %d amperes.\n", maxpow);
        }
        puts("");
    }
}
