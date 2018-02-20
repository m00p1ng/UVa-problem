#include <cstdio>
#include <algorithm>
using namespace std;

int root[200000];

struct node {
    int i, j, dist;
} nodes[200000];

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
    int total_dist = 0;
    int idx = 0;

    sort(nodes, nodes+total_edge, cmp);

    while(--n) {
        while(!union_set(nodes[idx].i, nodes[idx].j)) idx++;
        total_dist += nodes[idx++].dist;
    }
    return total_dist;
}

int main() {
    int n, q, x, y, d;
    int sum;
    while(scanf("%d %d", &n, &q), n || q) {
        sum = 0;

        for(int i = 0; i < n; i++) root[i] = i;
        for(int i = 0; i < q; i++) {
            scanf("%d %d %d", &x, &y, &d);
            nodes[i] = {x, y, d};
            sum += d;
        }

        printf("%d\n", sum-kruskal(n, q));
    }
}
