#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int row, col;
char board[1000][1001];

struct mypair {
    char c;
    int count;
} cpair[26];

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

void dfs(int x, int y, char c) {
    if(x < 0 || y < 0 || x == row || y == col) return;
    if(board[x][y] == '.' || board[x][y] != c) return;

    board[x][y] = '.';
    for(int i = 0; i < 4; i++) {
        dfs(x + dx[i], y + dy[i], c);
    }
}

bool cmp(mypair a, mypair b) {
    if(a.count > b.count) return true;
    if(a.count < b.count) return false;
    return a.c < b.c;
}

int main() {
    int testcase;
    scanf("%d", &testcase);
    for(int cs = 1; cs <= testcase; cs++) {
        scanf("%d %d", &row, &col);

        for(int i = 0; i < row; i++) {
            scanf("%s", board[i]);
        }

        memset(cpair, 0, sizeof cpair);

        int group = 0;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(board[i][j] != '.') {
                    int idx = board[i][j] - 'a';
                    if(cpair[idx].count == 0) group++;
                    cpair[idx].count++;
                    cpair[idx].c = board[i][j];
                    dfs(i, j, board[i][j]);
                }
            }
        }

        sort(cpair, cpair+26, cmp);
        printf("World #%d\n", cs);
        for(int i = 0; i < group; i++) {
            printf("%c: %d\n", cpair[i].c, cpair[i].count);
        }
    }
}

