#include <iostream>
#include <string>

int numDigits(int x) {
    return std::to_string(x).length();
}

void printSpaces(int n) {
    for (int i = 0; i < n; i++) {
        std::cout << " ";
    }
}

int powerOfTwo(int exponent) {
    int value = 1;

    for (int i = 0; i < exponent; i++)
        value *= 2;

    return value;
}

void printRow(int level, int n, int width) {
    int spc = (n - level) * width;
    printSpaces(spc);

    for (int i = 0; i < level; i++) {
        int value = powerOfTwo(i);

        std::cout << value;

        int spaces = width - numDigits(value);
        printSpaces(spaces);
    }

    for (int i = level - 2; i >= 0; i--) {
        int value = powerOfTwo(i);

        std::cout << value;

        if (i != 0) {
            int spaces = width - numDigits(value);
            printSpaces(spaces);
        }
    }


    std::cout << std::endl;
}

void pyramid(int n, bool up) {
    int largest = powerOfTwo(n - 1);
    int width = numDigits(largest) + 1;

    if (up) {
        for (int level = 1; level <= n; level++) {
            printRow(level, n, width);
        }
    } else {
        for (int level = n; level >= 1; level--) {
            printRow(level, n, width);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout << "Usage: ./pyramid <number> <up/down>" << std::endl;
        return 1;
    }
    int n = std::stoi(argv[1]);
    std::string direction = argv[2];

    if (direction == "up") {
        pyramid(n, true);
    } else if (direction == "down") {
        pyramid(n, false);
    } else {
        std::cout << "Direction must be up or down." << std::endl;
        return 1;
    }

    return 0;
}