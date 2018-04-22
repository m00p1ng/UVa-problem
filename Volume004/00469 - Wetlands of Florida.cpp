#include <cstdio>
#include <cstring>

char board[105][105];
int r, c;

int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
int visited[105][105];

int dfs(int i, int j) {
    if(i < 0 || j < 0 || i == r || j == c) return 0;
    if(board[i][j] == 'L' || visited[i][j]) return 0;
    visited[i][j] = true;

    int cnt = 1;
    for(int d = 0; d < 8; d++) {
        cnt += dfs(i+dr[d], j+dc[d]);
    }
    return cnt;
}

int main() {
    int ts;
    scanf("%d\n\n", &ts);
    char buff[1000];
    int x, y;
    
    while(ts--) {
        r = c = 0;

        while(fgets(buff, 1000, stdin) && buff[0] != '\n') {
            if(buff[0] == 'L' || buff[0] == 'W') {
                strcpy(board[r], buff);
                r++;
                c = strlen(buff)-1;
            } else {
                memset(visited, 0, sizeof(visited));
                sscanf(buff, "%d %d", &x, &y);
                printf("%d\n", dfs(x-1, y-1));
            }
        }
        if(ts) puts("");
    }
}
