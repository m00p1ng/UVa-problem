#include <cstdio>

enum {OK, WRONG, OUTPUT};

int main() {
    int ts;
    char a[100], b[100];
    scanf("%d\n", &ts);
    for(int t = 1; t <= ts; t++) {
        fgets(a, 100, stdin);
        fgets(b, 100, stdin);
        int i = 0, j = 0;
        int flag = OUTPUT;

        while(a[i] && b[j]) {
            while(a[i] == ' ') i++;
            while(b[j] == ' ') j++;
            if(a[i] != b[j]) {
                flag = WRONG;
                break;
            }
            i++, j++;
        }
        if(i == j && flag != WRONG) flag = OK;
        printf("Case %d: ", t);
        if(flag == OK) puts("Yes");
        else if(flag == WRONG) puts("Wrong Answer");
        else puts("Output Format Error");
    }
}
