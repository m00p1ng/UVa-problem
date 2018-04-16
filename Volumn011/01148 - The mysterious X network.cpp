#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> ii;

vii graph;

int bfs(int s, int e) {
    queue<ii> q;
    bool visited[100010] = {false};
    visited[s] = true;

    q.push(ii(0, s));
    while(!q.empty()) {
        ii u = q.front(); q.pop();

        if(u.second == e) {
            return u.first;
        }

        for(int i = 0; i < graph[u.second].size(); i++) {
            int v = graph[u.second][i];
            if(!visited[v]) {
                q.push(ii(u.first+1, v));
                visited[v] = true;
            }
        }
    }
    return -1;
}

int main() {
    int ts, n, u, e, v;
    scanf("%d", &ts);

    while(ts--) {
        scanf("%d", &n);
        graph.assign(n+2, vi());

        for(int i = 0; i < n; i++) {
            scanf("%d %d", &u, &e);
            for(int j = 0; j < e; j++) {
                scanf("%d", &v);
                graph[u].push_back(v);
            }
        }

        scanf("%d %d", &u, &v);
        int depth = bfs(u, v);
        printf("%d %d %d\n", u, v, depth-1);
        if(ts) puts("");
    }
}
