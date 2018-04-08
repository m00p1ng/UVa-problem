#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int ts;
    scanf("%d", &ts);
    while(ts--) {
        int sq[4];
        scanf("%d %d %d %d", &sq[0], &sq[1], &sq[2], &sq[3]);
        sort(sq, sq+4);

        if(sq[0] == sq[1] && sq[1] == sq[2] && sq[2] == sq[3]) puts("square");
        else if(sq[0] == sq[1] && sq[2] == sq[3]) puts("rectangle");
        else if(sq[3] >= sq[0] + sq[1] + sq[2]) puts("banana");
        else puts("quadrangle");
    }
}
