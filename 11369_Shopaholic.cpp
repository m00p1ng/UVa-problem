#include <cstdio>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int ts;
    scanf("%d", &ts);
    while(ts--) {
        int n;
        scanf("%d", &n);
        int items[20002];

        for(int i = 0; i < n; i++) {
            scanf("%d", &items[i]);
        }
        sort(items, items+n, cmp);
        int discount = 0;
        for(int i = 2; i < n; i+=3) {
            discount += items[i]; 
        }
        printf("%d\n", discount);
    }
}
