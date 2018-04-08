#include <cstdio>
#include <vector>
#include <queue>
#define INF 1E9
using namespace std;

int n, m, S, T;
int dist[20000];

typedef pair<int, int> ii;
typedef vector<ii> vii;

vector<vii> graph;
priority_queue<ii, vector<ii>, greater<ii>> pq;

void input_graph() {
    graph.assign(n, vii());
    int a, b, d;
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &d);
        graph[a].push_back(ii(b, d));
        graph[b].push_back(ii(a, d));
    }
}

void dijikstra() {
    for(int i = 0; i < n; i++) dist[i] = INF;
    dist[S] = 0;
    pq.push(ii(0, S));

    while(!pq.empty()) {
        ii cur = pq.top(); pq.pop();
        int d = cur.first;
        int u = cur.second;

        if(d > dist[u]) continue;
        for(int idx = 0; idx < graph[u].size(); idx++) {
            ii v = graph[u][idx];

            int new_dist = dist[u]+v.second;
            if(new_dist < dist[v.first]) {
                dist[v.first] = new_dist;
                pq.push(ii(new_dist, v.first));
            }
        }
    }
}

int main() {
    int ts;
    scanf("%d", &ts);

    for(int t = 1; t <= ts; t++) {
        scanf("%d %d %d %d", &n, &m, &S, &T);
        input_graph();
        dijikstra();

        printf("Case #%d: ", t);
        if(dist[T] == INF) puts("unreachable");
        else printf("%d\n", dist[T]);
    }
}
