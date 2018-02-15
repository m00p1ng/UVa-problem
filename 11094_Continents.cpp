#include <cstdio>

int m, n;
char board[100][100];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int dfs(int x, int y, char c) {
    if(x < 0 || x == m || board[x][y] != c) return 0;
    board[x][y] = ' ';
    
    int con = 1;
    for(int d = 0; d < 4; d++) {
        int nx = x+dx[d];
        int ny = y+dy[d];
        if(ny == -1) ny = n-1;
        if(ny == n) ny = 0;

        con += dfs(nx, ny, c);
    }
    return con;
}

int main() {
    int x, y;
    int max_con;
    char start;
    while(scanf("%d %d", &m, &n) == 2) {
        max_con = 0;
        for(int i = 0; i < m; i++) {
            scanf("%s", board[i]);
        }


        scanf("%d %d", &x, &y);
        start = board[x][y];
        dfs(x, y, start);

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == start) {
                    int con = dfs(i, j, start); 
                    if(con > max_con) max_con = con;
                }
            }
        }
        printf("%d\n", max_con);
    }
}
