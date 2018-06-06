#include <iostream>
using namespace::std;

bool isSorted(void * arr, int size, size_t structSize, int (func) (void * a) (void * b)) {
    bool sorted = true;
    for (int i = 0; i < size; i++) {
        sorted = sorted & func(arr[i], arr[i + 1]);
    }
}

int main() {
}
