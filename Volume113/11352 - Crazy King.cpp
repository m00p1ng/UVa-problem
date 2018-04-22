#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int r, c;
char board[110][110];
bool visited[110][110];

int ai, aj, bi, bj;
int dr[] = {1, 1, 2, 2, -1, -1, -2, -2};
int dc[] = {2, -2, 1, -1, 2, -2, 1, -1};

int kr[] = {1,1,1,-1,-1,-1,0,0};
int kc[] = {1,0,-1,1,0,-1,1,-1};

bool is_valid(int i, int j) {
    return i >= 0 && j >= 0 && i < r && j < c;
}

void knight_mark(int i, int j) {
    visited[i][j] = true;
    int ni, nj;
    for(int d = 0; d < 8; d++) {
        ni = i + dr[d];
        nj = j + dc[d];
        if(is_valid(ni, nj)) {
            visited[ni][nj] = true;
        }
    }
}

int bfs_king() {
    queue<iii> q;
    q.push(iii(0, ii(ai, aj)));
    int ni, nj;
    bool vis_king[110][110] = {0};
    vis_king[ai][aj] = 0;

    while(!q.empty()) {
        iii v = q.front(); q.pop();
        ii p = v.second;

        if(p.first == bi && p.second == bj) return v.first;

        for(int d = 0; d < 8; d++) {
            ni = p.first + kr[d];
            nj = p.second + kc[d];
            if(is_valid(ni, nj) && !vis_king[ni][nj] && !visited[ni][nj]) {
                vis_king[ni][nj] = true;
                q.push(iii(v.first+1, ii(ni, nj)));
            }
        }
    }
    return -1;
}

int main() {
    int ts;
    scanf("%d", &ts);
    while(ts--) {
        scanf("%d %d", &r, &c);
        memset(visited, false, sizeof(visited));

        for(int i = 0; i < r; i++) {
            scanf("%s", board[i]);
            for(int j = 0; j < c; j++) {
                if(board[i][j] == 'A') ai = i, aj = j;
                if(board[i][j] == 'B') bi = i, bj = j;
                if(board[i][j] == 'Z') {
                    knight_mark(i, j);
                }
            }
        }

        visited[ai][aj] = visited[bi][bj] = false;

        int m = bfs_king();
        if(m != -1) printf("Minimal possible length of a trip is %d\n", m);
        else puts("King Peter, you can't go now!");
    }
}
