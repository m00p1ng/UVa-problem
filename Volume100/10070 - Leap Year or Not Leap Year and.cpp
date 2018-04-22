#include <cstdio>
#include <cstring>

bool check_leap(char *year, int len) {
    if(year[len-2] == '0' && year[len-1] == '0') {
        int num = ((year[len-4]-'0')*10)+(year[len-3]-'0');
        if(num % 4 == 0) return true;
    }
    else {
        int num = ((year[len-2]-'0')*10)+(year[len-1]-'0');
        if(num % 4 == 0) return true;
    }
    return false;
}

bool check_hulu(char *year, int len) {
    int sum = 0;
    for(int i = 0; i < len; i++) sum += (year[i]-'0'); 
    return sum % 3 == 0;
}

bool check_buku(char *year, int len) {
    int sum = 0;
    bool p = true;
    for(int i = len-1; i >= 0; i--) {
        if(p) sum += (year[i]-'0');
        else sum -= (year[i]-'0');
        p = !p;
    }
    return sum % 11 == 0;
}

int main() {
    char year[1005];
    int is_first = true;
    while(scanf("%s", year) == 1) {
        bool is_leap, is_hulu, is_buku;
        int len = strlen(year);
        is_hulu = is_buku = false;
        is_leap = check_leap(year, len);

        if(year[len-1] == '5' || year[len-1] == '0') {
            is_hulu = check_hulu(year, len);
            is_buku = check_buku(year, len);
        }

        if(!is_first) puts("");
        is_first = false;

        if(is_leap || is_hulu || (is_buku && is_leap)) {
            if(is_leap) puts("This is leap year.");
            if(is_hulu) puts("This is huluculu festival year.");
            if(is_leap && is_buku) puts("This is bulukulu festival year.");
        }
        else puts("This is an ordinary year."); 
    }
}

