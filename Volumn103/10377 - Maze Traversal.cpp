#include <cstdio>
#include <cstring>

int dx[] = {-1, 0, 1,  0};
int dy[] = { 0, 1, 0, -1};

int main() {
    char wall[60][65];
    int ts;
    scanf("%d", &ts);
    while(ts--) {
        int row, col;
        scanf("%d %d\n", &row, &col);
        for(int i = 0; i < row; i++) {
            fgets(wall[i], 62, stdin);
        }
        
        int x, y;
        int ori = 4000000;
        scanf("%d %d\n", &x, &y);
        x--; y--;

        char cmd = ' ';
        while(1) {
            scanf("%c", &cmd);
            if(cmd == 'Q') break;
            if(cmd == 'R') ori++;
            else if(cmd == 'L') ori--;
            else if(cmd == 'F') {
                int idx = ori % 4;
                int px = x + dx[idx];
                int py = y + dy[idx];
                if(px < 0 || py < 0 || px >= row || py >= col) continue;
                if(wall[px][py] == '*') continue;
                x = px;
                y = py;
            }
        }

        printf("%d %d ", x+1, y+1);
        int idx = ori % 4;
        if(idx == 0) puts("N");
        else if(idx == 1) puts("E");
        else if(idx == 2) puts("S");
        else if(idx == 3) puts("W");
        if(ts) puts("");
    }
}

