#include <cstdio>
#include <map>
#include <vector>
using namespace std;

int main() {
    map<int, vector<int>> dict;

    int n, m;
    int num;
    int k, v;
    while(scanf("%d %d", &n, &m) == 2) {
        dict.clear();
        for(int i = 1; i <= n; i++) {
            scanf("%d", &num);
            dict[num].push_back(i);
        }

        for(int i = 0; i < m; i++) {
            scanf("%d %d", &k, &v);
            if(dict[v].size() < k) puts("0");
            else printf("%d\n", dict[v][k-1]);
        }
    }
}

