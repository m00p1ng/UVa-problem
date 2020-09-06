#include <cstdio>

int main() {
    int n, m, s;
    
    while (scanf("%d %d", &n, &m) == 2) {
        int total_player = 0;
        for (int i = 0; i < n; i++) {
            int cnt = 0;

            for (int j = 0; j < m; j++) {
                scanf("%d", &s);

                if (s > 0) {
                    cnt++;
                }
            }

            if (cnt == m) {
                total_player++;
            }
        }

        printf("%d\n", total_player);
    }
}
