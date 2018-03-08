#include <cstdio>
#include <cstring>

int main() {
    int walk [][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    char di[] = {'N', 'E', 'S', 'W'};

    int row, col, x, y;
    char temp, pre[100][100], direction[101];
    scanf("%d %d", &row, &col);

    while(scanf("%d %d %c", &x, &y, &temp) == 3) {
        scanf("%s", direction);

        int ori = 0;
        switch(temp) {
            case 'N': ori = 0; break;
            case 'E': ori = 1; break;
            case 'S': ori = 2; break;
            case 'W': ori = 3; break;
        }
        bool is_lost = false;
        for(int i = 0; i < strlen(direction); i++) {
            if(direction[i] == 'R') {
                ori++;
                if(ori == 4) ori -= 4;
            } else if(direction[i] == 'L') {
                ori--;
                if(ori < 0) ori += 4;
            } else if(direction[i] == 'F') {
                x += walk[ori][0];
                y += walk[ori][1];
                if(x < 0 || x > row || y < 0 || y > col) {
                    x -= walk[ori][0];
                    y -= walk[ori][1];

                    if(pre[x][y] == 1) continue;

                    is_lost = true;
                    pre[x][y] = 1;
                    break;
                }
            }
        }
        printf("%d %d %c", x, y, di[ori]);
        if(is_lost) printf(" LOST");
        puts("");
    }
}

