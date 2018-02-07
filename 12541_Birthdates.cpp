#include <cstdio>
#include <algorithm>
using namespace std;

struct bd {
    char name[20];
    int d, m, y;
} b[100];

bool cmp(struct bd a, struct bd b) {
    if(a.y > b.y) return true;
    if(a.y < b.y) return false;

    if(a.m > b.m) return true;
    if(a.m < b.m) return false;

    return a.d > b.d;
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s %d %d %d", b[i].name, &b[i].d, &b[i].m, &b[i].y);
    }
    sort(b, b+n, cmp);
    printf("%s\n%s\n", b[0].name, b[n-1].name);
}
