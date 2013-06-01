#include <iterator>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>

int main(int argc, char* argv[]) 
{   
    int num_testcases;
    std::cin >> num_testcases;
    getchar();
    getchar();

    for (int case_id = 1; case_id <= num_testcases; case_id++)
    {
        if (case_id > 1)
        {
            putchar('\n');
        }
        printf("Case #%d:\n", case_id);
        std::string sentence;
        while (getline(std::cin, sentence) && sentence.size())
        {
            std::stringstream sentence_stream(sentence);
            std::istream_iterator<std::string> it(sentence_stream);
            std::istream_iterator<std::string> end;
            std::vector<std::string> tokens(it, end);
            
            int curr_pos = 0;
            for (int i = 0; i < tokens.size(); i++)
            {
                if (tokens[i].size() > curr_pos)
                {
                    putchar(tokens[i][curr_pos]);
                    curr_pos++;
                }
            }
            putchar('\n');
        }
    }

    return 0;
}
