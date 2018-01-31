#include <cstdio>
#include <cstring>

int main() {
    char pad[] = "12312312312312312341231234";
    char s[110];
    int ts;
    scanf("%d%*c", &ts);

    for(int t = 1; t <= ts; t++) {
        fgets(s, 110, stdin);

        int sum = 0;
        for(int i = 0; i < strlen(s)-1; i++) {
            if(s[i] == ' ') sum++;
            else sum += pad[s[i]-'a'] - '0';
        }
        printf("Case #%d: %d\n", t, sum);
    }
}
