#include <cstdio>

int main() {
    int ts;
    scanf("%d", &ts);

    puts("Lumberjacks:");
    while(ts--) {
        int prev, next;
        scanf("%d", &prev);
        scanf("%d", &next);

        bool is_inc = false;
        bool is_ord = true;

        if(next-prev > 0) is_inc = true;

        for(int i = 2; i < 10; i++) {
            prev = next;
            scanf("%d", &next);
            
            if((is_inc && next-prev < 0) || (!is_inc && next-prev > 0) || next-prev == 0) {
                is_ord = false;
            }
        }
        if(is_ord) puts("Ordered");
        else puts("Unordered");
    }
}
