#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    char s[100];
    while(scanf("%s", s), s[0] != '#') {
        if(next_permutation(s, s+strlen(s))) puts(s); 
        else puts("No Successor");
    }
}
