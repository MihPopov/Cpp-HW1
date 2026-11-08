#include <iostream>

int len_of_number(char* number, bool has_sign) {
    int len = 0;
    int index = has_sign ? 1 : 0;
    while (number[index] != '.' && number[index] != '\0') {
        len++;
        index++;
    }
    return len;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        return 1;
    }

    char* number1 = argv[1];
    char* number2 = argv[2];

    if (number1[0] == '-' && number2[0] != '-') {
        std::cout << "less\n";
        return 0;
    }
    else if (number1[0] != '-' && number2[0] == '-') {
        std::cout << "greater\n";
        return 0;
    }

    bool has_sign_1 = (number1[0] == '+' || number1[0] == '-');
    bool has_sign_2 = (number2[0] == '+' || number2[0] == '-');
    bool is_negative = number1[0] == '-';

    int len1 = len_of_number(number1, has_sign_1);
    int len2 = len_of_number(number2, has_sign_2);

    bool invert_result = is_negative;

    if (len1 != len2) {
        bool n1_is_less = len1 < len2;
        if (invert_result) n1_is_less = !n1_is_less;
        if (n1_is_less) {
            std::cout << "less\n";
        }
        else {
            std::cout << "greater\n";
        }
        return 0;
    }

    int number1_index = has_sign_1 ? 1 : 0;
    int number2_index = has_sign_2 ? 1 : 0;
    for (int i = 0; i < len1; i++) {
        char digit_1 = number1[i + number1_index];
        char digit_2 = number2[i + number2_index];
        if (digit_1 != digit_2) {
            bool d1_is_less = digit_1 < digit_2;
            if (invert_result) d1_is_less = !d1_is_less;
            if (d1_is_less) {
                std::cout << "less\n";
            }
            else {
                std::cout << "greater\n";
            }
            return 0;
        }
    }

    number1_index += len1;
    number2_index += len2;
    if (number1[number1_index] == '\0' && number2[number2_index] == '\0') {
        std::cout << "equal\n";
        return 0;
    }
    if (number1[number1_index] == '.') number1_index++;
    if (number2[number2_index] == '.') number2_index++;
    while (number1[number1_index] != '\0' || number2[number2_index] != '\0') {
        char digit_1 = (number1[number1_index] == '\0') ? '0' : number1[number1_index];
        char digit_2 = (number2[number2_index] == '\0') ? '0' : number2[number2_index];
        if (digit_1 != digit_2) {
            bool d1_is_less = digit_1 < digit_2;
            if (invert_result) d1_is_less = !d1_is_less;
            if (d1_is_less) {
                std::cout << "less\n";
            }
            else {
                std::cout << "greater\n";
            }
            return 0;
        }
        if (number1[number1_index] != '\0') number1_index++;
        if (number2[number2_index] != '\0') number2_index++;
    }

    std::cout << "equal\n";

    return 0;
}