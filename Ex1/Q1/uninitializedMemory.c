#include <stdio.h>

void uninitializedMemory() {
    int *ptr;
    int value = *ptr;
}

int main() {
    uninitializedMemory();
    return 0;
}
