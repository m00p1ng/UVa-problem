#include <cstdio>
#include <algorithm>
using namespace std;

struct hole {
    int i;
    char c;
} holes[2500];

int row, col;
char road[50][51];

int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};

int dfs(int i, int j, char c) {
    if(i < 0 || i == row || j < 0 || j == col) return 0;
    if(road[i][j] != c) return 0;

    road[i][j] = '.';
    int out = 1;

    for(int d = 0; d < 4; d++) {
        out += dfs(i+dr[d], j+dc[d], c);
    }
    return out;
}

bool cmp(hole a, hole b) {
    if(a.i > b.i) return true;
    if(a.i < b.i) return false;
    return a.c < b.c;
}

int main() {
    int cs = 1;

    while(scanf("%d %d", &row, &col), row || col) {
        for(int i = 0; i < row; i++) {
            scanf("%s", road[i]);
        }
        int idx = 0;

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(road[i][j] != '.') {
                    char c = road[i][j];
                    int val = dfs(i, j, c);
                    holes[idx++] = {val, c};
                }
            }
        }
        sort(holes, holes+idx, cmp);

        printf("Problem %d:\n", cs++);
        for(int i = 0; i < idx; i++) {
            printf("%c %d\n", holes[i].c, holes[i].i);
        }
    }
}

