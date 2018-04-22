#include <cstdio>
#include <cstring>

char query[300];
char pass[100][300];
int n, q;

int cur[300];

void print_pass(int len) {
    for(int i = 0; i < len; i++) {
        if(query[i] == '#') printf("%s", pass[cur[i]]);
        else printf("%d", cur[i]);
    }
    puts("");
}

void create_pass(int, int);

void _create_pass(int idx, int limit, int len) {
    if(idx == len) return;

    for(int i = 0; i < limit; i++) {
        cur[idx] = i;
        if(idx == len-1) print_pass(len);  
        else create_pass(idx+1, len); 
    }
    cur[idx] = 0;
}

void create_pass(int idx, int len) {
    if(query[idx] == '0') _create_pass(idx, 10, len);
    else _create_pass(idx, n, len);
}

int main() {
    while(scanf("%d", &n) == 1) {
        for(int i = 0; i < n; i++) {
            scanf("%s", pass[i]);
        }
        scanf("%d", &q);
        puts("--");
        for(int i = 0; i < q; i++) {
            memset(cur, 0, sizeof(cur));
            scanf("%s", query);
            int len = strlen(query);
            create_pass(0, len);
        }
    }
}
