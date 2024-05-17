#include <stdio.h>

void stackOverflow() {
    stackOverflow();
}

int main() {
    stackOverflow();
    return 0;
}
