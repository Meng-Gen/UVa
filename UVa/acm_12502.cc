#include <iostream>

int main(int argc, const char* argv[]) {
    int num_testcases;
    std::cin >> num_testcases;

    // Three families share a garden.  For example, family A spent 5 hours and family B spent 4 hours
    // and had everything done.  It implies that each family should spend 3 hours on its shared garden.
    // So family A could get $90 * (5-3) / 3 = $60.
    long long x;
    long long y;
    long long z;
    for (int i = 0; i < num_testcases; i++) {
        std::cin >> x >> y >> z;
        std::cout << (2 * x - y ) * z / (x + y) << std::endl;
    }
    return 0;
}