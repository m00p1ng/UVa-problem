#include <cstdio>
#include <algorithm>
using namespace std;

struct shoe {
    int job;
    double fine;
} shoes[1000];

bool cmp(struct shoe a, struct shoe b) {
    if(a.fine < b.fine) return true;
    if(a.fine > b.fine) return false;
    return a.job < b.job;
}

int main() {
    int ts, n;
    int t, s;
    scanf("%d", &ts);
    while(ts--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%d %d", &t, &s);
            shoes[i].job = i+1;
            shoes[i].fine = t/(double)s;
        }
        sort(shoes, shoes+n, cmp);

        for(int i = 0; i < n; i++) {
            if(i) putchar(' ');
            printf("%d", shoes[i].job);
        }
        puts("");
        if(ts) puts("");
    }
}
