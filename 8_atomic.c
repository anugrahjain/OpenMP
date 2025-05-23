/*
Supported Operations with omp atomic

1. Basic Arithmetic

    Addition: x += expr;
    Subtraction: x -= expr;
    Multiplication: x *= expr;
    Division: x /= expr;
    Remainder: x %= expr;

2. Bitwise Operations

    AND: x &= expr;
    OR: x |= expr;
    XOR: x ^= expr;
    Left shift: x <<= expr;
    Right shift: x >>= expr;

3. Increment/Decrement

    Pre-increment: ++x;
    Pre-decrement: --x;
    Post-increment: x++;
    Post-decrement: x--;

4. Comparison and Assignment

    Assignment of results based on a comparison:
        x = (x < expr) ? expr : x; (atomic minimum)
        x = (x > expr) ? expr : x; (atomic maximum)
*/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define SIZE 1000000  // Size of the array
#define THREADS 8     // Number of threads

void perform_operation_with_critical(int *arr, int size) {
    int sum = 0;
    double start_time = omp_get_wtime();

    #pragma omp parallel for num_threads(THREADS)
    for (int i = 0; i < size; i++) {
        #pragma omp critical
        sum += arr[i]; // Critical section for addition
    }

    double end_time = omp_get_wtime();
    printf("Critical - Sum: %d, Time: %.6f seconds\n", sum, end_time - start_time);
}

void perform_operation_with_atomic(int *arr, int size) {
    int sum = 0;
    double start_time = omp_get_wtime();

    #pragma omp parallel for num_threads(THREADS)
    for (int i = 0; i < size; i++) {
        #pragma omp atomic
        sum += arr[i]; // Atomic addition
    }

    double end_time = omp_get_wtime();
    printf("Atomic - Sum: %d, Time: %.6f seconds\n", sum, end_time - start_time);
}

int main() {
    // Allocate and initialize the array
    int *arr = (int *)malloc(SIZE * sizeof(int));
    for (int i = 0; i < SIZE; i++) {
        arr[i] = 1; // Initialize all elements to 1
    }

    printf("Array size: %d, Threads: %d\n", SIZE, THREADS);

    // Perform operation using omp critical
    perform_operation_with_critical(arr, SIZE);

    // Perform operation using omp atomic
    perform_operation_with_atomic(arr, SIZE);

    // Free the allocated memory
    free(arr);

    return 0;
}

