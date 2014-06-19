#include <iostream>

int main(int argc, const char* argv[]) {
    int alice;
    int beto;
    int clara;
    while (std::cin >> alice >> beto >> clara) {
        int hashed = alice * 4 + beto * 2 + clara;
        if ((hashed == 0) || (hashed == 7)) {
            std::cout << '*' << std::endl;
        } else if ((hashed == 1) || (hashed == 6)) {
            std::cout << 'C' << std::endl;
        } else if ((hashed == 2) || (hashed == 5)) {
            std::cout << 'B' << std::endl;
        } else if ((hashed == 3) || (hashed == 4)) {
            std::cout << 'A' << std::endl;
        }
    }
    return 0;
}
