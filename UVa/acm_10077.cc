#include <iostream>

int main(int argc, char* argv[]) {
    long long m;
    long long n;
    while (std::cin >> m >> n) {
        if ((m == 1) && (n == 1)) {
            break;
        }
        
        while ((m != 1) || (n != 1)) {
            if (m > n) {
                std::cout << 'R';
                m -= n;
            } else {
                std::cout << 'L';
                n -= m;
            }
        }
        std::cout << std::endl;
    }
    return 0;
}