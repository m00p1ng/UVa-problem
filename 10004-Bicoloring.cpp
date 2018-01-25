#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int colors[200];
int n;
bool is_bi;
vector<vector<int>> graph(200);

void dfs(int node, int c) {
    if(graph[node].empty()) return;
    for(int i = 0; i < graph[node].size(); i++) {
        int idx = graph[node][i];
        if(colors[idx] == 0) {
            colors[idx] = -c;
            dfs(idx, -c);
        } else if(colors[idx] == colors[node]) {
            is_bi = false;
            return;
        }
    }
}

int main() {
    int a, b, e;
    while(scanf("%d", &n), n) {
        graph.assign(n, vector<int>());
        scanf("%d", &e);
        for(int i = 0; i < e; i++) {
            scanf("%d %d", &a, &b);
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        memset(colors, 0, sizeof(colors));

        is_bi = true;
        dfs(0, 1);

        if(!is_bi) printf("NOT ");
        puts("BICOLORABLE.");
    }
}
