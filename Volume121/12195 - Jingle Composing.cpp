#include <cstdio>

int main() {
    int du[128];
    du['W'] = 64;
    du['H'] = 32;
    du['Q'] = 16;
    du['E'] = 8;
    du['S'] = 4;
    du['T'] = 2;
    du['X'] = 1;

    char temp[300];
    while(scanf("%s", temp), temp[0] != '*') {
        int cnt = 0;
        int temp_cnt = 0;
        for(int i = 1; temp[i]; i++) {
            if(temp[i] == '/') {
                if(temp_cnt == 64) cnt++;
                temp_cnt = 0;
            } else {
                temp_cnt += du[temp[i]];
            }
        }
        printf("%d\n", cnt);
    }
}
