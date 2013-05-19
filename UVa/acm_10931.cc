#include <bitset>
#include <iostream>
#include <string>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int I;
    while (std::cin >> I && I)
    {
        std::string binary_form = std::bitset<64>(I).to_string();
        binary_form = binary_form.substr(binary_form.find('1'));

        int parity = 0;
        for (int i = 0; i < binary_form.size(); i++)
        {
            if (binary_form[i] == '1') 
            {
                parity++;
            }
        }
        std::cout << "The parity of " << binary_form << " is " 
            << parity << " (mod 2)." << std::endl;
    }
    return 0;
}