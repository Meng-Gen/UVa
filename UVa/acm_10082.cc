#include <iostream>
#include <map>

char buffer[50000];
char keyboard[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int main(int argc, char* argv[])
{
	std::map<char, char> keyboard_map;
	for (int i = 1; i < sizeof(keyboard); i++)
	{
		keyboard_map[keyboard[i]] = keyboard[i - 1];
	}
	keyboard_map[' '] = ' ';

	while(std::cin.getline(buffer, 50000))
	{
		int i = 0;
		while (buffer[i])
		{
			std::cout << keyboard_map[buffer[i]];
			i++;
		}
		std::cout << std::endl;
	}

	return 0;
}