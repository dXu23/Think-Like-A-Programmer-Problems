#include <string>
#include <iostream>
using namespace std;
// using std::endl;

struct student {
    int grade;
    int studentID;
    string name;
};

const int ARRAY_SIZE = 10;
student studentArray[ARRAY_SIZE] = {
    {87, 10001, "Fred"},
    {28, 10002, "Tom"},
    {100, 10003, "Alistair"},
    {78, 10004, "Sasha"},
    {84, 10005, "Erin"},
    {98, 10006, "Belinda"},
    {75, 10007, "Leslie"},
    {70, 10008, "Candy"},
    {81, 10009, "Aretha"},
    {68, 10010, "Veronica"},
};

int compareByGrade( const void * studentA, const void * studentB ) {
    int Agrade = ((student *) studentA)->grade;
    int Bgrade = ((student *) studentB)->grade;
    return Agrade - Bgrade;
}

int compareByStudentID( const void * studentA, const void * studentB ) {
    int AstudentID = ((student *) studentA)->studentID;
    int BstudentID = ((student *) studentB)->studentID;
    return AstudentID - BstudentID;
}

void printStudentArr(student studentArr[], int size) {
    cout << "Grade" << "\t" << "Student ID" << "\t" << "Name" << endl;
    for (int i = 0; i < size; i++) {
        cout << studentArr[i].grade << "\t" << studentArr[i].studentID << "\t" << studentArr[i].name << endl;
    }
}

int maximum(student studentArr[], int size) {
    int max = 0;
    for (int i = 0; i < size; i++) {
        if (studentArr[i].grade > max) {
            max = studentArr[i].grade;
        }
    }
    return max;
}

int minimum(student studentArr[], int size) {
    int min = maximum(studentArr, size);
    for (int i = 0; i < size; i++) {
        if (studentArr[i].grade < min) {
            min = studentArr[i].grade;
        }
    }
    return min;
}

int average(student studentArr[], int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += studentArr[i].grade;
    }
    return total / size;
}

int firstQuartile(student studentArr[], int size) {
    return (minimum(studentArr, size) + average(studentArr, size)) / 2;
}

double arrayMedian(int intArray[], int size) {
    int sortedCopy[size];
    for (int i = 0; i < size; i++) {
        sortedCopy[i] = intArray[i];
    }
    qsort(sortedCopy, size, sizeof(int), compareByGrade);
    if (size % 2 == 0) {
        return (sortedCopy[size / 2] + sortedCopy[size / 2 - 1]) / 2;
    } else {
        return sortedCopy[size / 2];
    }
}
int lastQuartile(student studentArr[], int size) {
    return (average(studentArr, size) + arrayMedian(studentArr, size)) / 2;
}
    
int main() {
    printStudentArr(studentArray, ARRAY_SIZE);
    qsort(studentArray, ARRAY_SIZE, sizeof(student), compareByGrade); 
    printStudentArr(studentArray, ARRAY_SIZE);
    // delete [] studentArray;
    cout << "First Quartile" << "\t" << "Second Quartile" << "\t" << "Last Quartile" << "\n" << endl;
    cout << firstQuartile(studentArray, ARRAY_SIZE) << "\t" << arrayMedian(studentArray, ARRAY_SIZE) << "\t" << lastQuartile(studentArray, ARRAY_SIZE) << endl;
    cout << "Line 88" << endl;
    return 0;
}
