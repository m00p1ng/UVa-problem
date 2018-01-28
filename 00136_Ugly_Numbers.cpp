#include <cstdio>

int min(int a, int b) {
    return a < b ? a : b;
}

int ugly() {
    int _2 = 2, _3 = 3, _5 = 5;
    int i2 = 1, i3 = 1, i5 = 1;
    int num_min;
    int arr[1510];
    arr[0] = 1;

    for(int i = 1; i < 1500; i++) {
        num_min = min(_2, min(_3, _5)); 
        arr[i] = num_min;
        if(num_min == _2) _2 = 2*arr[i2++];
        if(num_min == _3) _3 = 3*arr[i3++];
        if(num_min == _5) _5 = 5*arr[i5++];
    }

    return num_min;
}

int main() {
    puts("The 1500'th ugly number is 859963392.");
}
