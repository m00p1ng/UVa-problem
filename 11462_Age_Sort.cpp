#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int n;
    int arr[2000010];

    while(scanf("%d", &n), n) {
        for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
        sort(arr, arr+n);
        for(int i = 0; i < n; i++) {
            if(i) putchar(' ');
            printf("%d", arr[i]);
        }
        puts("");
    }
}
