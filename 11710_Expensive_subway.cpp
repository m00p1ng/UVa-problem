#include <cstdio>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int root[400];
map<string, int> city;

struct node {
    int i, j, dist;
} nodes[79900];

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

int main() {
    int n, q, d, idx, mst, compo;
    char s[100], e[100];
    while(scanf("%d %d", &n, &q), n || q) {
        idx = mst = 0;
        city.clear();

        for(int i = 0; i < n; i++) {
            scanf("%s", s);
            city[s] = i;
            root[i] = i;
        }
        for(int i = 0; i < q; i++) {
            scanf("%s %s %d", s, e, &d);
            nodes[i] = {city[s], city[e], d};
        }
        scanf("%*s");

        sort(nodes, nodes+q, cmp);

        if(q < n-1) compo = 0;
        else {
            compo = n;
            while(compo != 1 && q--) {
                if(union_set(nodes[idx].i, nodes[idx].j)) {
                    compo--;
                    mst += nodes[idx].dist;
                }
                idx++;
            }
        }
        if(compo == 1) printf("%d\n", mst);
        else puts("Impossible");
    }
}
