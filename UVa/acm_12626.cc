#include <iostream>
#include <map>
#include <string>
#include <stdio.h>

int minimum(int a, int b)
{
    return (a > b) ? b : a;
}

std::map<char, int> margarita;

void InitMargarita()
{
    std::string pizza("MARGARITA");
    for (std::string::iterator it = pizza.begin(); it != pizza.end(); it++)
    {
        margarita[*it]++;
    }
}

int main(int argc, char* argv[]) 
{   
    InitMargarita();

    int num_testcases;
    std::cin >> num_testcases;
    while (num_testcases--)
    {
        std::string ingredients_string;
        std::cin >> ingredients_string;

        std::map<char, int> ingredients;
        for (std::string::iterator it = ingredients_string.begin(); 
            it != ingredients_string.end(); it++)
        {
            ingredients[*it]++;
        }
        
        int pizza_count = ingredients_string.size();
        for (std::map<char, int>::iterator it = margarita.begin();
            it != margarita.end(); it++)
        {            
            pizza_count = minimum(pizza_count, 
                ingredients[it->first] / it->second);   
        }
        std::cout << pizza_count << std::endl;
    }
    return 0;
}
