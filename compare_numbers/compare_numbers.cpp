#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        return 1;
    }

    char* number1 = argv[1];
    char* number2 = argv[2];

    if (number1[0] == '-' and number2[0] != '-') {
        std::cout << "less\n";
        return 0;
    }
    else if (number1[0] != '-' and number2[0] == '-') {
        std::cout << "greater\n";
        return 0;
    }

    int i1 = (number1[0] == '+' or number1[0] == '-');
    int i2 = (number2[0] == '+' or number2[0] == '-');

    int len1 = 0, len2 = 0;

    while (number1[i1] != '.' and number1[i1] != '\0') {
        len1++;
        i1++;
    }
    while (number2[i2] != '.' and number2[i2] != '\0') {
        len2++;
        i2++;
    }

    if (len1 != len2) {
        if (number1[0] == '-') {
            if (len1 < len2) {
                std::cout << "greater\n";
                return 0;
            }
            else {
                std::cout << "less\n";
                return 0;
            }
        }
        else {
            if (len1 < len2) {
                std::cout << "less\n";
                return 0;
            }
            else {
                std::cout << "greater\n";
                return 0;
            }
        }
    }

    int s1 = (number1[0] == '+' or number1[0] == '-');
    int s2 = (number2[0] == '+' or number2[0] == '-');
    for (int i = 0; i < len1; i++) {
        if (number1[0] == '-') {
            if (number1[i + s1] < number2[i + s2]) {
                std::cout << "greater\n";
                return 0;
            }
            else if (number1[i + s1] > number2[i + s2]) {
                std::cout << "less\n";
                return 0;
            }
        }
        else {
            if (number1[i + s1] < number2[i + s2]) {
                std::cout << "less\n";
                return 0;
            }
            else if (number1[i + s1] > number2[i + s2]) {
                std::cout << "greater\n";
                return 0;
            }
        }
    }

    if (number1[i1] == '\0' and number2[i2] == '\0') {
        std::cout << "equal\n";
        return 0;
    }
    if (number1[i1] == '.') i1++;
    if (number2[i2] == '.') i2++;
    while (number1[i1] != '\0' or number2[i2] != '\0') {
        char c1 = (number1[i1] == '\0') ? '0' : number1[i1];
        char c2 = (number2[i2] == '\0') ? '0' : number2[i2];
        if (number1[0] == '-') {
            if (c1 < c2) {
                std::cout << "greater\n";
                return 0;
            }
            else if (c1 > c2) {
                std::cout << "less\n";
                return 0;
            }
        }
        else {
            if (c1 < c2) {
                std::cout << "less\n";
                return 0;
            }
            else if (c1 > c2) {
                std::cout << "greater\n";
                return 0;
            }
        }
        if (number1[i1] != '\0') i1++;
        if (number2[i2] != '\0') i2++;
    }

    std::cout << "equal\n";

    return 0;
}