#include <cstdio>
#include <cstring>

int main() {
    int card;
    while(scanf("%d", &card), card != 0) {
        char cardName[3];
        char cardList[52][3];
        bool cardFill[52] = { false };
        int point = -1;
        char tempword[21];

        for(int i = 0; i < card; i++) {
            scanf("%s %s", cardName, tempword);
            int wordlength = strlen(tempword);

            while(wordlength--) {
                point = (point+1)%card;
                if(cardFill[point]) {
                    while(true) {
                        point = (point+1)%card;
                        if(!cardFill[point]) break;
                    }
                }
            }
            cardFill[point] = true;
            strcpy(cardList[point], cardName);
        }
        for(int i = 0; i < card; i++) {
            printf("%s%s", cardList[i], i == card-1 ? "\n" : " ");
        }
    }
}

