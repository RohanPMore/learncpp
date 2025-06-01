#include <iostream>
#include <cctype> // For isdigit and toupper

using namespace std;

int hexToDecimal(const char* hexString) {
    int value = 0;

    // Iterate through each character in the hex string
    while (*hexString) {
        if (isdigit(*hexString)) {
            // If character is a digit (0-9)
            value = (value << 4) + (*hexString - '0');
        } else {
            // If character is a letter (A-F or a-f)
            value = (value << 4) + (toupper(*hexString) - 'A' + 10);
        }
        hexString++;
    }

    return value;
}

int main() {
    const char* hexInput = "1010";//Eample hexadecimal input
    cout << "Decimal Value: " << hexToDecimal(hexInput) << endl;
    return 0;
}
