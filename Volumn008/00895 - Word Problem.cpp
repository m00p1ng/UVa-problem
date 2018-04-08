#include <cstdio>
#include <cstring>

int main() {
    char s[100];
    int freq[26][1000] = {0};
    int idx = 0;

    while(scanf("%s\n", s) , s[0] != '#') {
        for(int i = 0; i < strlen(s); i++) {
            freq[s[i]-'a'][idx]++;
        }
        idx++;
    }

    while(fgets(s, 100, stdin), strcmp(s, "#\n")) {
        s[strlen(s)-1] = '\0';
        int temp[26] = {0};

        char *p = strtok(s, " ");
        while(p) {
            temp[p[0]-'a']++;
            p = strtok(NULL, " ");
        }

        int count = 0;
        for(int i = 0; i < idx; i++) {
            int chk = 0;
            for(int j = 0; j < 26; j++) {
                if(temp[j] >= freq[j][i]) chk++;
            }
            if(chk == 26) count++;
        }
        printf("%d\n", count);
    }
}

