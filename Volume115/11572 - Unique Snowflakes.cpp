#include <cstring>
#include <map>
using namespace std;

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int ts, n, a, ms, prev, diff;
    map<int, int> visited;
    scanf("%d", &ts);

    while(ts--) {
        visited.clear();
        scanf("%d", &n);
        ms = 0, prev = 1;

        for(int i = 1; i <= n; i++) {
            scanf("%d", &a);
            if(visited[a]) {
                ms = max(ms, i - prev);
                prev = max(prev, visited[a] + 1);
            }
            visited[a] = i;
        }
        ms = max(ms, n - prev + 1);
        printf("%d\n", ms);
    }
}
