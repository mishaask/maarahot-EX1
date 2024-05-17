#include <stdio.h>

void divisionByZero() {
    int x = 1;
    int y = 0;
    int z = x / y;
}

int main() {
    divisionByZero();
    return 0;
}
