#include <cstdio>
#include <map>
#include <string>
#define EPS 1e-8
using namespace std;

bool is_sign(char* s) {
    return s[0] == '>' || s[0] == '<' || s[0] == '=';
}

int main() {
    int n, m;
    int a, b, num, sum;
    char temp[30];
    map<string, double> dict;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++) {
        scanf("%s %d.%d", temp, &a, &b);
        dict[temp] = a*10+b;
    }
    for(int i = 1; i <= m; i++) {
        sum = 0;
        bool is_correct;
        temp[0] = ' ';
        while(!is_sign(temp)) {
            scanf("%s", temp); 
            sum += dict[temp];
            scanf("%s", temp);
        }

        scanf("%d", &num);
        num *= 10;
        if(temp[0] == '>') {
            is_correct = (sum > num);
            if(temp[1] == '=') {
                is_correct |= (sum == num);
            }
        } else if(temp[0] == '<') {
            is_correct = (sum < num);
            if(temp[1] == '=') {
                is_correct |= (sum == num);
            }
        } else if(temp[0] == '=') {
            is_correct = (sum == num);
        }


        printf("Guess #%d was ", i);
        if(!is_correct) printf("in");
        puts("correct."); 
    }
}
