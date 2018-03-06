#include <cstdio>
#include <cstring>
#define INF 1000000000

int main() {
    int n, p;
    int ts = 0, req;
    char out[1000];
    char buff[1000];
    double pr, reqm, price;

    while(scanf("%d %d\n", &n, &p), n || p) {
        price = INF;
        req = -1;
        for(int i = 0; i < n; i++) {
            fgets(buff, 1000, stdin);
        }
        for(int i = 0; i < p; i++) {
            fgets(buff, 1000, stdin);
            scanf("%lf %lf\n", &pr, &reqm);

            buff[strlen(buff)-1] = '\0';

            if(reqm > req) {
                req = reqm;
                price = pr;
                strcpy(out, buff);
            } else if(req == reqm && pr < price) {
                req = reqm;
                price = pr;
                strcpy(out, buff);
            }

            while(reqm--) fgets(buff, 1000, stdin);
        }

        if(ts) puts("");

        printf("RFP #%d\n", ++ts);
        puts(out);
    }
}

