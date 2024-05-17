#include <math.h>
#include <stdio.h>

int factorial(int n) {
    return (n == 1 || n == 0) ? 1.0 : factorial(n - 1) * n;
    }


long double poisson(int k, double lambda) {
    long double res = (pow(lambda, k) / (expf(lambda) * factorial(k)));
    return res;
}