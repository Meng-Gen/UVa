#include <iostream>
#include <string>
#include <stdio.h>

inline void GenerateHeader()
{
    puts("#include<string.h>");
    puts("#include<stdio.h>");
    puts("int main()");
    puts("{");    
}

inline void GenerateFooter()
{
    puts("printf(\"\\n\");");
    puts("return 0;");
    puts("}");
}

inline void GeneratePrintFormat(const std::string& content)
{
    printf("printf(\"");
    for (std::string::const_iterator it = content.begin();
        it != content.end(); it++)
    {
        if (*it == '\\')
        {
            putchar('\\');
        }
        else if (*it == '\"')
        {
            putchar('\\');
        }
        putchar(*it);
    }
    printf("\\n\");\n");
}

int main(int argc, char* argv[])
{
    int case_id = 1;
    int N;
    std::string buffer;
    while (std::cin >> N && N)
    {
        printf("Case %d:\n", case_id); 
        case_id++;

        GenerateHeader();
        for (int i = 0; i < N;)
        {
            getline(std::cin, buffer);
            if (buffer.size())
            {
                GeneratePrintFormat(buffer);
                i++;
            }
        }
        GenerateFooter();
    }
    return 0;
}