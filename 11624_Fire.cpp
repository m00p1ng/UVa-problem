#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int r, c;
int si, sj;
char board[1010][1010];
bool visited[1010][1010];

int fire[1010][1010];

int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, -1, 1};

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

bool is_valid(int i, int j, int d) {
    return i >= 0 && j >= 0 && i < r && j < c && board[i][j] != '#' && fire[i][j] > d+1;
}

bool is_bound(int i, int j) {
    return i == 0 || j == 0 || i == r-1 || j == c-1;
}

void fire_connected() {
    queue<iii> q;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(fire[i][j] == 0) {
                q.push(iii(0, ii(i, j)));
            }
        }
    }

    int ni, nj;
    while(!q.empty()) {
        iii v = q.front(); q.pop();
        ii p = v.second;

        for(int d = 0; d < 4; d++) {
            ni = p.first + dr[d];
            nj = p.second + dc[d];
            if(is_valid(ni, nj, v.first)) {
                fire[ni][nj] = v.first+1;
                q.push(iii(v.first+1, ii(ni, nj)));
            }
        }
    }
}

int bfs_joe(int i, int j) {
    queue<iii> q;
    q.push(iii(0, ii(i, j)));
    int cnt = 0, ni, nj;

    while(!q.empty()) {
        iii v = q.front(); q.pop();
        ii p = v.second;

        if(is_bound(p.first, p.second)) {
            return v.first+1;
        }

        visited[p.first][p.second] = true;

        for(int d = 0; d < 4; d++) {
            ni = p.first + dr[d];
            nj = p.second + dc[d];
            if(is_valid(ni, nj, v.first) && !visited[ni][nj]) {
                q.push(iii(v.first+1, ii(ni, nj)));
            }
        }
    }

    return -1;
}

void input_board() {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            fire[i][j] = 1<<20;
        }
    }

    for(int i = 0; i < r; i++) {
        scanf("%s", board[i]);
        for(int j = 0; j < c; j++) {
            if(board[i][j] == 'J') {
                si = i;
                sj = j;
                board[i][j] = '.';
            }
            if(board[i][j] == 'F') {
                fire[i][j] = 0;
                board[i][j] = '.';
            }
        }
    }
}

int main() {
    int ts;
    scanf("%d", &ts);
    while(ts--) {
        scanf("%d %d", &r, &c);
        memset(visited, 0, sizeof(visited));
        memset(fire, 0, sizeof(fire));
        input_board();
        fire_connected();

        int b = bfs_joe(si, sj);
        if(b == -1) puts("IMPOSSIBLE");
        else printf("%d\n", b);
    }
}
