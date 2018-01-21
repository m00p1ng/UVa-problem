#include <cstdio>
#include <cstring>

int main() {
    int ts, c, l;
    char temp, line[20000];
    scanf("%d", &ts);
    long long sum, cost[256], val;
    while(ts--) {
        sum = 0;
        memset(cost, 0, sizeof(cost));
        scanf("%d\n", &c);
        
        for(int i = 0; i < c; i++) {
            scanf("%c %lld\n", &temp, &val);
            cost[temp+128] = val;
        }
        scanf("%d\n", &l);
        for(int i = 0; i < l; i++) {
            fgets(line, 10010, stdin);
            for(int i = 0; i < strlen(line); i++) {
                sum += cost[line[i]+128];
            }
        }
        printf("%lld.%02lld$\n", sum/100, sum % 100);
    }
}
