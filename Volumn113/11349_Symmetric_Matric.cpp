#include <cstdio>

long long matrix[100][100];
int n;

bool is_symmetric() {
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            if(matrix[i][j] != matrix[n-i-1][n-j-1]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int testcase;
    scanf("%d", &testcase);
    for(int cs = 1; cs <= testcase; cs++) {
        scanf("\nN = %d", &n);

        bool is_neg = false;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                scanf("%lld", &matrix[i][j]);
                if(matrix[i][j] < 0) is_neg = true;
            }
        }

        printf("Test #%d: ", cs);
        if(!is_neg && is_symmetric()) puts("Symmetric.");
        else puts("Non-symmetric.");
    }
}

