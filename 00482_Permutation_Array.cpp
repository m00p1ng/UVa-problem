#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

int main() {
    int ts;
    int total, total2;
    char buff[100005], data[100005];
    string da[10000];
    char *tok;
    int li[10000];
    scanf("%d\n", &ts);

    while(ts--) {
        scanf("\n");

        fgets(buff, 100000, stdin);
        buff[strlen(buff)-1] = '\0';

        fgets(data, 100000, stdin);
        data[strlen(data)-1] = '\0';

        tok = strtok(buff, " ");
        total = total2 = 0;

        while(tok != NULL) {
            li[total++] = atoi(tok)-1;
            tok = strtok(NULL, " ");
        }

        tok = strtok(data, " ");

        while(tok != NULL) {
            da[li[total2]] = tok;
            total2++;
            tok = strtok(NULL, " ");
        }
        for(int i = 0; i < total; i++) printf("%s\n", da[i].c_str()); 
        if(ts) puts("");
    }
}


