#include <cstdio>

bool self_number[1000001] = {false};

void gen_self(int n) {
    if(n > 1000000) return;
    int next_self = n;
    while(n > 0) {
        next_self += n % 10;
        n /= 10;
    }
    if(self_number[next_self]) return;
    self_number[next_self] = true;
    gen_self(next_self);
}

int main() {
    for(int i = 1; i <= 1000000; i++) {
        if(!self_number[i]) {
            gen_self(i);
            printf("%d\n", i);
        }
    }
}
