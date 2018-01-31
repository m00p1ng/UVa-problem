#include <cstdio>

int abs(int n) {
    return n > 0 ? n : -n;
}

int main() {
    int n;
    int box[100];
    int ts = 0;
    while(scanf("%d", &n), n) {
        int sum = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d", &box[i]);
            sum += box[i];
        }
        int avg = sum/n;
        int diff = 0;
        for(int i = 0; i < n; i++) {
            diff += abs(box[i] - avg);
        }
        printf("Set #%d\n", ++ts);
        printf("The minimum number of moves is %d.\n\n", diff>>1);
    }
}
