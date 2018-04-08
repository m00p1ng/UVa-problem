#include <cstdio>
#include <cstring>

int main() {
    int r, cnt, lost;
    char t[10000];
    bool flag[26], visited[26];
    while(scanf("%d", &r), r != -1) {
        scanf("%s", t);

        cnt = lost = 0;
        memset(flag, 0, sizeof(flag));
        memset(visited, 0, sizeof(visited));
        for(int i = 0; i < strlen(t); i++) {
            if(!flag[t[i]-'a']) {
                flag[t[i]-'a'] = true;
                cnt++;
            }
        }

        scanf("%s", t);
        for(int i = 0; i < strlen(t); i++) {
            if(!visited[t[i]-'a']) {
                if(flag[t[i]-'a']) {
                    cnt--;
                    if(cnt == 0) break;
                }
                else lost++;
                visited[t[i]-'a'] = true;
            }
        }

        printf("Round %d\n", r);
        if(lost >= 7) puts("You lose.");
        else if(cnt == 0) puts("You win.");
        else puts("You chickened out.");
    }
}
