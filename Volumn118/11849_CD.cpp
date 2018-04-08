#include <cstdio>
#include <map>
using namespace std;

int main() {
    int n, m;
    int temp;
    int cnt;
    
    map<int, int> cd;
    while(scanf("%d %d", &n, &m), n || m) {
        cd.clear();             
        cnt = 0;


        for(int i = 0; i < n; i++) {
            scanf("%d", &temp); 
            cd[temp]++;
        }

        for(int i = 0; i < m; i++) {
            scanf("%d", &temp); 
            if(cd[temp]) {
                cnt++;
            }
        }
        printf("%d\n", cnt);
    }
}
