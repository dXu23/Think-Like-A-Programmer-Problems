#include <iostream>
#include "usefulArrayFunc.h"
using namespace::std;

const int NUM_AGENTS = 3;
const int NUM_MONTHS = 12;

int sales[NUM_AGENTS][NUM_MONTHS] = {
    {1856, 498, 30924, 87478, 328, 2653, 387, 3754, 387587, 2873, 276, 32},
    {5865, 5456, 3983, 6464, 9957, 4785, 3875, 3838, 4959, 1122, 7766, 2534},
    {23, 55, 67, 99, 265, 376, 232, 223, 4546, 564, 4544, 3434}
};

/*
double arrayMedian2(int intArray[], int ARRAY_SIZE) {
    int median;
    int greaterThan = 0;
    int lessThan = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        median = intArray[i];
    }
*/

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
