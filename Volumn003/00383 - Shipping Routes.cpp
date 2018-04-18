#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <map>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> ii;

vii graph;
map<string, int> m;

int bfs(int s, int e) {
    queue<ii> q;
    bool visited[1000] = {false};
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
    int ts, n, e, q, c;
    scanf("%d", &ts);

    puts("SHIPPING ROUTES OUTPUT\n");

    for(int t = 1; t <= ts; t++) {
        printf("DATA SET  %d\n\n", t);
        scanf("%d %d %d", &n, &e, &q);
        char a[100], b[100];
        graph.assign(n+2, vi());
        m.clear();
        int cnt = 1;

        for(int i = 0; i < n; i++) {
            scanf("%s", a);
            m[a] = cnt++;
        }
        for(int i = 0; i < e; i++) {
            scanf("%s %s", a, b);
            graph[m[a]].push_back(m[b]);
            graph[m[b]].push_back(m[a]);
        }

        for(int i = 0; i < q; i++) {
            scanf("%d %s %s", &c, a, b);
            int depth = bfs(m[a], m[b]);
            if(depth != -1) {
                printf("$%d\n", c*depth*100);
            } else {
                puts("NO SHIPMENT POSSIBLE");
            }
        }
        puts("");
    }

    puts("END OF OUTPUT");
}
