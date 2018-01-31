#include <cstdio>
#include <map>
#include <cstring>
#include <string>
using namespace std;

int main() {
    int m, n;
    long long cost;
    char s[1000];
    scanf("%d %d", &m, &n);
    map<string, long long> price;

    for(int i = 0; i < m; i++) {
        scanf("%s %lld", s, &cost);
        price[s] = cost;
    }

    for(int i = 0; i < n; i++) {
        cost = 0;
        while(scanf("%s", s), strcmp(s, ".")) {
            cost += price[s];
        }
        printf("%lld\n", cost);
    }
}
