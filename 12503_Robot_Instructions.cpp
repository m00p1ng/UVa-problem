#include <cstdio>

int main() {
    int ts;
    scanf("%d", &ts);

    int instruction[100];
    char temp[1000];
    while(ts--) {
        int n;
        scanf("%d", &n);

        int distance = 0;
        for(int i = 0; i < n; i++) {
            scanf("%s", temp);
            if(temp[0] == 'L') {
                instruction[i] = -1;
            } else if(temp[0] == 'R') {
                instruction[i] = 1;
            } else if(temp[0] == 'S') {
                int ins;
                scanf("%*s %d", &ins);
                instruction[i] = instruction[ins-1];
            }
            distance += instruction[i];
        }
        printf("%d\n", distance);
    }
}
