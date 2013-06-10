#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stdio.h>

struct BlackBookRecord
{
    std::string title; 
    std::string first_name;
    std::string last_name;
    std::string home_address;
    std::string department;
    std::string home_phone;
    std::string work_phone;
    std::string campus_box;

    void Print()
    {
        std::cout << "----------------------------------------" << std::endl;
        std::cout << title << " " << first_name << " " << last_name 
            << std::endl;
        std::cout << home_address << std::endl;
        std::cout << "Department: " << department << std::endl;
        std::cout << "Home Phone: " << home_phone << std::endl;
        std::cout << "Work Phone: " << work_phone << std::endl;
        std::cout << "Campus Box: " << campus_box << std::endl;
    }
};

bool Compare(const BlackBookRecord& a, const BlackBookRecord& b)
{
    return a.last_name < b.last_name;
}

int main(int argc, char* argv[]) 
{
    int num_departments;
    std::cin >> num_departments;
    getchar();

    std::vector<BlackBookRecord> members;
    std::string curr_department;
    for (int i = 0; i < num_departments; i++)
    {
        getline(std::cin, curr_department);
        
        std::string record;
        while (getline(std::cin, record) && record.size())
        {
            BlackBookRecord member;
            member.department = curr_department;
            std::stringstream record_source(record);
            std::getline(record_source, member.title, ','); 
            std::getline(record_source, member.first_name, ','); 
            std::getline(record_source, member.last_name, ','); 
            std::getline(record_source, member.home_address, ','); 
            std::getline(record_source, member.home_phone, ','); 
            std::getline(record_source, member.work_phone, ','); 
            std::getline(record_source, member.campus_box, ',');

            members.push_back(member);
        }
    }
    
    std::sort(members.begin(), members.end(), Compare);
    for (std::vector<BlackBookRecord>::iterator it = members.begin();
        it != members.end(); it++)
    {
        it->Print();
    }

    return 0;
}