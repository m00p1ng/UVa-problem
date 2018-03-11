#include <cstdio>

int data[9];
int sum;

int move_sum(int i, int j, int k) {
    return sum - (data[i] + data[j] + data[k]);
}

int main() {
    char out[][4] = {"BCG", "BGC", "CBG", "CGB", "GBC", "GCB"};

    while(scanf("%d", &data[0]) == 1) {
        sum = data[0];
        for(int i = 1; i < 9; i++) {
            scanf("%d", &data[i]);
            sum += data[i];
        }

        int min = 1<<30;
        int idx = -1;
        int temp[6];

        temp[0] = move_sum(0, 5, 7);
        temp[1] = move_sum(0, 4, 8);
        temp[2] = move_sum(2, 3, 7);
        temp[3] = move_sum(2, 4, 6);
        temp[4] = move_sum(1, 3, 8);
        temp[5] = move_sum(1, 5, 6);

        for(int i = 0; i < 6; i++) {
            if(temp[i] < min) {
                min = temp[i];
                idx = i;
            }
        }
        printf("%s %d\n", out[idx], min);
    }
}

