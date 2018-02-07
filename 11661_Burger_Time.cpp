#include <cstdio>

int main() {
    int n;
    char s[2000010];
    int idx, dis;
    bool r = false;
    while(scanf("%d %s", &n, s) == 2) {
        dis = 1e8;

        int i = 0;
        while(s[i] == '.') i++;

        if(s[i] == 'R') r = true; 
        else if(s[i] == 'D') r = false; 
        else if(s[i] == 'Z') dis = 0; 
        idx = i;

        while(i < n) {
            while(s[i] == '.') i++;

            if(s[i] == 'Z') {
                dis = 0;
                break;
            } else if((r && s[i] == 'R') || (!r && s[i] == 'D')) {
                idx = i; 
            } else if((!r && s[i] == 'R') || (r && s[i] == 'D')) {
                if(s[i] == 'R') r = true;
                else r = false; 
                dis = dis < i-idx ? dis : i-idx;
                idx = i;
            }
            i++;
        }
        printf("%d\n", dis);
    }
}
