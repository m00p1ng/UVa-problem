#include <cstdio>
#include <algorithm>
#define INF 1<<30

int abs(int a) {
    return a > 0 ? a : -a;
}

int main() {
    int arr[1000];
    int ts = 0, n, query, num;
    int min_diff, val;

    while(scanf("%d", &n), n) {
        for(int i = 0; i < n; i++) scanf("%d", &arr[i]); 
        std::sort(arr, arr+n);
        
        printf("Case %d:\n", ++ts);
        scanf("%d", &query);
        for(int i = 0; i < query; i++) {
            min_diff = INF;
            scanf("%d", &num);

            for(int x = 0; x < n-1; x++) {
                for(int y = x+1; y < n; y++) {
                    int diff = abs(arr[x]+arr[y]-num);
                    if(diff < min_diff) {
                        min_diff = diff;
                        val = arr[x]+arr[y];
                    }
                }
            }
            printf("Closest sum to %d is %d.\n", num, val);
        }
    }
}

