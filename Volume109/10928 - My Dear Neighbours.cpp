#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int main() {
    int ts, n;
    char temp[10000];
    scanf("%d", &ts);

    while(ts--) {
        scanf("%d\n", &n);
        int idx = 0;
        int place[2000];
        int min = 999999999;

        for(int i = 1; i <= n; i++) {
            fgets(temp, 10000, stdin);
            char* p = strtok(temp, " ");
            int cnt = 0;

            while(p != NULL) {
                cnt++;
                p = strtok(NULL, " ");
            }

            if(cnt == min) {
                place[idx++] = i;
            } else if(cnt < min) {
                min = cnt;
                idx = 0;
                place[idx++] = i;
            }
        }
        printf("%d", place[0]);
        for(int i = 1; i < idx; i++) {
            printf(" %d", place[i]);
        }
        puts("");
    }
}
