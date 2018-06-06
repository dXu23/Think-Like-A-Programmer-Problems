#include <iostream>
using namespace::std;

const char cipherArr[26] = {'M', 'Z', 'D', 'O', 'Y', 'C', 'F', 'X', 'A', 'V', 'N', 'J', 'Q', 'R', 'B', 'G', 'L', 'T', 'W', 'E', 'I', 'P', 'H', 'S', 'K', 'U'}; 

char * encode(char * message, int msgSize, const char cipherArr[26]) {
    char * cipherText = (char *) malloc(msgSize * sizeof(char));
    for (int i = 0; i < msgSize; i++) {
        if (message[i] >= 'A' && message[i] <= 'Z') {
            cipherText[i] = cipherArr[message[i] - 'A'];
        } else {
            cipherText[i] = message[i];
        }
    }
    return cipherText;
}

char * decode(char * cipher, int cipherSize, const char cipherArr[26]) {
    char * message = (char *) malloc(cipherSize * sizeof(char));
    int j; 
    for (int i = 0; i < cipherSize; i++) {
        j = 0;
        if (cipher[i] >= 'A' && cipher[i] <= 'Z') {
            while (cipher[i] != cipherArr[j]) {
                j++;
            }
            message[i] = (j + 1) + 'A' - 1;
        } else {
            message[i] = cipher[i];
        }
    }
    return message;
}

int main() {
    char msg[46] = "THE QUICK BROWN FOX JUMPED OVER THE LAZY DOG.";
    char * cipher = encode(msg, 46, cipherArr);
    cout << cipher << endl;
    char * decodedMsg = decode(cipher, 46, cipherArr);
    cout << decodedMsg << endl;
    return 0;
}
