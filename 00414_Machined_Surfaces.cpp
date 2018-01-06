#include <cstdio>

int main() {
    int line;
    while(scanf("%d\n", &line), line != 0) {
        int blank = 0;
        int min_blank = 100;
        char temp[30];
        for(int r = 0; r < line; r++) {
            fgets(temp, 30, stdin);

            int cur_blank = 0;
            for(int i = 0; i < 25; i++) {
                if(temp[i] == ' ') {
                    cur_blank++;
                }
            }
            
            blank += cur_blank;

            if(cur_blank < min_blank) {
                min_blank = cur_blank;
            }

        }
        printf("%d\n", blank-(min_blank*line));
    }
}
