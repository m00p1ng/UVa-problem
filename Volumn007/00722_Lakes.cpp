#include <cstdio>
#include <cstring>

char board[110][110];
int r, c;
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

int dfs(int i, int j) {
    if(i < 0 || j < 0 || i == r || j == c) return 0;
    if(board[i][j] == '1') return 0;

    board[i][j] = '1';

    int sum = 1;
    for(int d = 0; d < 4; d++) {
        sum += dfs(dr[d]+i, dc[d]+j);
    }
    return sum;
}

int main() {
    int ts;
    scanf("%d\n\n", &ts);

    while(ts--) {
        r = c = 0;
        int sr, sc;
        char temp[110];

        scanf("%d %d\n", &sr, &sc);

        while(fgets(temp, 110, stdin)) {
            if(!strcmp(temp, "\n")) break;
            strcpy(board[r++], temp);
        }
        c = strlen(board[0]) - 1;

        int lake = dfs(sr-1, sc-1);
        printf("%d\n", lake);
        if(ts) puts("");
    }
}
