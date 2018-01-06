#include <cstdio>
#include <algorithm>

int main() {
    int ts;
    scanf("%d", &ts);
    
    int data[1000];
    while(ts--) {
        int n;
        int sum = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%d", &data[i]);
            sum += data[i];
        }
        double avg = (double)sum / (double)n;
        std::sort(data, data+n);

        int idx = 0;
        for(int i = 0; i < n; i++) {
            if(avg < data[i]) {
                idx = n - i;
                break;
            }
        }
        printf("%.3lf%%\n", (double)idx/(double)n*100);
    }
}
