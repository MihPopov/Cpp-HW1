#include <iostream>

double* create_array(size_t size) {
    return new double[size];
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        return 1;
    }

    int n = std::stoi(argv[1]);

    double* a = create_array(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    double* b = create_array(n);
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }

    double result = 0;
    for (int i = 0; i < n; i++) {
        result += a[i] * b[i];
    }

    delete[] a;
    delete[] b;

    std::cout << result << '\n';
}