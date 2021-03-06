#include <iostream>
using namespace::std;

void _refHelper(unsigned int i, int bound) {
    unsigned int j, k, spaces = (bound - i ) / 2;
    for (k = 0; k < spaces; k++) {
        cout << " ";
    }
    for (j = 0; j < i; j++) {
        cout << "#";
    }
    for (k = 0; k < spaces; k++) {
        cout << " ";
    }
    cout << endl;
}

void icicle(unsigned int num) {
    for (unsigned int i = num; i > 0; i -=2) {
        _refHelper(i, num);
    }
}

void reflection(unsigned int num) {
    unsigned int i;
    for (i = 0; i < num; i +=2) {
        _refHelper(i, num);
    }
    for (i = 0; i < num; i++) {
        cout << "#";
    }

    cout << endl;
    for (i = num; i > 0; i -=2) {
        _refHelper(i, num);
    }
}

void _xHelper(unsigned int i, unsigned int bound) {
    unsigned int j, spaces = 4 * (bound - 1) - 4 * i;

    for (j = 0; j < i - 1; j++) {
        cout << " ";
    }

    for (j = 0; j < i; j++) {
        cout << "#";
    }

    for (j = 0; j < spaces; j++) {
        cout << " ";
    }

    for (j = 0; j < i; j++) {
        cout << "#";
    }

    for (j = 0; j < i - 1; j++) {
        cout << " ";
    }

    cout << endl;
}

void X(unsigned int bound) {
    unsigned int i;
    for (i = 0; i < bound; i++) {
        _xHelper(i, bound);
    }
    for (i = bound - 1; i > 0; i--) {
        _xHelper(i, bound);
    }
}

bool valid_isbn(char num[13]) {
    unsigned int sum = 0, digit;
    for (size_t i = 0; i < 13; i++) {
        digit = num[i] - '0';
        if (digit < 0 || digit > 9) {
            cout << "Invalid number" << endl;
            return false;
        }

        sum += i % 2 == 0 ? num[i] - '0' : 3 * (num[i] - '0');
    }

    return sum % 10 == 0;
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


int convertCharToDigit(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else if (c >= 'A' && c <= 'Z') {
        return c - '7';
    } else {
        return -1;
    }
}

char convertDigitToChar(int num) {
    if (num >= 0 && num <= 9) {
        return (char) (num + '0');
    } else if (num >= 10 && num <= 15) {
        return (char) (num + '7');
    } else {
        return '\0';
    }
}

int anyBaseToDecimal(char * numInput, int base) {
    int numOutput = 0; 
    int digit;
    int i = 0;
    while (numInput[i] != '\0') {
        digit = convertCharToDigit(numInput[i]);
        if (digit != -1) {
            numOutput = base * numOutput + (convertCharToDigit(numInput[i]));
        } else {
            return -1;
        }
        i++;
    }
    return numOutput;
}

void decimalToAnyBase(int num, int base) {
    if (num == 0) {
        return;
    }
    char digit = convertDigitToChar(num % base);
    decimalToAnyBase(num / base, base);
    cout << digit;
}

void baseToBase(char * num1, int base1, int base2) {
    int decNum = anyBaseToDecimal(num1, base);
    decimalToAnyBase(decNum, base2);
}

/* Function to be deleted
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
    } else {
        return -1;
    }
}

convertCharToDigit(char c)

int main() {
    // Problem 1: Using only single-character output statements that output a hash mark, a
    // space, or an end-of-line, write a program that produces the following shape
    //
    // ########
    //  ######
    //   ####
    //    ##
  
    cout << "Problem 1:\n\n";
    icicle(8);
    
    // Problem 2: Or how about:
    //
    //    ##
    //   ####
    //  ######
    // ########
    // ########
    //  ######
    //   ####
    //    ##
    
    cout << "\n\nProblem 2:\n\n";
    reflection(8);
    
    // Problem 3: Here's an especially tricky one:
    //
    // #            #
    //  ##        ##
    //   ###    ###
    //    ########
    //    ########
    //   ###    ###
    //  ##        ##
    // #            #
    
    cout << "\n\n Problem 3:\n\n";
    X(5);

    // Problem 5
    cout << "\n\nProblem 5: Please enter a 13-digit ISBN number\n\n";
    char isbnNumber[13];
    cin >> isbnNumber;
    if (valid_isbn(isbnNumber)) {
        cout << "The number was valid." << endl;
    } else {
        cout << "The number was invalid!\n" << endl;
    }
    
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
