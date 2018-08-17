
// Function that compares
int compareFunc(const void * voidA, const void * voidB);

// Function that finds the median of an array
// Useful for Exercise 3-2
double arrayMedian(int intArray[], int ARRAY_SIZE);

// Function that checks whether an array is sorted. Can be used like quick sort. 
// Exercise 3-3 of Thinking Like a Programmer
bool isSorted(void * arr, size_t n, size_t s, int (*func) (const void *, const void *));
