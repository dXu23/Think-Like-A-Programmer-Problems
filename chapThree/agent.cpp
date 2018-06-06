#include <iostream>
using namespace::std;

const int NUM_AGENTS = 3;
const int NUM_MONTHS = 12;

int sales[NUM_AGENTS][NUM_MONTHS] = {
    {1856, 498, 30924, 87478, 328, 2653, 387, 3754, 387587, 2873, 276, 32},
    {5865, 5456, 3983, 6464, 9957, 4785, 3875, 3838, 4959, 1122, 7766, 2534},
    {23, 55, 67, 99, 265, 376, 232, 223, 4546, 564, 4544, 3434}
};

int compareFunc(const void * voidA, const void * voidB) {
    int * intA = (int *) (voidA);
    int * intB = (int *) (voidB);
    return *intA - *intB;
}

/*
double arrayMedian2(int intArray[], int ARRAY_SIZE) {
    int median;
    int greaterThan = 0;
    int lessThan = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        median = intArray[i];
    }
*/

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

int main() {
    double highestMedian = arrayMedian(sales[0], 12);
    for (int agent = 1; agent < NUM_AGENTS; agent++) {
        double agentMedian = arrayMedian(sales[agent], 12);
        if (agentMedian > highestMedian) {
            highestMedian = agentMedian;
        }
    }
    cout << "Highest monthly median: " << highestMedian << "\n";
    return 0;
}
