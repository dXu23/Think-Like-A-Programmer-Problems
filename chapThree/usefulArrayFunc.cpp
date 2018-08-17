#include <iostream>
using namespace::std;

int compareFunc(const void * voidA, const void * voidB) {
    int * intA = (int *) (voidA);
    int * intB = (int *) (voidB);
    return *intA - *intB;
}

double arrayMedian(int intArray[], int ARRAY_SIZE) {
    int sortedCopy[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        sortedCopy[i] = intArray[i];
    }
    qsort(sortedCopy, ARRAY_SIZE, sizeof(int), compareFunc);
    if (ARRAY_SIZE % 2 == 0) {
        return (sortedCopy[ARRAY_SIZE / 2] + sortedCopy[ARRAY_SIZE / 2 - 1]) / 2;
    } else {
        return sortedCopy[ARRAY_SIZE / 2];
    }
}


// Exercise 3-3 of Thinking Like a Programmer
bool isSorted(void * arr, size_t n, size_t s, int (*func) (const void *, const void *)) {
    bool sorted = true;
    int size = (int) n;
    for (int i = 0; i < size - 1; i++) {
        sorted = sorted && (func(((char *) arr + s * i), (void *) ((char *) arr + s * (i + 1))) <= 0 );
    }
    return sorted;
}
