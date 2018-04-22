#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
using namespace std;

struct state {
    int r, c;
    string path;
};

int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};
char di[] = "SNEW";
int si, sj, ei, ej;

bool visited[20][20];

bool is_valid(int i, int j) {
    return i >= 0 && j >= 0 && i <= 12 && j <= 12;
}

string bfs() {
    queue<state> q; 
    q.push({si, sj, ""});
    visited[si][sj] = true;
    int ni, nj;

    while(!q.empty()) {
        state v = q.front(); q.pop();

        if(v.r == ei && v.c == ej) return v.path;

        for(int d = 0; d < 4; d++) {
            ni = v.r + dr[d];
            nj = v.c + dc[d];
            if(is_valid(ni, nj) && !visited[ni][nj]) {
                ni += dr[d];
                nj += dc[d];
                if(is_valid(ni, nj) && !visited[ni][nj]) {
                    q.push({ni, nj, v.path+di[d]}); 
                    visited[ni][nj] = true;
                }
            }
        }
    }
    return "IMPOSSIBLE";
}

int main() {
    while(scanf("%d %d", &sj, &si), si || sj) {
        memset(visited, false, sizeof(visited));
        scanf("%d %d", &ej, &ei);
        si = 2*si - 1, sj = 2*sj - 1;
        ei = 2*ei - 1, ej = 2*ej - 1;

        int ai, aj, bi, bj;
        for(int d = 0; d < 3; d++) {
            scanf("%d %d %d %d", &aj, &ai, &bj, &bi);
            for(int j = aj; j < bj; j++) visited[2*ai][2*j + 1] = true;
            for(int j = ai; j < bi; j++) visited[2*j + 1][2*aj] = true;
        }
        printf("%s\n", bfs().c_str());
    }
}
