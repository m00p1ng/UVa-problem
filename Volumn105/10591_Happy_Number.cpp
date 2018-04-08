#include <cstdio>
#include <cstring>

int sq[] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81};

bool happy(char *number) {
    int len = strlen(number);
    int sum = 0;
    char temp[100];
    
    for(int i = 0; i < len; i++) {
        sum += sq[number[i]-'0']; 
    }

    while(len != 1) {
        sprintf(temp, "%d", sum);
        len = strlen(temp);
        sum = 0;

        for(int i = 0; i < len; i++) {
            sum += sq[temp[i]-'0'];    
        }
    }

    return sum == 1;
}

int main() {
    int ts;
    scanf("%d", &ts);
    for(int t = 1; t <= ts; t++) {
        char number[100];
        scanf("%s", number);

        printf("Case #%d: %s is ", t, number);
        if(happy(number)) puts("a Happy number.");
        else puts("an Unhappy number.");
    }
}

