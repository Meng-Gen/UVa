#include <iostream>
#include <math.h>
#include <stdio.h>

long long size, pos;
long long line = 0;
long long column = 0;

long long GetSizeLength(long long pos)
{
    long long len = (long long)sqrt(double(pos));
    if (len % 2 == 0)
    {
        len++;
    }
    if (len * len < pos)
    {
        len += 2;
    }
    return len;
}

void Calculate()
{
    line = size/2 + 1;
    column = size/2 + 1;
    if (pos == 1)
    {
        return;
    }
    long long side_len = GetSizeLength(pos);
    long long prev_square = (side_len - 2)*(side_len - 2);
    long long which_side = (pos - prev_square - 1)/(side_len - 1);
    long long prev_pos = prev_square + which_side * (side_len - 1);

    if (which_side == 0)
    {
        line = line + side_len/2;
        column = column + side_len/2 - pos + prev_pos;
    }
    else if (which_side == 1)
    {
        line = line + side_len/2 - pos + prev_pos;
        column = column - side_len/2;
    }
    else if (which_side == 2)
    {
        line = line - side_len/2;
        column = column - side_len/2 + pos - prev_pos;
    }
    else if (which_side == 3)
    {
        line = line - side_len/2 + pos - prev_pos;
        column = column + side_len/2;
    }
}

void PrintSolution()
{
    printf("Line = %lld, column = %lld.\n", line, column);
}

int main(int argc, char* argv[])
{
    while (std::cin >> size >> pos && (size || pos))
    {
        Calculate();
        PrintSolution();
    }
    return 0;
}