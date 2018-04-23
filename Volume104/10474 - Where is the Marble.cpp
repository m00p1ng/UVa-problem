#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int n, q, temp, ts = 0, data[10010];
    while(scanf("%d %d", &n, &q), n || q) {
        for(int i = 0; i < n; i++) {
            scanf("%d", &data[i]);
        }
        sort(data, data+n);
        printf("CASE# %d:\n", ++ts);
        for(int i = 0; i < q; i++) {
            scanf("%d", &temp);
            int pos = lower_bound(data, data+n, temp) - data;
            if(temp == data[pos]) {
                printf("%d found at %d\n", temp, pos+1);
            } else {
                printf("%d not found\n", temp);
            }
        }
    }
}
