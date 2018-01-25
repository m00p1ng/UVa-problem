#include <cstdio>
#include <map>
#include <string>
using namespace std;

int main() {
    int ts;
    char s[1000];
    map<string, int> hw;
    scanf("%d", &ts);

    for(int t = 1; t <= ts; t++) {
        hw.clear();
        int n, q, score, day;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%s %d", s, &score);
            hw[s] = score;
        }
        scanf("%d %s", &day, s);
        
        int cur = hw[s];
        printf("Case %d: ", t);

        if(cur > day+5 || cur == 0)  puts("Do your own homework!");
        else if(cur <= day)  puts("Yesss");
        else puts("Late");
    }
}
