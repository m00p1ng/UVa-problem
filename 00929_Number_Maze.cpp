#include <cstdio>
#include <queue>
#include <vector>
#define INF 1e9
using namespace std;

typedef pair<int,int> ii;
typedef pair<int, ii> iii;

int board[1000][1000];
int dist[1000][1000];
int row, col;
priority_queue<iii, vector<iii>, greater<iii>> pq;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void get_board() {
    scanf("%d %d", &row, &col);

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            scanf("%d", &board[i][j]);
            dist[i][j] = INF;
        }
    }
}

bool in_board(int i, int j) {
    return i >= 0 && j >= 0 && i < row && j < col;
}

void dijikstra() {
    pq.push(iii(board[0][0], ii(0, 0)));
    dist[0][0] = board[0][0];

    while(!pq.empty()) {
        iii cur = pq.top(); pq.pop();

        int cd = cur.first;
        ii p = cur.second;

        if(cd > dist[p.first][p.second]) continue;
        for(int d = 0; d < 4; d++) {
            int r = p.first + dr[d];
            int c = p.second + dc[d];
            if(!in_board(r, c)) continue;
            if(dist[p.first][p.second] + board[r][c] < dist[r][c]) {
                dist[r][c] = dist[p.first][p.second] + board[r][c]; 
                pq.push(iii(dist[r][c], ii(r, c)));
            }
        }
    }
}

int main() {
    int ts;
    scanf("%d", & ts);

    while(ts--) {
        get_board();
        dijikstra();

        printf("%d\n", dist[row-1][col-1]);
    }
}
