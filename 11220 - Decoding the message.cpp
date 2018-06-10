#include <cstdio>
#include <cstring>

int main() {
    int ts;
    char buff[1000];
    scanf("%d\n\n", &ts);
    for(int t = 1; t <= ts; t++) { 
        if(t != 1) puts("");
        printf("Case #%d:\n", t);

        while(fgets(buff, 1000, stdin) && buff[0] != '\n') {
            buff[strlen(buff)-1] = '\0';
            int cur = 0;
            char* p = strtok(buff, " ");
            while(p != NULL) {
                if(strlen(p) >= cur+1) {
                    printf("%c", p[cur++]);
                }
                p = strtok(NULL, " ");
            }
            puts("");
        }
    }
}
