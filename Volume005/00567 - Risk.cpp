#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> ii;

vii graph;

int bfs(int s, int e) {
    queue<ii> q;
    q.push(ii(0, s));
    bool visited[100] = {false};
    visited[s] = true;

    while(!q.empty()) {
        ii v = q.front(); q.pop();
        
        if(v.second == e) return v.first;

        for(int i = 0; i < graph[v.second].size(); i++) {
            int k = graph[v.second][i];
            if(k && !visited[k]) {
                q.push(ii(v.first+1, k));
                visited[k] = true;
            }
        }
    }
    return -1;
}

int main() {
    int e, k, q, a, b, ts = 0;
    bool flag;

    while(1) {
        if(ts) puts("");
        graph.assign(30, vi());

        for(int i = 1; i <= 19; i++) {
            flag = scanf("%d", &e) == 1;
            if(!flag) break;
            for(int j = 0; j < e; j++) {
                scanf("%d", &k);
                graph[i].push_back(k);
                graph[k].push_back(i);
            }
        }
        if(!flag) break;

        scanf("%d", &q);
        printf("Test Set #%d\n", ++ts);
        for(int i = 0; i < q; i++) {
            scanf("%d %d", &a, &b);
            printf("%2d to %2d: %d\n", a, b, bfs(a, b));
        }
    }
}
