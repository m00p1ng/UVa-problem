#include <cstdio>
#include <cstring>

int cur[20];
int h, k;

void print_cur() {
    for(int i = 0; i < h; i++) {
        printf("%d", cur[i]);
    }
    puts("");
}

void hamming(int idx, int remain) {
    if(remain < 0) return;
    if(idx == h) {
        if(remain == 0) {
            print_cur();
        }
        return;
    }
    
    hamming(idx+1, remain);
    cur[idx] = 1;
    hamming(idx+1, remain-1);
    cur[idx] = 0;
}

int main() {
    int ts;
    scanf("%d", &ts);

    while(ts--) {
        scanf("%d %d", &h, &k);
        memset(cur, 0, sizeof(0));
        hamming(0, k);


        if(ts) puts("");
    }
}
