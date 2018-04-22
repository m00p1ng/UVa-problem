#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <string>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, string> is;

vii graph;
map<string, int> m;
char city_name[1000];


void bfs(int s, int e) {
    queue<is> q;
    bool visited[1000] = {false};
    visited[s] = true;

    q.push(is(s, ""));
    while(!q.empty()) {
        is u = q.front(); q.pop();

        if(u.first == e) {
            u.second = city_name[s] + u.second;
            puts(u.second.c_str());
        }

        for(int i = 0; i < graph[u.first].size(); i++) {
            int v = graph[u.first][i];
            if(!visited[v]) {
                q.push(is(v, u.second+city_name[v]));
                visited[v] = true;
            }
        }
    }
}

int main() {
    int ts, n, q;
    scanf("%d", &ts);

    while(ts--) {
        scanf("%d %d", &n, &q);
        int cnt = 1;
        char a[100], b[100];
        graph.assign(n+2, vi());
        m.clear();

        for(int i = 0; i < n; i++) {
            scanf("%s %s", a, b);
            if(m[a] == 0) {
                city_name[cnt] = a[0];
                m[a] = cnt++;
            }
            if(m[b] == 0) {
                city_name[cnt] = b[0];
                m[b] = cnt++;
            }
            graph[m[a]].push_back(m[b]);
            graph[m[b]].push_back(m[a]);
        }

        for(int i = 0; i < q; i++) {
            scanf("%s %s", a, b);
            bfs(m[a], m[b]);
        }
        if(ts) puts("");
    }
}
