#include <cstdio>
#include <set>
using namespace std;

int main () {
    int ts;
    int m, n, num, cnt;
    multiset<int> s;
    scanf("%d", &ts);

    while(ts--) {
        s.clear();
        cnt = 0;

        scanf("%d %d", &m, &n);
        for(int i = 0; i < m; i++) {
            scanf("%d", &num);
            s.insert(num);
        }
        for(int i = 0; i < n; i++) {
            scanf("%d", &num);
            auto it = s.find(num);
            if(it != s.end()) {
                cnt++;
                s.erase(it);
            }
        }
        printf("%d\n", m+n-2*cnt);
    }
}
