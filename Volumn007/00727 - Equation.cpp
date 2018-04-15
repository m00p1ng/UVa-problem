#include <cstdio>
#include <stack>

int prec(char c) {
    if(c == '*' || c == '/') return 2;
    if(c == '+' || c == '-') return 1;
    return 0;
}

int main() {
    int ts;
    scanf("%d\n\n", &ts);

    while(ts--) {
        char buff[10], c;
        std::stack<char> s;

        while(fgets(buff, 10, stdin) && buff[0] != '\n') {
            c = buff[0];

            if(c >= '0' && c <= '9') {
                printf("%c", c);
            } else if(c == '(') {
                s.push('(');
            } else if(c == ')') {
                while(s.top() != '(') {
                    printf("%c", s.top());
                    s.pop();
                }
                s.pop();
            } else {
                while(!s.empty() && prec(c) <= prec(s.top())) {
                    printf("%c", s.top());
                    s.pop();
                }
                s.push(c);
            }
        }
        while(!s.empty()) {
            printf("%c", s.top());
            s.pop();
        }
        puts("");
        if(ts) puts("");
    }
}
