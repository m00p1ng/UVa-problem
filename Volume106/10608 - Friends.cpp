#include <cstdio>
#include <cstring>

int f_set[30010];
int people_group[30010];
int max;


void init_group(int n) {
    for(int i = 1; i <= n; i++) {
        f_set[i] = i;
        people_group[i] = 1;
    }
}

int find_set(int a) {
    if(f_set[a] == a) return a;
    return find_set(f_set[a]);
}

void union_set(int a, int b) {
    int fa = find_set(a);
    int fb = find_set(b);

    if(fa == fb) return;
    
    f_set[fb] = fa;

    people_group[fa] += people_group[fb];
    people_group[fb] = 0;
    if(people_group[fa] > max) max = people_group[fa];
}

int main() {
    int ts;
    int n, m;
    int a, b;
    scanf("%d", & ts);

    while(ts--) {
        memset(f_set, 0, sizeof(f_set));
        max = 1;

        scanf("%d %d", &n, &m);
        init_group(n);
        for(int i = 0; i < m; i++) {
            scanf("%d %d", &a, &b);
            union_set(a, b);
        }
        printf("%d\n", max);
    }
}
