#include <iostream>
#include <map>
#include <string>
#include <stdio.h>

int main(int argc, char* argv[])
{
    std::map<std::string, std::string> language_detection_map;
    language_detection_map["HELLO"] = "ENGLISH";
    language_detection_map["HOLA"] = "SPANISH";
    language_detection_map["HALLO"] = "GERMAN";
    language_detection_map["BONJOUR"] = "FRENCH";
    language_detection_map["CIAO"] = "ITALIAN";
    language_detection_map["ZDRAVSTVUJTE"] = "RUSSIAN";

    int case_id = 1;
    std::string hello;
    while (std::cin >> hello)
    {
        if (hello.compare("#") == 0)
        {
            break;
        }

        std::string language = language_detection_map[hello];
        if (language.empty())
        {
            language = "UNKNOWN";
        }
        std::cout << "Case " << case_id << ": " << language << std::endl;

        case_id++;
    }

    return 0;
}