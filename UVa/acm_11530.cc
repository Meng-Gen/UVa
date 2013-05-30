#include <iostream>
#include <map>
#include <string>
#include <stdio.h>

std::map<char, int> press_count;

void InitPressCount()
{
    for (int i = 'a'; i <= 'w'; i += 3)
    {
        press_count[i] = 1;
        press_count[i+1] = 2;
        press_count[i+2] = 3;
        if (i == 'p')
        {
            i++;
        }
    }
    press_count['s'] = 4;
    press_count['z'] = 4;
    press_count[' '] = 1;
}

int main(int argc, char* argv[]) 
{
    InitPressCount();

    int num_testcases;
    std::cin >> num_testcases;
    getchar();
    for (int case_id = 1; case_id <= num_testcases; case_id++)
    {
        std::string message;
        getline(std::cin, message);

        int total_press_count = 0;
        int message_length = message.size();
        for (int i = 0; i < message_length; i++)
        {
            total_press_count += press_count[message[i]];
        }
        printf("Case #%d: %d\n", case_id, total_press_count);
    }
    return 0;
}
