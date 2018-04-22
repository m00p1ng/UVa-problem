#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;

int main() {
    int ts;
    scanf("%d%*c", &ts);
    char paren[20000];

    while(ts--) {
        stack<char> s;
        bool is_valid = true;
        fgets(paren, 10000, stdin);
        paren[strlen(paren)-1] = '\0';

        if(strlen(paren) % 2 == 0) {
            for(int i = 0; i < strlen(paren); i++) {
                if(paren[i] == '(' || paren[i] == '[') {
                    s.push(paren[i]);
                } else if(paren[i] == ')' && !s.empty() && s.top() == '(') {
                    s.pop();
                } else if(paren[i] == ']' && !s.empty() && s.top() == '[') {
                    s.pop();
                } else {
                    is_valid = false;
                    break;
                }
            }
        } else is_valid = false; 

        if(s.empty() && is_valid) puts("Yes");
        else puts("No"); 
    }
}
