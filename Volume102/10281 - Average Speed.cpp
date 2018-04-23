#include <cstdio>

int main() {
    int a, b, c, temp;
    double prev_dist = 0, cur_dist, dist, st, ed;
    char buff[100];

    while(fgets(buff, 100, stdin) && buff[0] != '\n') {
        int p = sscanf(buff, "%d:%d:%d %d", &a, &b, &c, &temp);

        ed = a + b/60.0 + c/3600.0;
        if(p == 4) {
            prev_dist += (ed - st)*dist; 
            dist = temp;
            st = ed;
        } else {
            cur_dist = prev_dist + (ed - st)*dist; 
            printf("%02d:%02d:%02d %.2lf km\n", a, b, c, cur_dist);
        }
    }
}
