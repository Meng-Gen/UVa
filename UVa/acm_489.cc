#include <iostream>
#include <string>
#include <map>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int round;
    std::string solution;
    std::string guesses;
    while (std::cin >> round && (round != -1))
    {
        getchar();
        getline(std::cin, solution);
        getline(std::cin, guesses);

        std::map<char, int> solution_letters;
        for (std::string::iterator it = solution.begin(); 
            it != solution.end(); it++)
        {
            solution_letters[*it]++;
        }

        int solution_letter_count = solution_letters.size();
        bool is_winning = false;
        bool is_losing = false;
        std::map<char, int> guessed_letters;
        int correct_count = 0;
        int wrong_count = 0;
        for (int i = 0; i < guesses.size(); i++)
        {
            if (guessed_letters[guesses[i]])
            {
                continue;
            }
            guessed_letters[guesses[i]]++;
            if (solution_letters[guesses[i]])
            {
                correct_count++;
                if (correct_count == solution_letter_count)
                {
                    is_winning = true;
                    break;
                }
            }
            else
            {
                wrong_count++;
                if (wrong_count >= 7)
                {
                    is_losing = true;
                    break;
                }
            }
        }

        printf("Round %d\n", round);
        if (is_winning)
        {
            puts("You win.");
        }
        else if (is_losing)
        {
            puts("You lose.");
        }
        else
        {
            puts("You chickened out.");
        }
    }

    return 0;
}