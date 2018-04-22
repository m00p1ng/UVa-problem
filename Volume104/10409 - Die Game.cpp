#include <cstdio>

enum {TOP, NORTH, WEST, DOWN, SOUTH, EAST};

int start[] { 1, 2, 3, 6, 5, 4 };
int die[6];

void sim(int d) {
    int temp = die[TOP];
    switch(d) {
        case NORTH:
            die[TOP] = die[SOUTH];
            die[SOUTH] = die[DOWN];
            die[DOWN] = die[NORTH];
            die[NORTH] = temp;
            break;
        case SOUTH:
            die[TOP] = die[NORTH];
            die[NORTH] = die[DOWN];
            die[DOWN] = die[SOUTH];
            die[SOUTH] = temp;
            break;
        case WEST:
            die[TOP] = die[EAST];
            die[EAST] = die[DOWN];
            die[DOWN] = die[WEST];
            die[WEST] = temp;
            break;
        case EAST:
            die[TOP] = die[WEST];
            die[WEST] = die[DOWN];
            die[DOWN] = die[EAST];
            die[EAST] = temp;
            break;
    }
}

int main() {
    int m[128];
    m['n'] = NORTH;
    m['s'] = SOUTH;
    m['e'] = EAST;
    m['w'] = WEST;

    int n;
    char s[10];
    while(scanf("%d", &n), n) {
        for(int i = 0; i < 6; i++) die[i] = start[i];
        for(int i = 0; i < n; i++) {
            scanf("%s", s);          
            sim(m[s[0]]);
        }
        printf("%d\n", die[TOP]);
    }
}
