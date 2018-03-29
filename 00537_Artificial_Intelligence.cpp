#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdlib>

double var[3];
bool vis[3];
char buff[1000];
int mymap[128];
enum { P, U, I};

double unit_parse(char s) {
    if(s == 'm') return 0.001;
    if(s == 'k') return 1000;
    if(s == 'M') return 1000000;
    return 1;
}

bool data_field(int idx) {
    if(buff[idx] != 'P' && buff[idx] != 'U' && buff[idx] != 'I') return false;
    if(buff[idx+1] != '=') return false;
    
    int run = 2;
    char number[100] = {0};
    int ii = 0;

    while(isdigit(buff[idx+run]) || buff[idx+run] == '.' || buff[idx+run] == '-') {
        number[ii++] = buff[idx+run]; 
        run++;
    }
    
    double unit = 1;
    if(buff[idx+run] == 'm' || buff[idx+run] == 'k' || buff[idx+run] == 'M') {
        unit = unit_parse(buff[idx+run]);
        run++;
    }

    int iii = mymap[buff[idx]];
    double data;
    sscanf(number, "%lf", &data);

    var[iii] = data*unit;
    vis[iii] = true;

    return true;
}


int main() {
    int ts;
    mymap['P'] = 0;
    mymap['U'] = 1;
    mymap['I'] = 2;
    scanf("%d\n", &ts);

    for(int t = 1; t <= ts; t++) {
        var[0] = var[1] = var[2] = 0;
        vis[0] = vis[1] = vis[2] = false;
        fgets(buff, 1000, stdin); 

        int cnt = 0;
        for(int i = 0; i < strlen(buff) && cnt != 2; i++) {
            cnt += data_field(i); 
        }

        printf("Problem #%d\n", t);
        if(!vis[P]) printf("P=%.2lfW", var[I]*var[U]);
        else if(!vis[I]) printf("I=%.2lfA", var[P]/var[U]);
        else if(!vis[U]) printf("U=%.2lfV", var[P]/var[I]);
        puts("\n");
    }
}
