#include <cstdio>

int main() {
    int a, b;

    while(scanf("%d %d", &a, &b), a || b) {
        bool prev_carry = false;
        int carry = 0; 

        int sum;
        while(a >= 1 && b >= 1) {
            sum = (a % 10) + (b % 10) + prev_carry;

            if(sum / 10 == 1) {
                prev_carry = true;
                carry++;
            }
            else {
                prev_carry = false;
            }

            a /= 10;
            b /= 10;
        }
        int remain = (a != 0) ? a : b;

        while(remain >= 1 && prev_carry) {
            sum = (remain % 10) + 1;
            if(sum / 10 == 1)carry++; 
            else prev_carry = false; 

            remain /= 10;
        }
        
        if(carry == 0) {
            puts("No carry operation.");
        } else if(carry == 1) {
            puts("1 carry operation.");
        } else {
            printf("%d carry operations.\n", carry);
        }
    }
}
