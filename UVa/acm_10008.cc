#include <algorithm>
#include <iostream>
#include <string>
#include <stdio.h>

char buffer[50000];

bool compare_on_letter_count(std::pair<char, int> lhs, std::pair<char, int> rhs)
{	
	if (lhs.second > rhs.second)
	{
		return true;
	}
	if (lhs.second < rhs.second)
	{
		return false;
	}
	if (lhs.first < rhs.first) 
	{
		return true;
	}
	return false;
}

int main(int argc, char* argv[])
{
	std::pair<char, int> LetterCount[26];
	for (int i = 0; i < 26; i++)
	{
		LetterCount[i].first = 'A' + i;
		LetterCount[i].second = 0;
	}

	int N;
	std::cin >> N;
	getchar();
	for (int i = 0; i < N; i++)
	{
		std::cin.getline(buffer, 50000);
		for (int j = 0; buffer[j] != '\0'; j++)
		{
			if (buffer[j] >= 'a' && buffer[j] <= 'z')
			{
				LetterCount[buffer[j] - 'a'].second++;
			}
			else if (buffer[j] >= 'A' && buffer[j] <= 'Z')
			{
				LetterCount[buffer[j] - 'A'].second++;
			}
		}
	}

	std::sort(LetterCount, LetterCount + 26, compare_on_letter_count);
	
	for (int i = 0; i < 26; i++)
	{
		// If a letter does not appear in the text, 
		// then that letter must not appear in the output.
		if (LetterCount[i].second == 0)
		{
			break;
		}
		std::cout << LetterCount[i].first << " " << LetterCount[i].second << std::endl;
	}

	return 0;
}