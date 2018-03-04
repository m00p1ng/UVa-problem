#include <cstdio>

int main() {
    int ts;
    scanf("%d", &ts);
    for(int t = 1; t <= ts; t++) {
        int ad, am, ay, bd, bm, by;
        scanf("%d/%d/%d", &ad, &am, &ay);
        scanf("%d/%d/%d", &bd, &bm, &by);
        
        int age = ay - by;
        if(am < bm || (am == bm && ad < bd)) age--; 

        printf("Case #%d: ", t);
        if(age < 0) puts("Invalid birth date");
        else if(age > 130) puts("Check birth date"); 
        else printf("%d\n", age);
    }
}

