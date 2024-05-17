#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "maxSubArraySum.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <random seed> <input size>\n", argv[0]);
        return 1;
    }

    int seed = atoi(argv[1]);
    int size = atoi(argv[2]);

    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        perror("Unable to allocate memory");
        return 1;
    }

    generateRandomArray(arr, size, seed);

    clock_t start, end;

    // Timing O(n) algorithm
    start = clock();
    int max_sum_n = maxSubArraySumN(arr, size);
    end = clock();
    printf("O(n) Max Subarray Sum: %d, Time: %lf seconds\n", max_sum_n, ((double)(end - start)) / CLOCKS_PER_SEC);

    // Timing O(n^2) algorithm
    start = clock();
    int max_sum_n2 = maxSubArraySumN2(arr, size);
    end = clock();
    printf("O(n^2) Max Subarray Sum: %d, Time: %lf seconds\n", max_sum_n2, ((double)(end - start)) / CLOCKS_PER_SEC);

    // Timing O(n^3) algorithm
    start = clock();
    int max_sum_n3 = maxSubArraySumN3(arr, size);
    end = clock();
    printf("O(n^3) Max Subarray Sum: %d, Time: %lf seconds\n", max_sum_n3, ((double)(end - start)) / CLOCKS_PER_SEC);

    free(arr);
    return 0;
}