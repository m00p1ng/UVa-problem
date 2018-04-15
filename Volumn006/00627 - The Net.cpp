#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>
#include <string>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, string> is;

vii graph;

string num_toString(int n) {
    string res = "";
    while(n > 0) {
        res = (char)(n % 10 + '0') + res;
        n /= 10;
    }
    return res;
}

string bfs(int s, int e) {
    queue<is> q;
    bool visited[1000] = {false};
    visited[s] = true;

    q.push(is(s, num_toString(s)));
    while(!q.empty()) {
        is u = q.front(); q.pop();

        if(u.first == e) {
            return u.second;
        }

        for(int i = 0; i < graph[u.first].size(); i++) {
            int v = graph[u.first][i];
            if(!visited[v]) {
                q.push(is(v, u.second + " " + num_toString(v)));
                visited[v] = true;
            }
        }
    }
    return "connection impossible";
}

void handle_line(char* s) {
    char* p = strtok(s, "-");
    int u = atoi(p);

    p = strtok(NULL, ",");
    while(p != NULL) {
        graph[u].push_back(atoi(p)); 
        p = strtok(NULL, ",");
    }
}

int main() {
    int n, q, a, b;

    while(scanf("%d", &n) == 1) {
        char temp[1000];
        graph.assign(n+2, vi());

        for(int i = 0; i < n; i++) {
            scanf("%s", temp);
            handle_line(temp);
        }

        puts("-----");
        scanf("%d", &q);
        for(int i = 0; i < q; i++) {
            scanf("%d %d", &a, &b);
            puts(bfs(a, b).c_str());
        }
    }
}
