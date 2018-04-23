#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;

int main() {
    int ts;
    scanf("%d\n", &ts);

    bool mul_flag;
    char buff[100], sign;
    long long min_sum, max_sum, num, mul;
    stack<int> s;
    while(ts--) {
        scanf("%lld", &num);
        fgets(buff, 1000, stdin);
        int len = strlen(buff)-1;
        buff[len] = '+';

        sign = buff[0];
        mul_flag = false;
        min_sum = sign == '+' ? num : 0;
        mul = sign == '+' ? 1 : num;

        s.push(num);
        num = 0;

        for(int i = 1; i <= len; i++) {
            if(buff[i] >= '0' && buff[i] <= '9') {
                num = num*10 + buff[i] - '0';
            } else {
                if(sign == '+') {
                    if(mul_flag) {
                        min_sum += mul;
                        mul = 1;
                        mul_flag = false;
                    }
                    if(buff[i] == '+') min_sum += num;
                    else mul = num;
                    int a = s.top(); s.pop();
                    s.push(a+num);
                } else {
                    mul *= num;
                    mul_flag = true;
                    s.push(num);
                }

                sign = buff[i];
                num = 0;
            }
        }

        max_sum = 1;
        while(!s.empty()) {
            max_sum *= s.top();
            s.pop();
        }
        if(mul_flag) min_sum += mul;
        printf("The maximum and minimum are %lld and %lld.\n", max_sum, min_sum);
    }
}

