#include <cstdio>
#include <cstring>

char matrix[101][101];
char sub[101][101];
int m, s;

void rotate_clockwise() {
    char temp[101][101];
    for(int i = 0; i < s; i++) {
        for(int j = 0; j < s; j++) {
            temp[i][j] = sub[s-j-1][i];
        }
    }
    for(int i = 0; i < s; i++) temp[i][s] = '\0';
    for(int i = 0; i < s; i++) strcpy(sub[i], temp[i]);
}

int count_sub() {
    int diff = m-s;
    int ret_count = 0;
    for(int mi = 0; mi <= diff; mi++) {
        for(int mj = 0; mj <= diff; mj++) {
            int temp_count = 0;
            for(int si = 0; si < s; si++) {
                for(int sj = 0; sj < s; sj++) {
                    if(sub[si][sj] == matrix[mi+si][mj+sj]) temp_count++;
                }
            }
            if(temp_count == s*s) ret_count++;
        }
    }
    return ret_count;
}

int main() {
    while(scanf("%d %d", &m, &s),  m && s) {
        scanf("%*c");
        for(int i = 0; i < m; i++) scanf("%s", matrix[i]);
        for(int i = 0; i < s; i++) scanf("%s", sub[i]);

        printf("%d ", count_sub());
        rotate_clockwise();
        printf("%d ", count_sub());
        rotate_clockwise();
        printf("%d ", count_sub());
        rotate_clockwise();
        printf("%d\n", count_sub());
    }
}

