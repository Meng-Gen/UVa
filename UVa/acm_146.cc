#include <algorithm>
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
    std::string id_code;
    while (std::cin >> id_code)
    {
        if (id_code == "#")
        {
            break;
        }
        if (next_permutation(id_code.begin(), id_code.end()))
        {
            std::cout << id_code << std::endl;
        }
        else
        {
            std::cout << "No Successor" << std::endl;
        }
    }
    
    return 0;
}