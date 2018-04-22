#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

double x[5000], y[5000];
int root[100];

struct node {
    int i, j;
    double dist;
} nodes[5000];

double distance(int i, int j) {
    double dx = x[i]-x[j];
    double dy = y[i]-y[j];
    return sqrt(dx*dx+dy*dy);
}

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

double kruskal(int n, int total_edge) {
    sort(nodes, nodes+total_edge, cmp);

    int idx = 0;
    double total_dist = 0;

    while(--n) {
        while(!union_set(nodes[idx].i, nodes[idx].j)) idx++;
        total_dist += nodes[idx++].dist;
    }
    return total_dist;
}

int main() {
    int ts, n;
    scanf("%d", &ts);
    while(ts--) {
        scanf("%d", &n);
        int idx = 0;

        for(int i = 0; i < n; i++) {
            root[i] = i;
            scanf("%lf %lf", &x[i], &y[i]);
            for(int j = 0; j < i; j++) {
                nodes[idx++] = {i, j, distance(i, j)};
            }
        }

        printf("%.2lf\n", kruskal(n, idx));
        if(ts) puts("");
    }
}
