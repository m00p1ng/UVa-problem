#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

typedef vector<int> vi;
vector<vi> graph;
vi ts;
bool visited[101];

void dfs(int u) {
    visited[u] = true;
    for(int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i]; 
        if(!visited[v]) dfs(v);
    }
    ts.push_back(u);
}

int main() {
    int m, n;

    while(scanf("%d %d", &n, &m), n || m) {
        graph.assign(n+1, vi());
        ts.clear();
        memset(visited, false, sizeof(visited));
        int x, y;

        for(int i = 0; i < m; i++) {
            scanf("%d %d", &x, &y);
            graph[x].push_back(y);
        }
        
        for(int i = 1; i <= n; i++) {
            if(!visited[i]) dfs(i);
        }

        printf("%d", ts[ts.size()-1]);
        for(int i = ts.size()-2; i >= 0; i--) {
            printf(" %d", ts[i]);
        }
        puts("");
    }
}
