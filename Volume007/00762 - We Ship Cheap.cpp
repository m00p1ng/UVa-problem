#include <cstdio>
#include <cstring>
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
char city_name[1000][3];

string bfs(int s, int e) {
    queue<is> q;
    bool visited[1000] = {false};
    visited[s] = true;

    q.push(is(s, city_name[s]));
    while(!q.empty()) {
        is u = q.front(); q.pop();

        if(u.first == e) {
            return u.second;
        }

        for(int i = 0; i < graph[u.first].size(); i++) {
            int v = graph[u.first][i];
            if(!visited[v]) {
                q.push(is(v, u.second + city_name[v]));
                visited[v] = true;
            }
        }
    }
    return "No route";
}

void print_route(string s) {
    int len = s.length();
    printf("%c%c ", s[0], s[1]);
    for(int i = 1; i < len/2 - 1; i++) {
        printf("%c%c\n", s[2*i], s[2*i+1]);
        printf("%c%c ", s[2*i], s[2*i+1]);
    }
    printf("%c%c\n", s[len-2], s[len-1]);
}

int main() {
    int n;
    bool ts = false;

    while(scanf("%d", &n) == 1) {
        int cnt = 1;
        char a[100], b[100];
        graph.assign(n+2, vi());
        m.clear();

        for(int i = 0; i < n; i++) {
            scanf("%s %s", a, b);
            if(m[a] == 0) {
                strcpy(city_name[cnt], a);
                m[a] = cnt++;
            }
            if(m[b] == 0) {
                strcpy(city_name[cnt], b);
                m[b] = cnt++;
            }
            graph[m[a]].push_back(m[b]);
            graph[m[b]].push_back(m[a]);
        }

        if(ts) puts("");
        ts = true;

        scanf("%s %s", a, b);
        if(m[a] == 0 || m[b] == 0) {
            puts("No route");
            continue;
        }
        string res =  bfs(m[a], m[b]);
        if(res != "No route") {
            print_route(res);
        } else {
            puts("No route");
        }
    }
}
