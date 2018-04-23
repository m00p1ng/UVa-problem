#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <vector>
#include <string>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

vector<vi> graph;
map<string, int> m;

int bfs(int s, int e) {
    queue<ii> q;
    bool visited[210] = {false};
    q.push(ii(0, s));
    visited[s] = true;

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
    int ts, len[210];
    char data[210][1000], a[1000], b[1000], temp[1000];
    scanf("%d", &ts);

    while(ts--) {
        int n = 1;
        graph.assign(210, vi());
        m.clear();

        while(scanf("%s\n", data[n]), data[n][0] != '*') {
            m[data[n]] = n;
            len[n] = strlen(data[n]);
            for(int j = 1; j < n; j++) {
                int diff = 0;
                for(int k = 0; k < len[n]; k++) {
                    if(data[j][k] != data[n][k]) diff++;
                }
                if(diff == 1) {
                    graph[n].push_back(j);
                    graph[j].push_back(n);
                }
            }
            n++;
        }
        while(fgets(temp, 1000, stdin) && temp[0] != '\n') {
            sscanf(temp, "%s %s\n", a, b);
            printf("%s %s %d\n", a, b, bfs(m[a], m[b]));
        }
        if(ts) puts("");
    }
}
