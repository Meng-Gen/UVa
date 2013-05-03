#include <iostream>
#include <sstream>
#include <string>
//#include <vector>

char buffer[50000];

// A ``word'' is defined as a consecutive sequence of letters 
// (upper and/or lower case).
int get_word_count()
{
	int count = 0;

	bool begin_word = false;
	for (int i = 0; buffer[i] != '\0'; i++)
	{
		if (begin_word)
		{
			if ((buffer[i] >= 'a' && buffer[i] <= 'z') ||
				(buffer[i] >= 'A' && buffer[i] <= 'Z'))
			{
				continue;
			}
			else
			{
				count++;
				begin_word = false;
			}
		}
		else 
		{
			if ((buffer[i] >= 'a' && buffer[i] <= 'z') ||
				(buffer[i] >= 'A' && buffer[i] <= 'Z'))
			{
				begin_word = true;
			}
		}
	}

	if (begin_word)
	{
		count++;
	}

	return count;
}

int main(int argc, char* argv[])
{
	while (std::cin.getline(buffer, 50000))
	{
		std::cout << get_word_count() << std::endl;
	}
	
	return 0;
}