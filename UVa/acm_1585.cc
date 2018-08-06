#include <ios>
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int testcases;
    std::cin >> testcases;
    while (testcases--) {
        std::string s;
        std::cin >> s;
        int total_count = 0;
        int count = 0;
        for (std::string::size_type i = 0; i < s.size(); i++) {
            if (s[i] == 'O') {
                count++;
                total_count += count;
            } else {
                count = 0;
            }
        }
        std::cout << total_count << '\n';
    }
    return 0;
}