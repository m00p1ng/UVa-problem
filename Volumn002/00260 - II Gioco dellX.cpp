#include <cstdio>
#include <cstring>

int n;
int dr[] = {-1,-1, 0, 0, 1, 1};
int dc[] = {-1, 0,-1, 1, 0, 1};
char board[300][300];
bool visited[300][300];
char team_win;

void dfs(int x, int y, char t) {
    if(x < 0 || y < 0 || x == n || y == n) return;
    if(board[x][y] != t || visited[x][y]) return;

    if(board[x][y] == 'b' && x == n-1) {
        team_win = 'B';
        return;
    }
    if(board[x][y] == 'w' && y == n-1) {
        team_win = 'W';
        return;
    }
    visited[x][y] = true;

    for(int d = 0; d < 6; d++) {
        dfs(x+dr[d], y+dc[d], t);
    }
}

int main() {
    int ts = 1;
    while(scanf("%d", &n), n) {
        memset(visited, 0, sizeof(visited));
        team_win = '.';

        for(int i = 0; i < n; i++) {
            scanf("%s", board[i]);
        }

        for(int i = 0; i < n && team_win == '.'; i++) {
            if(!visited[0][i] && board[0][i] == 'b') dfs(0, i, 'b');
            if(!visited[i][0] && board[i][0] == 'w') dfs(i, 0, 'w');
        }
        printf("%d %c\n", ts++, team_win);
    }
}
