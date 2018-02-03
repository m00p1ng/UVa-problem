#include <cstdio>
#include <cstring>

int main() {
    int ts;
    char s[100];
    scanf("%d", &ts);
    while(ts--) {
        scanf("%s", s);
        int len = strlen(s);
        int sum = 0;
        int curscore = 1;
        for(int i = 0; i < len; i++) {
            if(s[i] == 'X') curscore = 1; 
            else {
                sum += curscore;
                curscore++;
            }
        }
        printf("%d\n", sum);
    }
}
