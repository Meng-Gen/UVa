#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>

int P[1000001];

// Knuth¡VMorris¡VPratt algorithm
int GetPower(const std::string& query)
{
    int length = query.size();

    memset(P, 0, 1000001);
	P[0] = -1;
    int j = -1;
    for (int i = 1; i < length; i++)
    {
		while(j >= 0 && query[j+1] != query[i])
        {
			j = P[j];
        }
        if (query[j+1] == query[i])
        {
			j++;
        }
		P[i] = j; 
	}

    int period = length - j - 1;
    if (length % period == 0)
    {
        return length / period;
    }
    return 1;
}

int main(int argc, char* argv[])
{
    std::string buffer;
    while (std::cin >> buffer && (buffer != "."))
    {
        std::cout << GetPower(buffer) << std::endl; 
    }
    return 0;
}