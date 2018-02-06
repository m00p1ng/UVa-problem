#include <cstdio>
#include <cstring>

int main() {
    int ts, n, m;
    int data[50][10000];
    int freq[10010];
    bool vis[10010];
    scanf("%d", &ts);
    for(int t = 1; t <= ts; t++) {
        memset(freq, 0, sizeof(freq));
        scanf("%d", &n);

        for(int i = 0; i < n; i++) {
            scanf("%d", &data[i][0]);
            memset(vis, 0, sizeof(vis));
            for(int j = 1; j <= data[i][0]; j++) {
                scanf("%d", &data[i][j]);
                if(!vis[data[i][j]]) {
                    freq[data[i][j]]++;
                    vis[data[i][j]] = true;
                    data[i][j] = data[i][j];
                } else {
                    j--;
                    data[i][0]--;
                }
            }
        }

        int uni = 0;
        for(int i = 0; i < n; i++) {
            int cur = 0;
            for(int j = 1; j <= data[i][0]; j++) {
                if(freq[data[i][j]] == 1) cur++; 
            }
            uni += cur;
            data[i][0] = cur*100;
        }

        printf("Case %d:", t);
        if(uni > 0) {
            for(int i = 0; i < n; i++) {
                printf(" %lf%%", data[i][0]/(double)uni);
            }
        }
        puts("");
    }
}
