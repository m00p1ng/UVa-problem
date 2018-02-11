#include <cstdio>
#include <vector>
#include <map>
#include <queue>
using namespace std;

typedef pair<int, int> ii;

map<int, vector<int>> graph;
map<int, int> visited;

int bfs(int start, int depth) {
    queue<ii> q;
    visited.clear();

    q.push(ii(start, 0));
    int reach = 0;
    while(!q.empty()) {
        ii cur = q.front(); q.pop();

        if(cur.second > depth) continue;
        if(graph[cur.first].empty() || visited[cur.first]) continue;
        visited[cur.first] = true;
        reach++;

        for(int i = 0; i < graph[cur.first].size(); i++) {
            q.push(ii(graph[cur.first][i], cur.second+1));
        }
    }
    return reach;
}

int main() {
    int n;
    int a, b, reach, cnt;
    int ts = 0;

    while(scanf("%d", &n), n) {
        graph.clear();
        cnt = 0;

        for(int i = 0; i < n; i++) {
            scanf("%d %d", &a, &b);
            if(graph[a].empty()) cnt++;
            if(a != b && graph[b].empty()) cnt++;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        while(scanf("%d %d", &a, &b), a || b) {
            reach = bfs(a, b);
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", ++ts, cnt-reach, a, b);
        }
    }
}
