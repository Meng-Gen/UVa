#include <iostream>

long long factorial[6] = {
    40320, 362880, 3628800, 39916800, 479001600, 6227020800
};

int main(int argc, const char* argv[]) {
    long long n;
    while (std::cin >> n) {
        if (n < 0) {
            if (n % 2 == 0) {
                std::cout << "Underflow!" << std::endl;
            } else {
                std::cout << "Overflow!" << std::endl;
            }
        }
        else if (n < 8) {
            std::cout << "Underflow!" << std::endl;
        } else if (n > 13) {
            std::cout << "Overflow!" << std::endl;
        }
        else {
            std::cout << factorial[n - 8] << std::endl;
        }
    }
    return 0;
}
