#include <cstdio>
#include <cstring>

int main (){
    int ts, f, m;
    char s[10000];
    scanf("%d\n", &ts);
    while(ts--) {
        fgets(s, 10000, stdin);
        int len = strlen(s);

        m = f = 0;
        for(int i = 0; i < len; i++) {
            if(s[i] == 'M') m++;
            else if(s[i] == 'F') f++;
        }

        if(m != f || m <= 1 || f <= 1) puts("NO LOOP");
        else puts("LOOP");
    }
}
