#include <cstdio>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int main() {
    int n, tmp[5];
    char s[100];
    map<string, int> rec;

    while(scanf("%d", &n), n) {
        int mx = 1;
        int g = n;
        rec.clear();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 5; j++) {
                scanf("%d", &tmp[j]);
            }
            sort(tmp, tmp+5);
            sprintf(s, "%d%d%d%d%d", tmp[0], tmp[1], tmp[2], tmp[3], tmp[4]);
            rec[s]++;

            if(rec[s] > mx) {
                mx = rec[s];
                g = 1;
            } else if(rec[s] > 1 && rec[s] == mx) {
                g++;
            }
        }
        printf("%d\n", g*mx);
    }
}
