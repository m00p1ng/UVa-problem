#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

int l, r, c;
char board[100][100][100];
bool visited[100][100][100];
int st[3];

struct tri {
    int x, y, z;
};

typedef pair<int, tri> it;

int dl[] = {0, 0, 0, 0, 1, -1};
int dr[] = {1, 0, -1, 0, 0, 0};
int dc[] = {0, 1, 0, -1, 0, 0};

bool is_valid(int i, int j, int k) {
    return i >= 0 && j >= 0 && k >= 0 && i < l && j < r && k < c;
}

int bfs() {
    queue<it> q;
    memset(visited, false, sizeof(visited));

    q.push(it(0, {st[0], st[1], st[2]}));

    while(!q.empty()) {
        it v = q.front(); q.pop();
        tri a = v.second;

        if(visited[a.x][a.y][a.z]) continue;
        if(board[a.x][a.y][a.z] == '#') continue;
        if(board[a.x][a.y][a.z] == 'E') return v.first;
        visited[a.x][a.y][a.z] = true;

        for(int d = 0; d < 6; d++) {
            int ni = a.x + dl[d];
            int nj = a.y + dr[d];
            int nk = a.z + dc[d];
            if(is_valid(ni, nj, nk)) {
                q.push(it(v.first+1, {ni, nj, nk}));
            }
        }
    }

    return 0;
}

int main() {
    while(scanf("%d %d %d", &l, &r, &c), l || r || c) {
        for(int i = 0; i < l; i++) {
            for(int j = 0; j < r; j++) {
                scanf("%s", board[i][j]);
                for(int k = 0; k < c; k++) {
                    if(board[i][j][k] == 'S') {
                        st[0] = i;
                        st[1] = j;
                        st[2] = k;
                    }
                }
            }
        }
        int t = bfs();
        if(t != 0) printf("Escaped in %d minute(s).\n", t);
        else puts("Trapped!");
    }
}
