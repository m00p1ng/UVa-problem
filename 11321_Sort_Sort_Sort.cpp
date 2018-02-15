#include <cstdio>
#include <algorithm>
using namespace std;

int n, m;

bool cmp(int a, int b) {
    int ma = a % m;
    int mb = b % m;
    if(ma != mb) return ma < mb;

    int oa = a&1;
    int ob = b&1;
    if(oa && !ob) return true;
    if(!oa && ob) return false;
    if(oa) return a > b;
    return a < b;
}

int main() {
    int num[10010];
    while(scanf("%d %d", &n, &m) == 2) {
        for(int i = 0; i < n; i++) {
            scanf("%d", &num[i]);
        }
        sort(num, num+n, cmp);

        printf("%d %d\n", n, m);
        for(int i = 0; i < n; i++) {
            printf("%d\n", num[i]);
        }
    }
}
