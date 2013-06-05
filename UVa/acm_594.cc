#include <stdio.h>

int main(int argc, char* argv[])
{
    int L;
    while (scanf("%d", &L) == 1)
    {
        int B = ((L << 8) & 0xFF00FF00) | ((L >> 8) & 0xFF00FF); 
        B = (B << 16) | ((B >> 16) & 0xFFFF);
        printf("%d converts to %d\n", L, B);
    }
    return 0;
}