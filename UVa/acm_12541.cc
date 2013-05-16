#include <algorithm>
#include <iostream>
#include <stdio.h>

struct Person
{
    char person_name[16];  
    int day;
    int month;
    int year;
};

bool compare(const Person &a, const Person &b)
{
    if (a.year > b.year)
    {
        return true;
    }
    else if (a.year < b.year) 
    {
        return false;
    }
    
    if (a.month > b.month)
    {
        return true;
    }
    else if (a.month < b.month) 
    {
        return false;
    }

    if (a.day > b.day)
    {
        return true;
    }
    else if (a.day < b.day) 
    {
        return false;
    }

    // It should not be here by problem settings.
    return false;
}

Person persons[101];

int main(int argc, char* argv[])
{
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> persons[i].person_name 
            >> persons[i].day >> persons[i].month >> persons[i].year;
    }

    std::sort(persons, persons + n, compare);

    std::cout << persons[0].person_name << std::endl;
    std::cout << persons[n-1].person_name << std::endl;

    return 0;
}
