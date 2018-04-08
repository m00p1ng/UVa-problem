#include <cstdio>

char temp[10][10];

bool is_win(char c) {
    for(int i = 0; i < 3; i++) {
        if(temp[i][0] == c) {
            if(temp[i][0] == temp[i][1] && temp[i][1] == temp[i][2] && temp[i][0] == c) return true;
        }
        if(temp[0][i] == c) {
            if(temp[0][i] == temp[1][i] && temp[1][i] == temp[2][i] && temp[0][i] == c) return true;
        }
    }
    if(temp[1][1] == c) {
        if(temp[0][0] == temp[1][1] && temp[1][1] == temp[2][2]) return true;
        if(temp[0][2] == temp[1][1] && temp[1][1] == temp[2][0]) return true;
    }

    return false;
}

int main() {
    int ts;
    scanf("%d", &ts);
    int x, o;

    while(ts--) {
        x = o = 0;
        for(int i = 0; i < 3; i++) {
            scanf("%s", temp[i]);
            for(int j = 0; j < 3; j++) {
                if(temp[i][j] == 'X') x++;
                if(temp[i][j] == 'O') o++;
            }
        }
        bool res_x = is_win('X');
        bool res_o = is_win('O');
        if(o > x || x - o > 1 || (res_x && res_o)) puts("no");
        else {
            if(res_x && x == o+1) puts("yes");
            else if(res_o && o == x) puts("yes");
            else if(!res_x && !res_o && (o == x || x == o+1)) puts("yes");
            else puts("no");
        }
    }
}
