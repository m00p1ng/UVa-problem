#include <cstdio>

int main() {
    int n;
    int num[1000];
    while(scanf("%d", &n) == 1) {
        for(int i = 0; i < n; i++) scanf("%d", &num[i]);

        int f = 0;
        for(int i = 0; i < n-1; i++) {
            for(int j = i+1; j < n; j++) {
                if(num[i] > num[j]) f++; 
            }
        }
        printf("Minimum exchange operations : %d\n", f);
    }
}
