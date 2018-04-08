#include <cstdio>
#include <cstring>

int abs(int n) {
    return n > 0 ? n : -n;
}

int main() {
    int n, b, cnt;
    bool visited[100];
    int ball[100];
    while(scanf("%d %d", &n, &b), n || b) {
        memset(visited, false, sizeof(visited));
        cnt = n+1;

        for(int i = 0; i < b; i++) {
            scanf("%d", &ball[i]);

            for(int j = 0; j <= i; j++) {
                int diff = abs(ball[j] - ball[i]);
                if(!visited[diff]) {
                    cnt--;
                    visited[diff] = true;
                }
            }
        }
        if(cnt == 0) puts("Y");
        else puts("N");
    }
}
