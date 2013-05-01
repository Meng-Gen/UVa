#include <iostream>
#include <sstream>

// 50000 is a magic, lucky number.
char buffer[50000];

int main(int argc, char* argv[])
{
	bool begin_quotation = true;
    while(std::cin.getline(buffer, 50000))
    {
		std::stringstream string_builder;
		for (int i = 0; buffer[i] != 0; i++)
		{
			if (buffer[i] == '"')
			{
				string_builder << (begin_quotation ? "``" : "''");
				begin_quotation = !begin_quotation;
			}
			else
			{
				string_builder << buffer[i];
			}
		}
		std::cout << string_builder.str() << std::endl;
    }

    return 0;
}