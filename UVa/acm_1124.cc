#include <iostream>
#include <stdio.h>

char buffer[50000];

int main(int argc, char* argv[])
{
    while (gets(buffer))
    {
        puts(buffer);
    }
}