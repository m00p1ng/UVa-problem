#include <cstdio>
#include <queue>
using namespace std;

typedef pair<int, int> ii;

int dr[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dc[] = {-2, -1, 1, 2, 2, 1, -1, -2};

int bfs(char* a, char* b) {
    queue<ii> q;
    int moves[8][8];
    bool visited[8][8] = {false};
    int si = a[0] - 'a', sj = a[1] - '1';
    int ei = b[0] - 'a', ej = b[1] - '1';

    q.push(ii(si, sj));
    moves[si][sj] = 0;

    while(!q.empty()) {
        ii p = q.front(); q.pop();
        int pi = p.first, pj = p.second;

        if(visited[pi][pj]) continue;
        visited[pi][pj] = true;
        if(pi == ei && pj == ej) return moves[pi][pj];

        for(int d = 0; d < 8; d++) {
            int ci = pi + dr[d];
            int cj = pj + dc[d];
            if(ci >= 0 && ci < 8 && cj >= 0 && cj < 8) {
                q.push(ii(ci, cj));
                moves[ci][cj] = moves[pi][pj] + 1;
            }
        }
    }

    return 0;
}

int main() {
    char a[10], b[10];

    while(scanf("%s %s", a, b) == 2) {
        printf("To get from %s to %s takes %d knight moves.\n", a, b, bfs(a, b));
    }
}
