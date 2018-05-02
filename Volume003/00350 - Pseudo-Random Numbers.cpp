#include <cstdio>

int main() {
    int z, i, m, l, temp;
    int ts = 0;
    while(scanf("%d %d %d %d", &z, &i, &m, &l), z || i || m || l) {
        int visited[10000] = {0};
        int cnt = 1;
        temp = l;
        visited[temp] = 1;

        while(1) {
            temp = (z*temp+i) % m;
            cnt++;

            if(visited[temp] != 0) {
                cnt -= visited[temp];
                break;
            }
            visited[temp] = cnt;
        }
        printf("Case %d: %d\n", ++ts, cnt); 
    }
}
