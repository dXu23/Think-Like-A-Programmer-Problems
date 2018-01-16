#include <iostream>
using namespace::std;

void _refHelper(int i, int bound) {
    int spaces = (bound - i ) / 2;
    for (int k = 0; k < spaces; k++) {
	cout << " ";
    }
    for (int j = 0; j < i; j++) {
	cout << "#";
    }
    for (int k = 0; k < spaces; k++) {
	cout << " ";
    }
    cout << endl;
}

void icicle(int num) {
    for (int i = num; i > 0; i -=2) {
	_refHelper(i, num);
    }
}

void reflection(int num) {
    for (int i = 0; i < num; i +=2) {
	_refHelper(i, num);
    }
    for (int i = 0; i < num; i++) {
	cout << "#";
    }
    cout << endl;
    for (int i = num; i > 0; i -=2) {
	_refHelper(i, num);
    }
}

void _xHelper(int i, int bound) {
    int spaces = 4 * (bound - 1) - 4 * i;
    for (int j = 0; j < i - 1; j++) {
	cout << " ";
    }
    for (int j = 0; j < i; j++) {
	cout << "#";
    }
    for (int j = 0; j < spaces; j++) {
	cout << " ";
    }
    for (int j = 0; j < i; j++) {
	cout << "#";
    }
    for (int j = 0; j < i - 1; j++) {
	cout << " ";
    }
    cout << endl;
}

void X(int bound) {
    for (int i = 0; i < bound; i++) {
	_xHelper(i, bound);
    }
    int param = bound - 1;
    for (int i = param; i > 0; i--) {
	_xHelper(i, bound);
    }
}

void _decimalToBin(int num) {
    if (num == 0) {
	return;
    }
    int digit = num % 2;
    _decimalToBin(num / 2);
    cout << digit;
}

void decimalToBin(int num) {
    _decimalToBin(num);
    cout << endl;
}

int binToDecimal(char * bin) {
    int num = 0;
    int i = 0;
    while (bin[i] != '\0') {
      //cout << bin[i] << endl;
        //cout << bin[i] - '0' << endl;
	num = 2 * num + (bin[i] - '0');
	//cout << num << endl;
	i++;
    }
    return num;
}

/*
binDecConversion() {
    int choice = 0;
    int result;
    cout << "Type 0 to choose to convert from binary to decimal or 1 to convert from decimal to binary: \n";
    choice << cin;
    choice = choice - '0';
    char * num;
    if (choice == 0) {
	result = binToDecimal(choice);
	cout << result;
    }
    else if (choice == 1) {
    }
}
*/

char digitHelper(int num) {
    if ((num >= 0) && (num < 10)) {
	return (char) num + '0';
    }
    else if ((num >= 10) && (num < 16)) {
	return (char) num + 55;
    }
}

/*
char convertNum(int num, int base) {
    if (num == 0) {
	return;
    }
    int digit = num % 2;
    _decimalToBin(num / 2);
    cout << digit;
}
*/

int main() {
    // Problem 1
    cout << "Problem 1:\n\n";
    icicle(8);
    
    // Problem 2
    cout << "\n\nProblem 2:\n\n";
    reflection(8);
    
    // Problem 3
    cout << "\n\n Problem 3:\n\n";
    X(5);

    // Problem 5
    cout << "\n\n Problem 5:\n\n";
    
    // Problem 6
    cout << "\n\nProblem 6: Please enter a decimal to be converted to binary: ";
    int number;
    cin >> number;
    decimalToBin(number);
    cout << "\n\nNow please enter a binary number: ";
    char binNum[32];
    cin >> binNum;
    cout << binToDecimal(binNum);
    cout << endl;
    return 0;
}
