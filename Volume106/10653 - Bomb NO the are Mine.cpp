#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int,int> ii;
typedef pair<ii, int> iii;

int r, c;
int si, sj, ei, ej;
bool visited[1000][1000];

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int bfs() {
    queue<iii> q;
    q.push(iii(ii(si,sj),0));
    int short_dist = 0;
    while(!q.empty()) {
        iii cur = q.front(); q.pop();
        ii p = cur.first;
        int dist = cur.second;

        if(p.first < 0 || p.second < 0 || p.first == r || p.second == c) continue;
        if(visited[p.first][p.second]) continue;
        if(p.first == ei && p.second == ej) {
            short_dist = dist;
            break;
        }
        visited[p.first][p.second] = true;
        for(int d = 0; d < 4; d++) {
            int nr = p.first+dr[d];
            int nc = p.second+dc[d];
            if(!visited[nr][nc]) {
                q.push(iii(ii(nr, nc), dist+1));
            }
        }
    }
    return short_dist;
}

int main() {
    int total_r, b, rb, t;
    while(scanf("%d %d", &r, &c), r || c) {
        memset(visited, false, sizeof(visited));
        scanf("%d", &total_r);
        for(int i = 0; i < total_r; i++) {
            scanf("%d %d", &rb, &b);
            for(int j = 0; j < b; j++) {
                scanf("%d", &t);
                visited[rb][t] = true;
            }
        }
        scanf("%d %d", &si, &sj);
        scanf("%d %d", &ei, &ej);

        printf("%d\n", bfs());
    }
}
