#include <cstdio>

int main() {
    int ts = 0;
    int n, temp, created[12];
    while(scanf("%d", &n), n >= 0) {
        for(int i = 0; i < 12; i++) {
            scanf("%d", &created[i]);
        }
        printf("Case %d:\n", ++ts);
        for(int i = 0; i < 12; i++) {
            scanf("%d", &temp);
            if(n - temp >= 0) {
                puts("No problem! :D");
                n -= temp;
            } else {
                puts("No problem. :(");
            }
            n += created[i];
        }
    }
}
