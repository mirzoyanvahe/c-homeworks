#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

// Function to add two arrays and store the result in a third array
void addArrays(int *a, int *b, int *result, int size) {
    for (int i = 0; i < size; i++) {
        result[i] = a[i] + b[i];
    }
}

// Function to add two arrays with vectorization using OpenMP SIMD pragma
void addArraysVectorized(int * __restrict__ a, int * __restrict__ b, int * __restrict__ result, int size) {
    #pragma omp simd
    for (int i = 0; i < size; i++) {
        result[i] = a[i] + b[i];
    }
}

int main() {
    int *array1, *array2, *result;
    int i;

    // Allocate memory for the arrays
    array1 = (int *)malloc(ARRAY_SIZE * sizeof(int));
    array2 = (int *)malloc(ARRAY_SIZE * sizeof(int));
    result = (int *)malloc(ARRAY_SIZE * sizeof(int));

    // Initialize arrays with random values
    srand(time(NULL));
    for (i = 0; i < ARRAY_SIZE; i++) {
        array1[i] = rand() % 100;
        array2[i] = rand() % 100;
    }

    // Measure time before the calculation
    clock_t start_time = clock();

    // Add arrays without vectorization
    addArrays(array1, array2, result, ARRAY_SIZE);

    // Measure time after the calculation
    clock_t end_time = clock();

    // Calculate the duration in milliseconds
    double duration = ((double)(end_time - start_time)) / CLOCKS_PER_SEC * 1000;

    // Print the duration
    printf("Time taken to add arrays without vectorization: %f milliseconds\n", duration);

    // Measure time before the vectorized calculation
    start_time = clock();

    // Add arrays with vectorization
    addArraysVectorized(array1, array2, result, ARRAY_SIZE);

    // Measure time after the vectorized calculation
    end_time = clock();

    // Calculate the duration in milliseconds
    duration = ((double)(end_time - start_time)) / CLOCKS_PER_SEC * 1000;

    // Print the duration
    printf("Time taken to add arrays with vectorization: %f milliseconds\n", duration);

    // Free allocated memory
    free(array1);
    free(array2);
    free(result);

    return 0;
}
