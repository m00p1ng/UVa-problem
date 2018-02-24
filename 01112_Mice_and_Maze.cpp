#include <cstdio>
#include <queue>
#include <vector>
#define INF 1E9
using namespace std;

int n, s, t, q;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vi dist;
vector<vii> graph;
priority_queue<ii, vii, greater<ii>> pq;

void input_graph() {
    int a, b, d;
    graph.assign(n+1, vii());
    for(int i = 0; i < q; i++) {
        scanf("%d %d %d", &a, &b, &d);
        graph[b].push_back(ii(a, d));
    }
}

void dijiksta() {
    dist.assign(n+1, INF);
    dist[s] = 0;

    pq.push(ii(0, s));

    while(!pq.empty()) {
        ii cur = pq.top(); pq.pop();
        int ud = cur.first;
        int u = cur.second;

        if(ud > dist[u]) continue;
        for(int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i].first;
            int vd = graph[u][i].second;
            int new_dist = dist[u]+vd;

            if(new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push(ii(new_dist, v));
            }
        }
    }
}

int main() {
    int ts;
    scanf("%d", &ts);
    while(ts--) {
        scanf("%d %d %d %d", &n, &s, &t, &q);
        input_graph();
        dijiksta();
        int cnt = 0;
        for(int i = 1; i <= n; i++) if(dist[i] <= t) cnt++;
        printf("%d\n", cnt);
        if(ts) puts("");
    }
}
