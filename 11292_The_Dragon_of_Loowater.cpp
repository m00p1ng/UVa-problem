#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int d[20000], k[20000];
    int m, n, i, j, coin;
    while(scanf("%d %d", &m, &n), m || n) {
        for(int i = 0; i < m; i++) scanf("%d", &d[i]);
        for(int i = 0; i < n; i++) scanf("%d", &k[i]);
        sort(d, d+m);
        sort(k, k+n);

        i = j = coin = 0;
        while(i < m && j < n) {
            if(d[i] <= k[j]) {
                coin += k[j];
                i++;
            }
            j++;
        }
        if(i != m) puts("Loowater is doomed!");
        else printf("%d\n", coin);
    }
}
