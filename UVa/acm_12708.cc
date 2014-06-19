#include <iostream>

int main(int argc, const char* argv[]) {
    int num_testcases;
    std::cin >> num_testcases;
    
    for (int i = 0; i < num_testcases; i++) {
        long long n;
        std::cin >> n;
        std::cout << n / 2 << std::endl;
    }
    return 0;
}
