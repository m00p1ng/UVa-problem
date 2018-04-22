#include <cstdio>

int main() {
    int ts;
    scanf("%d", &ts);
    int sum = 0;
    while(ts--) {
        char temp[100];
        scanf("%s", temp);

        int money;
        if(temp[0] == 'd') {
            scanf("%d", &money);
            sum += money;
        } else {
            printf("%d\n", sum);
        }
    }
}
