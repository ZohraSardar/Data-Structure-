#include <iostream>

int power(int base, int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}

int countDigits(int number) {
    int count = 0;
    while (number != 0) {
        number /= 10;
        count++;
    }
    return count;
}

bool isArmstrongNumber(int number) {
    int originalNumber = number;
    int numDigits = countDigits(number);
    int armstrongSum = 0;

    while (number != 0) {
        int digit = number % 10;
        armstrongSum += power(digit, numDigits);
        number /= 10;
    }

    return (armstrongSum == originalNumber);
}

int main() {
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;

    if (isArmstrongNumber(number)) {
        std::cout << number << " is an Armstrong number." << std::endl;
    } else {
        std::cout << number << " is not an Armstrong number." << std::endl;
    }

    return 0;
}

