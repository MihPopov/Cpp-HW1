#include <iostream>

double* create_array(size_t size) {
    return new double[size];
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        return 1;
    }
    char* sn = argv[1];
    int n = 0, ind = 0;
    while (sn[ind] != '\0') {
        n *= 10;
        n += sn[ind] - '0';
        ind++;
    }

    double* a = create_array(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    double result = 0;
    double b;
    for (int i = 0; i < n; i++) {
        std::cin >> b;
        result += a[i] * b;
    }

    delete[] a;

    std::cout << result << '\n';
}