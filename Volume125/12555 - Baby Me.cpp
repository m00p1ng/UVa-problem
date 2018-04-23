#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	int ts, a;

	scanf("%d", &ts);
    for(int t = 1; t <= ts; t++) {
		cin >> a >> s;
        a = 50*a;
		if(s.length() > 3) {
            a += 5*(s[3]-'0'); 
        }
        printf("Case %d: %d", t, a/100);
        a = a % 100;
        if(a != 0) {
            if(a % 10 == 0) printf(".%d", a / 10);
            else printf(".%2d", a);
        }
        puts("");
	}
}
