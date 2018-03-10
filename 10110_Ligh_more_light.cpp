#include <cstdio>
#include <cmath>

int main() {
    long a;
    while(scanf("%ld", &a), a) {
        if((long)sqrt(a) == sqrt(a)) puts("yes"); 
        else puts("no");
    }
}

