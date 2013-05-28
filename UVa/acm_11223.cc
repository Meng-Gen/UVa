#include <iostream>
#include <map>
#include <string>
#include <stdio.h>

std::map<std::string, char> morse_code;

void InitMorseCode()
{
    std::string encoded[] = 
    {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
        ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
        "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----",
        ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.",
        ".-.-.-", "--..--", "..--..", ".----.", "-.-.--", "-..-.", "-.--.", "-.--.-", ".-...",
        "---...", "-.-.-.", "-...-", ".-.-.", "-....-", "..--.-", ".-..-.", ".--.-."
    };

    std::string decoded("ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,?'!/()&:;=+-_\"@");

    for (unsigned int i = 0; i < decoded.size(); i++)
    {
        morse_code[encoded[i]] = decoded[i];
    }
}

int main(int argc, char* argv[])
{
    InitMorseCode();

    int num_testcases;
    std::cin >> num_testcases;
    getchar();
    for (int case_id = 1; case_id <= num_testcases; case_id++)
    {
        if (case_id > 1)
        {
            putchar('\n');
        }

        printf("Message #%d\n", case_id);

        std::string message;
        getline(std::cin, message);

        char buffer[2005];
        int pos = 0;
        bool is_morse_phase = false;
        for (unsigned int i = 0; i < message.size(); i++)
        {
            if (is_morse_phase)
            {
                if (message[i] == '.' || message[i] == '-')
                {
                    buffer[pos] = message[i];
                    pos++;
                }
                else
                {
                    buffer[pos] = 0;
                    putchar(morse_code[buffer]);
                    pos = 0;
                    is_morse_phase = false;
                }
            }
            else
            {
                if (message[i] == '.' || message[i] == '-')
                {
                    buffer[pos] = message[i];
                    pos++;
                    is_morse_phase = true;
                }
                else
                {
                    putchar(' ');
                }
            }
        }

        if (is_morse_phase)
        {
            buffer[pos] = 0;
            putchar(morse_code[buffer]);
        }
        putchar('\n');
    }

    return 0;
}