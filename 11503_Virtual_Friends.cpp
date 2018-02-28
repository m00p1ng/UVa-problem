#include <cstdio>
#include <cstring>
#include <map>
#include <string>
using namespace std;

int root[100001];
int cnt[100001];

int find_set(int a) {
    if(root[a] == a) return a;
    return find_set(root[a]);
}

int union_set(int a, int b) {
    int fa = find_set(a);
    int fb = find_set(b);

    if(fa == fb) return cnt[fa];

    root[fb] = fa;
    cnt[fa] += cnt[fb];
    return cnt[fa];
}

int main() {
    int ts, n;
    int rnd;
    char a[30], b[30];
    map<string, int> name;
    scanf("%d", &ts);

    while(ts--) {
        name.clear();
        rnd = 1;
        memset(root, 0, sizeof(root));
        memset(cnt, 0, sizeof(cnt));
        scanf("%d", &n);

        for(int i = 0; i < n; i++) {
            scanf("%s %s", a, b); 
            if(name[a] == 0) {
                name[a] = root[rnd] = rnd;
                cnt[rnd++] = 1;
            }
            if(name[b] == 0) {
                name[b] = root[rnd] = rnd;
                cnt[rnd++] = 1;
            }
            printf("%d\n", union_set(name[a], name[b]));
        }
    }
}
