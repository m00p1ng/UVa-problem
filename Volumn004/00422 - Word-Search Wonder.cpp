#include <cstdio>
#include <cstring>

char board[100][100];
int n;

int dr[] = {-1, 0, 1, 1, 1, 0, -1};
int dc[] = {1, 1, 1, 0, -1, -1 ,-1};
int ei, ej;

bool is_valid(int i, int j) {
    return i >= 0 && j >= 0 && i < n && j < n;
}

bool bfs(char* s, int len, int i, int j, int depth, int di) {
    if(board[i][j] != s[depth]) return false;
    if(depth+1 == len) {
        ei = i;
        ej = j;
        return true;
    }

    if(!is_valid(i+dr[di], j+dc[di])) return false;
    return bfs(s, len, i+dr[di], j+dc[di], depth+1, di);
}

bool find_word(char* s, int len, int i, int j) {
    for(int d = 0; d < 7; d++) {
        if(is_valid(i+dr[d], j+dc[d]) && bfs(s, len, i+dr[d], j+dc[d], 1, d)) return true;
    }
    return false;;
}

int main() {
    char temp[100];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s", board[i]);
    }

    while(scanf("%s", temp), temp[0] != '0') {
        int len = strlen(temp);
        bool found = false;


        for(int i = 0; i < n && !found; i++) {
            for(int j = 0; j < n && !found; j++) {
                if(temp[0] == board[i][j]) {
                    if(len == 1) {
                        printf("%d,%d %d,%d\n", i+1, j+1, i+1, j+1);
                        found = true;
                    } else if(find_word(temp, len, i, j)) {
                        printf("%d,%d %d,%d\n", i+1, j+1, ei+1, ej+1);
                        found = true;
                    }
                }
            }
        }
        if(!found) puts("Not found");
    }
}
