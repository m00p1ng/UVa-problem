#include <cstdio>
#include <cstring>

int main() {
    int n, ts = 0;
    bool schedule[500];
    char temp[1000];
    while(scanf("%d\n", &n) == 1) {
        memset(schedule, false, sizeof(schedule));

        int sh, sm, eh, em, st, et;
        for(int i = 0; i < n; i++) {
            scanf("%d:%d %d:%d", &sh, &sm, &eh, &em);
            fgets(temp, 1000, stdin);
            st = (sh-10)*60 + sm;
            et = (eh-10)*60 + em;

            for(int j = st; j < et; j++) {
                schedule[j] = true;
            }
        }

        int ms = 0, ml = 0, temp;
        int start = 0, i = 0;
        
        while(i < 480) {
            while(schedule[i] && i < 480) i++;
            start = i;
            temp = 0;
            while(!schedule[i] && i < 480) {
                temp++;  
                i++;
            }
            if(temp > ml) {
                ml = temp;
                ms = start;
            }
        }
        printf("Day #%d: the longest nap starts at %d:%02d and will last for ", ++ts, 10 + ms/60, ms%60);
        
        int longh = ml / 60;
        if(longh) printf("%d hours and ", longh);
        printf("%d minutes.\n", ml % 60);
    }
}
