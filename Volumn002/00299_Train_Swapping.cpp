#include <cstdio>

void swap(int* arr, int a, int b) {
    int temp = arr[a]; 
    arr[a] = arr[b];
    arr[b] = temp;
}

int main() {
    int ts;
    scanf("%d", &ts);

    int n;
    int train[100];

    while(ts--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%d", &train[i]);
        }

        int swp = 0;
        for(int i = 0; i < n-1; i++) {
            for(int j = i+1; j < n; j++) {
                if(train[i] > train[j]) {
                    swap(train, i, j);
                    swp++;
                }
            }
        }
        printf("Optimal train swapping takes %d swaps.\n", swp);
    }
}
