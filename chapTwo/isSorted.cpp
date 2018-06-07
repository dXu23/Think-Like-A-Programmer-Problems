#include <iostream>
using namespace::std;

#define ARR_SIZE 20
bool isSorted(void * arr, size_t n, size_t s, int (*func) (const void *, const void *)) {
    bool sorted = true;
    int size = (int) n;
    for (int i = 0; i < size - 1; i++) {
        sorted = sorted && (func(((char *) arr + s * i), (void *) ((char *) arr + s * (i + 1))) <= 0 );
        // cout << sorted << endl;
    }
    return sorted;
}

int compareFunc(const void * A, const void * B) {
    int iA = *((int *) A);
    int iB = *((int *) B);
    cout << "iA: " << iA << " iB: " << iB << " " << endl;
    return iA - iB;
}

int main() {
    int intArr[ARR_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    bool sortedOrNot = isSorted(intArr, ARR_SIZE, sizeof(int), compareFunc);
    cout << "sorted? " << sortedOrNot << endl;
    return 0;
}
