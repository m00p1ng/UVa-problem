#include <cstdio>
#include <map>
using namespace std;

typedef pair<int, int> ii;

int main() {
    int n;
    map<ii, int> visited;
    int a, b, cnt;
    while(scanf("%d", &n), n) {
        visited.clear();
        cnt = 0;

        for(int i = 0; i < n; i++) {
            scanf("%d %d", &a, &b);
            if(visited[ii(b, a)]) {
                visited[ii(b, a)]--;
                cnt--;
            } else {
                visited[ii(a, b)]++;
                cnt++;
            }
        }
        if(cnt) puts("NO");
        else puts("YES");
    }
}
