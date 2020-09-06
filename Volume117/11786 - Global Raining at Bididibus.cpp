#include <cstdio>
#include <cstring>

int main() {
    int ts;
    char board[10100];
    int level[10010];
    scanf("%d", &ts);

    while (ts--) {
        scanf("%s", board);
        int total = 0, vol, ptr = -1;

        for (int i = 0; i < strlen(board); i++) {
            if (board[i] == '\\') {
                level[++ptr] = i;
            }

            if (board[i] == '/' && ptr != -1) {
                total += i - level[ptr--];
            }
        }

        printf("%d\n", total);
    }
}
