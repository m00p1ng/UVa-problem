#include <cstdio>
#include <cstring>

int lotto[20];
int cur[6];

void print_lotto() {
    for(int i = 0; i < 6; i++) {
        if(i != 0) putchar(' ');
        printf("%d", lotto[cur[i]]); 
    }
    puts("");
}

void find_lotto(int idx, int remain, int end) {
    if(remain == 0) {
        print_lotto();
        return;
    }

    int ii = 6-remain;
    for(int i = idx; i < end-remain+1; i++) {
        cur[ii] = i;
        find_lotto(i+1, remain-1, end);
    }
}

int main() {
    int n;
    bool first = true;
    while(scanf("%d", &n), n) {
        memset(cur, 0, sizeof(cur));
        if(!first) puts(""); 
        first = false;

        for(int i = 0; i < n; i++) {
            scanf("%d", &lotto[i]);
        }

        find_lotto(0, 6, n);
    }
}
