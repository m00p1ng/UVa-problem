#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int ts;
    int n, p, q;
    int eggs[100];
    scanf("%d", &ts);
    for(int t = 1; t <= ts; t++) {
        scanf("%d %d %d", &n, &p, &q);
        for(int i = 0; i < n; i++) {
            scanf("%d", &eggs[i]);
        }
        sort(eggs, eggs+n);
        int w = 0, i = 0;

        while(i < p && i < n) {
            w += eggs[i];
            if(w > q) break;
            i++;
        }
        printf("Case %d: %d\n", t, i); 
    }
}
