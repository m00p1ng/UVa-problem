#include <cstdio>
#include <map>
#include <string>
using namespace std;

int tree_set[5000];
int cnt_set[5000];
int max_set;

int find_set(int a) {
    if(tree_set[a] == a) return a;
    return find_set(tree_set[a]);
}

void union_set(int a, int b) {
    int fa = find_set(a);
    int fb = find_set(b);

    if(fa == fb) return;

    tree_set[fb] = fa;
    cnt_set[fa] += cnt_set[fb];

    if(cnt_set[fa] > max_set) max_set = cnt_set[fa];
}

int main() {
    int n, q;
    map<string, int> tree;
    char s[100], t[100];
    while(scanf("%d %d", &n, &q), n || q) {
        max_set = 1;
        for(int i = 0; i < n; i++) {
            scanf("%s", s);   
            tree[s] = i;
            tree_set[i] = i;
            cnt_set[i] = 1;
        }
        for(int i = 0; i < q; i++) {
            scanf("%s %s", s, t);
            union_set(tree[s], tree[t]);
        }
        printf("%d\n", max_set);
    }
}
