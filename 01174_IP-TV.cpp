#include <cstdio>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int root[2000];
map<string, int> city;

struct node {
    int i, j, dist;
} nodes[50000];

int find_set(int i) {
    if(root[i] == i) return i;
    return find_set(root[i]);
}

bool union_set(int i, int j) {
    int fi = find_set(i);
    int fj = find_set(j);

    if(fi == fj) return false;
    root[fi] = fj;

    return true;
}

bool cmp(node a, node b) {
    return a.dist < b.dist;
}

int kruskal(int n, int total_edge) {
    sort(nodes, nodes+total_edge, cmp);

    int idx = 0;
    int total_dist = 0;

    while(--n) {
        while(!union_set(nodes[idx].i, nodes[idx].j)) idx++;
        total_dist += nodes[idx++].dist;
    }
    return total_dist;
}

int main() {
    int ts, n, q, d;
    char a[10], b[10];
    scanf("%d", &ts);
    while(ts--) {
        scanf("%d %d", &n, &q);
        city.clear();
        int idx = 1;

        for(int i = 1; i <= n; i++) root[i] = i;
        for(int i = 0; i < q; i++) {
            scanf("%s %s %d", a, b, &d);
            if(city[a] == 0) city[a] = idx++;
            if(city[b] == 0) city[b] = idx++;
            nodes[i] = {city[a], city[b], d};
        }

        printf("%d\n", kruskal(n, q));
        if(ts) puts("");
    }
}
