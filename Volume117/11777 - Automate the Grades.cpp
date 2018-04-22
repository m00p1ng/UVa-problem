#include <cstdio>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort_score(int *score) {
    if(score[5] > score[4]) swap(&score[5], &score[4]);
    if(score[6] > score[4]) swap(&score[6], &score[4]);
    if(score[6] > score[5]) swap(&score[6], &score[5]);
}

char grade(int total) {
    if(total >= 90) return 'A';
    if(total >= 80) return 'B';
    if(total >= 70) return 'C';
    if(total >= 60) return 'D';
    return 'F';
}

int main() {
    int ts, total;
    int score[10];

    scanf("%d", &ts);
    for(int t = 1; t <= ts; t++) {
        for(int i = 0; i < 7; i++) scanf("%d", &score[i]);
        sort_score(score);
        total = score[0] + score[1] + score[2] + score[3];
        total += (score[4] + score[5])/2.0;
        printf("Case %d: %c\n", t, grade(total));
    }
}
