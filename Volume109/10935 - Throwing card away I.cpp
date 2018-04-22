#include <cstdio>
#include <queue>
using namespace std;

int main() {
    int n;

    queue<int> q, out;

    while(scanf("%d", &n), n) {
        for(int i = 1; i <= n; i++) {
            q.push(i);
        }

        for(int i = 0; i < n-1; i++) {
            out.push(q.front()); q.pop();
            q.push(q.front()); q.pop();
        }

        printf("Discarded cards:");
        if(n > 1) {
            for(int i = 0; i < n-2; i++) {
                printf(" %d,", out.front()); out.pop();
            }
            printf(" %d", out.front()); out.pop();
        }
        puts("");
        printf("Remaining card: %d\n", q.front()); q.pop();
    }
}
