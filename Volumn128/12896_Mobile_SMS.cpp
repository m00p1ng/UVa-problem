#include <cstdio>

int main() {
    char key[][10] = {
        " ", ".,?\"", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    int ts;
    int b[200], p, n;
    scanf("%d", &ts);
    while(ts--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d", &b[i]);
        for(int i = 0; i < n; i++) {
            scanf("%d", &p);
            putchar(key[b[i]][p-1]);
        }
        puts("");
    }
}
