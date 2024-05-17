#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int factorial(int n) {return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Error\n");
        return 1;
    }

    double lambda = atof(argv[1]);
    int k = atoi(argv[2]);

    long double px = exp(-lambda) * pow(lambda, k) / factorial(k);

    printf("%.15Lf\n", px);

    return 0;
}


//./poisson 2.5 3
