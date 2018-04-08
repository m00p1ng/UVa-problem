#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int n, data[10010], cost;
    int a, b;

    while(scanf("%d", &n) == 1) {
        for(int i = 0; i < n; i++) {
            scanf("%d", &data[i]);
        }
        scanf("%d", &cost);

        sort(data, data+n);

        int sum, i = 0, j = n-1;

        while(i < j) {
            sum = data[i] + data[j];

            if(sum == cost) {
                    a = i++;
                    b = j--;
            }
            else if(sum < cost) i++;
            else j--;
        }
        printf("Peter should buy books whose prices are %d and %d.\n\n", data[a], data[b]);
    }
}
