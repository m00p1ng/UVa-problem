#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int ts;
    int num[100];
    long long price;
    bool is_exp;
    scanf("%d", &ts);
    while(ts--) {
        int n = 0;
        while(scanf("%d", &num[n]), num[n]) n++;

        sort(num, num+n);
        price = 0;
        is_exp = false;
        for(int i = n-1; i >= 0; i--) {
            price += 2*pow(num[n-1-i], i+1);
            if(price > 5000000) {
                is_exp = true;
                break;
            }
        }
        if(!is_exp) printf("%lld\n", price);
        else puts("Too expensive");
    }
}
