#include <iostream>
#include <bitset>
#include <string>

using namespace std;

void findInterfaceAndPin(unsigned int hexInput) {
    // Interfaces and their pin capacities
    const int pinsPerInterface[6] = {12, 12, 12, 12, 12, 4};
    const string interfaceNames[6] = {
        "Front Panel", "Field Bus", "Hub A", "Hub B", "Sub A", "Sub B"};

    // Convert the hex input to binary (64 bits)
    bitset<64> binary(hexInput);

    // Display the 64-bit binary representation
    cout << "64-bit Binary Representation: " << binary << endl;

    // Calculate the pin position from the binary representation
    int position = -1; // Default position if no bit is set
    for (int i = 0; i < 64; ++i) {
        if (binary[i]) {
            position = i; // The rightmost set bit gives the position
            break;
        }
    }

    if (position == -1) {
        cout << "No pin selected (no bits set in the binary representation)." << endl;
        return;
    }

    // Determine the interface and pin number based on the position
    int cumulativePins = 0;
    for (int i = 0; i < 6; ++i) {
        cumulativePins += pinsPerInterface[i];
        if (position < cumulativePins) {
            int pinNumber = position - (cumulativePins - pinsPerInterface[i]) + 1;
            cout << "Interface Used: " << interfaceNames[i] << endl;
            cout << "Pin Number: " << pinNumber << endl;
            return;
        }
    }

    cout << "Position out of range of defined interfaces and pins." << endl;
}

int main() {
    unsigned int hexInput;

    // Input the hexadecimal number
    cout << "Enter a hexadecimal number (e.g., 0x20): ";
    cin >> hex >> hexInput;

    // Find and display the interface and pin
    findInterfaceAndPin(hexInput);

    return 0;
}
