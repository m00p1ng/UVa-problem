#include <cstdio>

int _set[50010];
int rel;

int find_set(int n) {
    if(_set[n] == n) return n;
    return find_set(_set[n]);
}

void union_set(int a, int b) {
    int fa = find_set(a);
    int fb = find_set(b);

    if(fa != fb) rel--;
    _set[fb] = fa;
}

int main() {
    int cnt = 0, n, m;
    int a, b;
    while(scanf("%d %d", &n, &m), n || m) {
        rel = n;
        for(int i = 1; i <= n; i++) _set[i] = i; 
        for(int i = 0; i < m; i++) {
            scanf("%d %d", &a, &b);
            union_set(a, b);
        }
        printf("Case %d: %d\n", ++cnt, rel);
    }
}
