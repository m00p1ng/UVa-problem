#include <cstdio>
#include <map>
#include <string>
#include <cstring>
#include <cctype>
using namespace std;

char num[] = "2223334445556667 77888999 ";

int main() {
    int ts;
    char out[9], input[1000];
    int idx, count, len;
    map<string, int> dict;
    scanf("%d", &ts);

    while(ts--) {
        int n;
        dict.clear();
        scanf("%d", &n);
        while(n--) {
            idx = 0;

            scanf("%s", input);
            len = strlen(input);
            for(int i = 0; i < len; i++) {
                if(idx == 3) out[idx++] = '-';
                if(isdigit(input[i])) out[idx++] = input[i]; 
                else if(isalpha(input[i])) out[idx++] = num[input[i]-'A']; 
            }
            out[8] = '\0';
            dict[out]++;
        }

        count = 0;
        for(auto it = dict.begin(); it != dict.end(); ++it) {
            if(it->second > 1) {
                count++;
                printf("%s %d\n", it->first.c_str(), it->second);
            }
        }
        if(count == 0) puts("No duplicates.");
        if(ts) puts("");
    }
}

