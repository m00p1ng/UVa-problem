#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int r, c;
bool bomb[220][220];
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

bool is_valid(int i, int j) {
    return i > 0 && j > 0 && i <= r && j <= c;
}

void fill_jiggly(int i, int j, int d) {
    int rad_sq = d*d;
    int ni, nj;

    for(int x = -d; x <= d; x++) {
        for(int y = -d; y <= d; y++) {
            if(x*x + y*y > rad_sq) continue; 
            ni = i + x;
            nj = j + y;
            if(is_valid(ni, nj)) {
                bomb[ni][nj] = true;
            }
        }
    }
}

int bfs_path() {
    queue<iii> q;
    q.push(iii(0, ii(1, 1)));
    bomb[1][1] = true;

    int ni, nj;

    while(!q.empty()) {
        iii v = q.front(); q.pop();
        ii p = v.second;

        if(p.first == r && p.second == c) {
            return v.first;
        }
        
        for(int d = 0; d < 4; d++) {
            ni = p.first + dr[d];
            nj = p.second + dc[d];
            if(is_valid(ni, nj) && !bomb[ni][nj]) {
                q.push(iii(v.first+1, ii(ni, nj)));
                bomb[ni][nj] = true;
            }
        }
    }
    return -1;
}

int main() {
    int m, a, b, l;
    while(scanf("%d %d", &r, &c), r || c) {
        memset(bomb, false, sizeof(bomb));

        scanf("%d", &m);
        for(int i = 0; i < m; i++) {
            scanf("%d %d", &a, &b);
            if(!bomb[a][b]) {
                bomb[a][b] = true;
            }
        }
        scanf("%d", &m);
        for(int i = 0; i < m; i++) {
            scanf("%d %d %d", &a, &b, &l);
            fill_jiggly(a, b, l);
        }

        int m = bfs_path();
        if(m != -1) printf("%d\n", m);
        else puts("Impossible.");
    }
}
