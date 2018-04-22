#include <cstdio>
#include <cmath>

void print_eq1(double h, double k, double r) {
        if(h > 0) printf("(x - %.3lf)^2", h);
        else if(h < 0) printf("(x + %.3lf)^2", -h);
        else printf("x^2");

        printf(" + ");

        if(k > 0) printf("(y - %.3lf)^2", k);
        else if(k < 0) printf("(y + %.3lf)^2", -k);
        else printf("y^2");

        printf(" = %.3lf^2\n", r);
}

void print_eq2(double h, double k, double rsq) {
        double res = -rsq + h*h + k*k;

        printf("x^2 + y^2 ");
        if(h > 0) printf("- %.3lfx ", 2*h);
        else if(h < 0) printf("+ %.3lfx ", -2*h);

        if(k > 0) printf("- %.3lfy ", 2*k);
        else if(k < 0) printf("+ %.3lfy ", -2*k);

        if(res > 0) printf("+ %.3lf ", res);
        else if(res < 0) printf("- %.3lf ", -res);

        puts("= 0");
}

int main() {
    double x1, x2, x3, y1, y2, y3;
    while(scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3) == 6) {
        double a, b, c, d, e, f;
        a = x1 - x2; b = y1 - y2;
        c = x2 - x3; d = y2 - y3;
        e = x1*x1 - x2*x2 + y1*y1 - y2*y2;
        f = x2*x2 - x3*x3 + y2*y2 - y3*y3;

        double cx, cy, det;
        det = 4*(a*d - b*c);
        cx = 2*(e*d - b*f)/det;
        cy = 2*(a*f - c*e)/det;

        double rsq, dx, dy;
        dx = x1-cx;
        dy = y1-cy;
        rsq = dx*dx + dy*dy;
        
        print_eq1(cx, cy, sqrt(rsq));
        print_eq2(cx, cy, rsq);

        puts("");
    }
}
