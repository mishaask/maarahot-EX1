#include <stdio.h>
#include <stdlib.h>

long double poisson(int k, double lambda);

int main() {
    double values[5][2] = {{1, 2}, {10, 2}, {2, 2}, {3, 3}, {3, 100}};

    for (int i = 0; i < 5; i++) {
        printf("%.50Lf\n", poisson((int)values[i][0], values[i][1]));
    }

    return 0;
}