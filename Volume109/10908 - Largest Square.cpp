#include <cstdio>

int main() {
    int ts;
    int r, c, q, a, b;
    char board[110][110];
    scanf("%d", &ts);
    while(ts--) {
        scanf("%d %d %d", &r, &c, &q);
        printf("%d %d %d\n", r, c, q);

        for(int i = 0; i < r; i++) {
            scanf("%s", board[i]);
        }

        while(q--) {
            scanf("%d %d", &a, &b);
            int offset = 0;
            bool is_valid = true;

            while(a+offset < r && b+offset < c && a-offset >= 0 && b-offset >= 0) {
                for(int i = -offset; i <= offset; i++) {
                    if(board[a][b] != board[a+i][b+offset] || board[a][b] != board[a+i][b-offset] ||
                       board[a][b] != board[a+offset][b+i] || board[a][b] != board[a-offset][b+i]) {
                        is_valid = false;
                    }
                }

                if(!is_valid) break;

                offset++;
            }

            printf("%d\n", 2*offset-1);
        }
    }
}
