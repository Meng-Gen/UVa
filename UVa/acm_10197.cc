// Portuguese is similar to Spanish.  
// I love Jose/ Saramago :-)

#include <iostream>
#include <string>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int case_id = 1;
    std::string portuguese_verb;
    std::string english_meaning;
    while (std::cin >> portuguese_verb >> english_meaning)
    {
        if (case_id > 1)
        {
            putchar('\n');
        }

        printf("%s (to %s)\n", portuguese_verb.c_str(), english_meaning.c_str());
        int length = portuguese_verb.size();        
        std::string root = portuguese_verb.substr(0, length - 2);
        char good_verb[2];
        good_verb[0] = portuguese_verb[length - 2]; 
        good_verb[1] = portuguese_verb[length - 1];

        if (good_verb[1] == 'r')
        {
            if (good_verb[0] == 'a')
            {
                std::cout << "eu        " << root << "o" << std::endl;
                std::cout << "tu        " << root << "as" << std::endl;
                std::cout << "ele/ela   " << root << "a" << std::endl;
                std::cout << "n" << ((char)243) << "s       " << root << "amos" << std::endl;
                std::cout << "v" << ((char)243) << "s       " << root << "ais" << std::endl;
                std::cout << "eles/elas " << root << "am" << std::endl;
            }
            else if (good_verb[0] == 'e')
            {
                std::cout << "eu        " << root << "o" << std::endl;
                std::cout << "tu        " << root << "es" << std::endl;
                std::cout << "ele/ela   " << root << "e" << std::endl;
                std::cout << "n" << ((char)243) << "s       " << root << "emos" << std::endl;
                std::cout << "v" << ((char)243) << "s       " << root << "eis" << std::endl;
                std::cout << "eles/elas " << root << "em" << std::endl;            
            }
            else if (good_verb[0] == 'i')
            {
                std::cout << "eu        " << root << "o" << std::endl;
                std::cout << "tu        " << root << "es" << std::endl;
                std::cout << "ele/ela   " << root << "e" << std::endl;
                std::cout << "n" << ((char)243) << "s       " << root << "imos" << std::endl;
                std::cout << "v" << ((char)243) << "s       " << root << "is" << std::endl;
                std::cout << "eles/elas " << root << "em" << std::endl;
            }
            else
            {
                printf("Unknown conjugation\n");
            }
        }
        else
        {
            printf("Unknown conjugation\n");
        }

        case_id++;
    }

    return 0;
}
