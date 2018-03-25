#include <cstdio>
#include <algorithm>
using namespace std;

int abs(int a) {
    return a > 0 ? a : -a;
}

bool cmp(int a, int b) {
    return abs(a) < abs(b);
}

int main() {
    int ts, n, cnt;
    int data[500000];
    bool is_plus;
    scanf("%d", &ts);

    while(ts--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%d", &data[i]);
        }
        sort(data, data+n, cmp);

        is_plus = data[0] > 0; 
        cnt = 1;
        for(int i = 1; i < n; i++) {
            if((data[i] > 0 && !is_plus) || (data[i] < 0 && is_plus)) {
                is_plus = !is_plus;
                cnt++;
            }
        }
        printf("%d\n", cnt);
    }
}
