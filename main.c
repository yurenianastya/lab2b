#include <stdio.h>
#include <math.h>

double func(double m, int n, double x) {
    double result = pow(-1, n) * pow(x, n);
    for (int i = 0; i < n; i++) {
        result *= (m + i);
    }
    return result;
}

double factorial(int n) {
    double result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    double step = 0.05;
    double fluff = 0.001;
    double x, MIN, MAX;
    int m = 9;
    x = 0;
    /*fluff = 0.001;
    m = 9*/

    printf("Type MIN\n"); /*0.5*/
    scanf("%lf", &MIN); /*0*/
    printf("Type MAX\n");
    scanf("%lf", &MAX);
    double sum = 0;
    while(x<MAX) {
        double current = 0;
        double prev = 0;
        int n = 0;
        do {
            n++;
            sum += func(m, n, x) / factorial(n);
            prev = current;
            current = sum;
        } while (fabs(current) - fabs(prev) > fluff);
        x += step;
        printf("%lf", x);
        printf("%lf\n", 1 + current);
    }

    return 0;
}
