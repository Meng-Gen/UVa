#include <iostream>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int num_testcases;
    std::cin >> num_testcases;

    for (int case_id = 0; case_id < num_testcases; case_id++)
    {
        int premium = 0;
        int num_farmers;
        std::cin >> num_farmers;
        for (int farmer_id = 0; farmer_id < num_farmers; farmer_id++)
        {
            int farmyard_size;
            int num_animals;
            int friendliness;
            std::cin >> farmyard_size >> num_animals >> friendliness;
            premium += (farmyard_size * friendliness);
        }
        std::cout << premium << std::endl;
    }
    return 0;
}