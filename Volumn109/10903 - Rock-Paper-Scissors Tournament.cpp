#include <cstdio>
#include <cstring>

int is_win(char a, char b) {
    if(a == b) return 0;
    if(a == 'r' && b == 's') return 1;
    if(a == 'p' && b == 'r') return 1;
    if(a == 's' && b == 'p') return 1;
    return -1;
}


int main() {
    int n, k, x, y;
    char a[10], b[10];

    int cnt[1010][2], total;

    int win;
    bool ts = false;

    while(scanf("%d %d", &n, &k) == 2 && (n || k)) {
        memset(cnt, 0, sizeof(cnt));
        total = 0;

        int rnd = k*n*(n-1)/2;
        for(int i = 0; i < rnd; i++) {
            scanf("%d %s %d %s", &x, a, &y, b);
            win = is_win(a[0], b[0]);
            if(win) {
                total++;
                if(win == 1){
                    cnt[x][0]++; cnt[y][1]++;
                } else {
                    cnt[y][0]++; cnt[x][1]++;
                }
            }
        }

        if(ts) puts(""); ts = true;

        for(int i = 1; i <= n; i++) {
            if(total == 0) {
                puts("-");
            } else {
                printf("%.3lf\n", cnt[i][0]/(double)(cnt[i][0]+cnt[i][1]));
            }
        }
    }
}
