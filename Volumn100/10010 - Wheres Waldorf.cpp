#include <cstdio>
#include <cstring>
#include <cctype>

char board[100][100];
int r, c;

int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, 1, 1, 1, 0, -1, -1 ,-1};

bool is_valid(int i, int j) {
    return i >= 0 && j >= 0 && i < r && j < c;
}

bool dfs(char* s, int len, int i, int j, int depth, int di) {
    if(board[i][j] != s[depth]) return false;
    if(depth+1 == len) return true;

    if(!is_valid(i+dr[di], j+dc[di])) return false;
    return dfs(s, len, i+dr[di], j+dc[di], depth+1, di);
}

bool find_word(char* s, int len, int i, int j) {
    for(int d = 0; d < 8; d++) {
        if(is_valid(i+dr[d], j+dc[d]) && dfs(s, len, i+dr[d], j+dc[d], 1, d)) return true;
    }
    return false;;
}

void tolower_string(char* s, int len) {
    for(int i = 0; i < len; i++) {
        s[i] = tolower(s[i]);
    }
}

int main() {
    int ts, q;
    char temp[100];
    scanf("%d", &ts);
    while(ts--) {
        scanf("%d %d", &r, &c);
        for(int i = 0; i < r; i++) {
            scanf("%s", board[i]);
            tolower_string(board[i], c);
        }

        scanf("%d", &q);
        for(int k = 0; k < q; k++) {
            scanf("%s", temp);
            int len = strlen(temp);
            bool found = false;
            tolower_string(temp, len);

            for(int i = 0; i < r && !found; i++) {
                for(int j = 0; j < c && !found; j++) {
                    if(temp[0] == board[i][j] && (len == 1 || find_word(temp, len, i, j))) {
                        printf("%d %d\n", i+1, j+1);
                        found = true;
                    }
                }
            }
        }
        if(ts) puts("");
    }
}
