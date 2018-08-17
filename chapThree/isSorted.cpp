#include <iostream>
using namespace::std;

#define ARR_SIZE 20

int compareFunc(const void * A, const void * B) {
    int iA = *((int *) A);
    int iB = *((int *) B);
    return iA - iB;
}

int main() {
    int intArr[ARR_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    bool sortedOrNot = isSorted(intArr, ARR_SIZE, sizeof(int), compareFunc);
    cout << "sorted? " << sortedOrNot << endl;
    return 0;
}
