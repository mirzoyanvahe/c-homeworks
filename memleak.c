#include <stdlib.h>

int main() {
    int *ptr = (int *)malloc(sizeof(int));
    free(ptr);  // Fix: Freeing the allocated memory

    return 0;
}
