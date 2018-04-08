#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

vector<vi> graph;
bool visited[2510];
int days[2510];
int n;

ii bfs(int start) {
    queue<ii> q;
    int mday = 0, mboom = 0;
    memset(visited, false, sizeof(visited));
    memset(days, 0, sizeof(days));

    q.push(ii(start, 0));
    visited[start] = true;

    while(!q.empty()) {
        ii p = q.front(); q.pop();
        for(int i = 0; i < graph[p.first].size(); i++) {
            int v = graph[p.first][i];
            if(!visited[v]) {
                int nday = p.second+1;
                days[nday]++;

                if(days[nday] > mboom) {
                    mboom = days[nday];
                    mday = nday;
                }

                visited[v] = true;
                q.push(ii(v, nday));
            }
        }
    }
    return ii(mboom, mday);
}

typedef vector<int> vi;
int main() {
    int m, k, q;
    scanf("%d", &n);
    graph.assign(n, vi());

    for(int i = 0; i < n; i++) {
        scanf("%d", &m);
        for(int j = 0; j < m; j++) {
            scanf("%d", &k);
            graph[i].push_back(k);
        }
    }

    scanf("%d", &q);
    for(int i = 0; i < q; i++) {
        scanf("%d", &k);
        ii p = bfs(k);
        if(p.first == 0) puts("0");
        else printf("%d %d\n", p.first, p.second);
    }
}
