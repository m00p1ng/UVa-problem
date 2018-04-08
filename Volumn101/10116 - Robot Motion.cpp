#include <cstdio>
#include <cstring>

int main() {
    int r, c, s;

    char grid[20][20];
    bool visited[20][20];
    while(scanf("%d %d %d", &r, &c, &s), r || c || s) {
        memset(visited, 0, sizeof(visited)); 

        for(int i = 0; i < r; i++) scanf("%s", grid[i]);

        int i = 0, j = s - 1;
        int cnt = 0;

        int loop = 1;
        bool is_loop = false;
        int li = -1, lj = -1;

        while(i >= 0 && j >= 0 && i < r && j < c) {
            int bi = i, bj = j;
            switch(grid[i][j]) {
                case 'S': i++; break;
                case 'N': i--; break;
                case 'E': j++; break;
                case 'W': j--; break;
            }

            if(!visited[bi][bj]) {
                cnt++;
                visited[bi][bj] = true;
            } else {
                if(!is_loop) {
                    li = i;
                    lj = j;
                    is_loop = true;
                    continue;
                }
                if(i == li && j == lj) break;
                else loop++;
            }
        }

        if(is_loop) {
            printf("%d step(s) before a loop of %d step(s)\n", cnt - loop, loop);
        } else {
            printf("%d step(s) to exit\n", cnt);
        }
    }
}

