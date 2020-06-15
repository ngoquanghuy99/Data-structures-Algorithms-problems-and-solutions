#include <iostream>
#include <bitset>

int main() {
    int x = 5; // Decimal Number
    std::bitset<8> bin(x); // Convert to 8 bit binary
    std::cout << bin.to_string() << std::endl; // Binary string 

    // To count the number of set bits
    std::cout << bin.count() << std::endl;

    return 0;
}
