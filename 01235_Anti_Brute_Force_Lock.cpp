#include <cstdio>
#include <algorithm>
using namespace std;

char pass[500][5];
int root[500];

struct node {
    int i, j, dist;
} nodes[124750];

int abs(int n) {
    return n > 0 ? n : -n;
}

int distance(int a, int b) {
    int cnt = 0;
    int diff;
    for(int i = 0; i < 4; i++) {
        if(a == -1) diff = pass[b][i]-'0';
        else diff = abs(pass[a][i]-pass[b][i]);

        if(diff > 5) cnt += 10-diff;
        else cnt+= diff;
    }
    return cnt;
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
    int ts, n, idx;
    scanf("%d", &ts);
    while(ts--) {
        scanf("%d", &n);
        idx = 0;
        int start_point = 1e8;

        for(int i = 0; i < n; i++) {
            root[i] = i;
            scanf("%s", pass[i]);

            int from_start = distance(-1, i);
            if(from_start < start_point) start_point = from_start;
            for(int j = 0; j < i; j++) {
                nodes[idx++] = {i, j, distance(i, j)};
            }
        }
        printf("%d\n", kruskal(n, idx)+start_point);
    }
}
