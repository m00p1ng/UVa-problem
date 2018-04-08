#include <cstdio>

int matrix[10][10];
int n;

void swap(int* a, int* b) {
    int *temp;
    *temp = *a;
    *a = *b;
    *b = *temp;
}

void transpose() {
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            swap(&matrix[i][j], &matrix[j][i]);
        }
    }
}

void incm(int k) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            matrix[i][j] += k;
        }
    }
}

void row(int a, int b) {
    for(int i = 0; i < n; i++) {
        swap(&matrix[a][i], &matrix[b][i]);
    }
}

void col(int a, int b) {
    for(int i = 0; i < n; i++) {
        swap(&matrix[i][a], &matrix[i][b]);
    }
}

int main() {
    int ts;
    char c, cmd[20];
    int n_cmd, a, b;
    scanf("%d", &ts);

    for(int t = 1; t <= ts; t++) {
        scanf("%d\n", &n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                scanf("%c", &c);
                matrix[i][j] = c - '0';
            }
            scanf("%*c");
        }

        scanf("%d", &n_cmd);
        while(n_cmd--) {
            scanf("%s", cmd); 
            if(cmd[0] == 'r' || cmd[0] == 'c') scanf("%d %d", &a, &b);
            switch(cmd[0]) {
                case 't': transpose(); break;
                case 'i': incm(1); break;
                case 'd': incm(-1); break;
                case 'r': row(a-1, b-1); break;
                case 'c': col(a-1, b-1); break;
            }
        }

        printf("Case #%d\n", t);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                printf("%d", (1000+matrix[i][j]) % 10);
            }
            puts("");
        }
        puts("");
    }
}

