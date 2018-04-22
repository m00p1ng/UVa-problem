#include <cstdio>
#include <cstring>

char board[10][10];

int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, 1, 1, 1, 0, -1, -1 ,-1};

bool is_valid(int i, int j) {
    return i >= 0 && j >= 0 && i < 4 && j < 4;
}

bool dfs(char* s, int len, int i, int j, int depth, int visited) {
    if(s[depth] != board[i][j]) return false;
    if(len == depth+1) return true;

    for(int d = 0; d < 8; d++) {
        int ni = i + dr[d];
        int nj = j + dc[d];
        if(is_valid(ni, nj) && !((visited>>(4*ni+nj))&1)) {
            if(dfs(s, len, ni, nj, depth+1, visited | (1<<(4*ni+nj)))) return true;
        }
    }
    return false;
}

int boggle_score(int n) {
    if(n == 3 || n == 4) return 1;
    if(n == 5) return 2;
    if(n == 6) return 3;
    if(n == 7) return 5;
    return 11;
}

int main() {
    int ts, q;
    char temp[100];
    scanf("%d", &ts);
    for(int t = 1; t <= ts; t++) {
        for(int i = 0; i < 4; i++) {
            scanf("%s", board[i]);
        }

        scanf("%d", &q);
        int score = 0;
        for(int k = 0; k < q; k++) {
            scanf("%s", temp);
            int len = strlen(temp);
            bool found = false;

            for(int i = 0; i < 4 && !found; i++) {
                for(int j = 0; j < 4 && !found; j++) {
                    if(temp[0] == board[i][j]) {
                        bool f = dfs(temp, len, i, j, 0, 1<<(4*i+j));
                        if(f) {
                            score += boggle_score(len) ;
                            found = true;
                        }
                    }
                }
            }
        }
        printf("Score for Boggle game #%d: %d\n", t, score);
    }
}
