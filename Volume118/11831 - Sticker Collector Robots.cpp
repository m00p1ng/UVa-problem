#include <cstdio>
#include <cctype>

int r, c;
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};

bool is_valid(int i, int j) {
    return i >= 0 && j >= 0 && i < r && j < c;
}

int main() {
    int q, sticker, collect;
    int si, sj, di;
    char board[110][110], cmd[50010];
    int m[128];
    m['N'] = 0; m['L'] = 1; m['S'] = 2; m['O'] = 3;

    while(scanf("%d %d %d", &r, &c, &q), r || c || q) {
        sticker = 0;
        collect = 0;
        di = 80000;
        for(int i = 0; i < r; i++) {
            scanf("%s", board[i]);
            for(int j = 0; j < c; j++) {
                if(board[i][j] == '*') sticker++;
                if(isalpha(board[i][j])) {
                    si = i, sj = j, di += m[board[i][j]];
                    board[i][j] = '.';
                }
            }
        }
        scanf("%s", cmd);
        int ni, nj;
        for(int i = 0; cmd[i] && sticker != 0; i++) {
            if(cmd[i] == 'F') {
                ni = si + dr[di&3];
                nj = sj + dc[di&3];
                if(is_valid(ni, nj) && board[ni][nj] != '#') {
                    if(board[ni][nj] == '*') {
                        collect++;
                        sticker--;
                        board[ni][nj] = '.';
                    }
                    si = ni; sj = nj;
                }
            }
            else if(cmd[i] == 'D') di++;
            else if(cmd[i] == 'E') di--;
        }
        printf("%d\n", collect);
    }
}
