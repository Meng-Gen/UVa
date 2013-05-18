#include <iterator>
#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>

struct IntegerSet
{
    std::set<int> elements;

    void Build(const std::string& set_string)
    {
        std::stringstream set_string_stream(set_string);
        std::istream_iterator<int> it(set_string_stream);
        std::istream_iterator<int> end;
        std::vector<int> tokens(it, end);

        elements = std::set<int>(tokens.begin(), tokens.end());
    }

    bool Contains(const IntegerSet& another)
    {
        for (std::set<int>::const_iterator it = another.elements.begin(); 
            it != another.elements.end(); ++it)
        {
            if (elements.find(*it) == elements.end())
            {
                return false;
            }
        }
        return true;
    }

    bool AreDisjoint(const IntegerSet& another)
    {
        for (std::set<int>::const_iterator it = another.elements.begin(); 
            it != another.elements.end(); ++it)
        {
            if (elements.find(*it) != elements.end())
            {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char* argv[])
{
    IntegerSet A;
    IntegerSet B;

    std::string set_string;
    while (getline(std::cin, set_string))
    {
        A.Build(set_string);
        getline(std::cin, set_string);
        B.Build(set_string);

        bool is_a_proper_of_b = B.Contains(A);
        bool is_b_proper_of_a = A.Contains(B);

        if (is_a_proper_of_b && is_b_proper_of_a)
        {
            printf("A equals B\n");
        }
        else if (is_b_proper_of_a)
        {
            printf("B is a proper subset of A\n");
        }
        else if (is_a_proper_of_b)
        {
            printf("A is a proper subset of B\n");
        }
        else if (A.AreDisjoint(B))
        {
            printf("A and B are disjoint\n");
        }
        else 
        {
            printf("I'm confused!\n");   
        }
    }
    
    return 0;
}