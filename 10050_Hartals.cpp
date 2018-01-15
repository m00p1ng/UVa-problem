#include <cstdio>
#include <cstring>

int main() {
    int ts;
    scanf("%d", &ts);
    int day, n, temp, out;
    bool hartal[4000];

    while(ts--) {
        memset(hartal, 0, sizeof(hartal));
        out = 0;

        scanf("%d", &day);
        scanf("%d", &n);

        for(int i = 0; i < n; i++) {
            scanf("%d", &temp);
            for(int j = temp; j <= day; j+=temp) {
                if(j % 7 != 6 && j % 7 != 0 && !hartal[j]) {
                    hartal[j] = true;
                    out++;
                }
            }
        }
        
        printf("%d\n", out);
    }
}
