#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> ii;

vii graph;
int number[1010];
bool visited[1010];

void bfs() {
    queue<ii> q;

    q.push(ii(0, 0));
    
    while (!q.empty()) {
        ii v = q.front(); q.pop();
        int node = v.first;
        int depth = v.second;

        if (visited[node]) {
            continue;
        }

        visited[node] = true; 
        number[node] = depth;

        for (int i = 0; i < graph[node].size(); i++) {
            int point = graph[node][i];

            q.push(ii(point, depth+1));
        }
    }
}

int main() {
    int ts;
    int p, d, u, v;
    scanf("%d", &ts);

    while (ts--) {
        scanf("%d %d", &p, &d);
        graph.assign(p, vi());
        memset(number, 0, sizeof(number));
        memset(visited, 0, sizeof(visited));

        for (int i = 0; i < d; i++) {
            scanf("%d %d", &u, &v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        bfs();

        for (int i = 1; i < p; i++) {
            printf("%d\n", number[i]);
        }
        
        if(ts) {
            puts("");
        }
    }
}
