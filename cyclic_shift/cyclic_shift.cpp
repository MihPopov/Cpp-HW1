#include <iostream>

int* create_array(size_t size) {
    return new int[size];
}

void print_array(int* array, size_t n) {
    for (size_t i = 0; i < n; i++) {
        std::cout << array[i] << '\n';
    }
    for (size_t i = 0; i < n; i++) {
        std::cout << array[i];
        if (i != n - 1) {
            std::cout << ' ';
        }
        else {
            std::cout << '\n';
        }
    }
}

void reverse_array(int* array, int left, int right) {
    while (left < right) {
        int temp = array[left];
        array[left] = array[right];
        array[right] = temp;

        left++;
        right--;
    }
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

    int* array = create_array(n);
    for (int i = 0; i < n; i++) {
        if (!(std::cin >> array[i])) {
            delete[] array;
            return 1;
        }
    }
    int k;
    if (!(std::cin >> k)) {
        delete[] array;
        return 1;
    }

    k = k % n;
    if (k == 0) {
        print_array(array, n);
        delete[] array;
        return 0;
    }
    if (k < 0) k += n;
    reverse_array(array, 0, n - 1);
    reverse_array(array, 0, k - 1);
    reverse_array(array, k, n - 1);

    print_array(array, n);

    delete[] array;

    return 0;
}