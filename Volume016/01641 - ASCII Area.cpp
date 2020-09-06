#include <cstdio>

int main() {
    int r, c;
    char board[110][110];

    while (scanf("%d %d", &r, &c) == 2) {
        int slash_count = 0, dot_count = 0;

        for (int i = 0; i < r; i++) {
            scanf("%s", board[i]);

            int current_slash = 0;
            for (int j = 0; j < c; j++) {
                if (board[i][j] == '/' || board[i][j] == '\\') {
                    current_slash++;
                }
                if (board[i][j] == '.' && current_slash % 2 == 1) {
                   dot_count++; 
                }
            }
            slash_count += current_slash;
        }

        int area = slash_count / 2 + dot_count;

        printf("%d\n", area);
    }
}
