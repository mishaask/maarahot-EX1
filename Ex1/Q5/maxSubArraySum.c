#include "maxSubArraySum.h"

int maxSubArraySumN(int arr[], int n) {
    int max_so_far = arr[0];
    int curr_max = arr[0];

    for (int i = 1; i < n; i++) {
        curr_max = (arr[i] > curr_max + arr[i]) ? arr[i] : curr_max + arr[i];
        max_so_far = (max_so_far > curr_max) ? max_so_far : curr_max;
    }
    return max_so_far;
}

int maxSubArraySumN2(int arr[], int n) {
    int max_sum = arr[0];
    for (int i = 0; i < n; i++) {
        int current_sum = 0;
        for (int j = i; j < n; j++) {
            current_sum += arr[j];
            if (current_sum > max_sum) {
                max_sum = current_sum;
            }
        }
    }
    return max_sum;
}

int maxSubArraySumN3(int arr[], int n) {
    int max_sum = arr[0];
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int current_sum = 0;
            for (int k = i; k <= j; k++) {
                current_sum += arr[k];
            }
            if (current_sum > max_sum) {
                max_sum = current_sum;
            }
        }
    }
    return max_sum;
}

void generateRandomArray(int arr[], int size, int seed) {
    srand(seed);
    for (int i = 0; i < size; i++) {
        arr[i] = (rand() % 100) - 25;  // Random numbers between -25 and 74
    }
}