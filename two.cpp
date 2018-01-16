#include <iostream>
using namespace::std;

bool isSorted(int arr[], int size) {
    bool sortedOrNot = true;
    for (int i = 1; i < size; i++) {
	sortedOrNot = sortedOrNot && (arr[i - 1] <= arr[i]);
    }
    return sortedOrNot;
}

