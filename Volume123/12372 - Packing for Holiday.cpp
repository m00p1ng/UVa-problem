#include <cstdio>

int main() {
    int ts;
    int l,w,h;
    scanf("%d", &ts);
    for(int i = 1; i <= ts; i++) {
        printf("Case %d: ", i);
        scanf("%d %d %d", &l, &w, &h);
        
        if(l > 20 || w > 20 || h > 20) {
            puts("bad"); 
        } else {
            puts("good");
        }
    }
}
