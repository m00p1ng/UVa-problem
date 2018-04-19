#include <cstdio>
#include <cstring>
#define INF 1<<20

bool graph[110][110];
bool visited[110];
int dp[110][110];
int node;

int min(int a, int b) {
    return a < b ? a : b;
}

void warshall() {
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= 100; i++) {
        if(visited[i]) for(int j = 1; j <= 100; j++) {
            dp[i][j] = graph[i][j] ? 1 : INF;
        }
    }

    for(int k = 1; k <= 100; k++) {
        if(visited[k]) for(int i = 1; i <= 100; i++) {
            if(visited[i]) for(int j = 1; j <= 100; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
}

void visited_mark(int k) {
    if(!visited[k]) {
        visited[k] = true;
        node++;
    }
}

double avg_click() {
    double sum = 0;

    for(int i = 1; i <= 100; i++) {
        for(int j = 1; j <= 100; j++) {
            if(dp[i][j] != INF && i != j) {
                sum += dp[i][j];
            }
        }
    }
    return sum/(node*(node-1));
}

int main() {
    int a, b, ts = 0;

    while(scanf("%d %d", &a, &b), a || b) {
        memset(visited, false, sizeof(visited));
        memset(graph, false, sizeof(graph));
        graph[a][b] = true;
        node = 0;

        visited_mark(a);
        visited_mark(b);

        while(scanf("%d %d", &a, &b), a || b) {
            graph[a][b] = true;
            visited_mark(a);
            visited_mark(b);
        }
        warshall();
        printf("Case %d: average length between pages = %.3lf clicks\n", ++ts, avg_click());
    }
}
