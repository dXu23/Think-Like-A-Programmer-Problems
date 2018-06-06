#include <iostream>
using namespace::std;

char * substring(char * arrayString, int start, int length) {
    char * subStr = (char *) malloc((length + 1) * sizeof(char));
    strcpy(subStr, &arrayString[start], length);
    subStr[length] = '\0';
    return subStr;
}

int main() {
    char * userString;
    char * resultString;
    cout << "Please enter a string:" << endl;
    userString << cin;
    cout << "Now please enter an integer:" << endl;
    userString = substring(userString, start, );

}
