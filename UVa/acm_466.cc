#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>

template <class T>
inline T to_type(const std::string& s) {
    std::stringstream builder(s);
    T t;
    builder >> t;
    return t;
}

// -----------------------------------------------------------------------------

int N;

char rotation[4][12][12] = {};
char reflection[4][12][12] = {};
char dest[12][12] = {};

void BuildRotation()
{
    for (int d = 1; d < 4; d++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                rotation[d][j][N-1-i] = rotation[d-1][i][j];
            }
        }
    }
}

void BuildReflection()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            reflection[0][N-1-i][j] = rotation[0][i][j];
        }
    }
    for (int d = 1; d < 4; d++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                reflection[d][j][N-1-i] = reflection[d-1][i][j];
            }
        }
    }
}

// -----------------------------------------------------------------------------

bool IsRotated(int degree)
{
    int which = degree/90;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (dest[i][j] != rotation[which][i][j])
            {
                return false;
            }
        }
    }
    return true;
}

bool IsReflectedThenRotated(int degree)
{
    int which = degree/90;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (dest[i][j] != reflection[which][i][j])
            {
                return false;
            }
        }
    }
    return true;
}

void PrintSolution(int case_id)
{
    if (IsRotated(0))
    {
        printf("Pattern %d was preserved.\n", case_id);
    }
    else if (IsRotated(90))
    {
        printf("Pattern %d was rotated 90 degrees.\n", case_id);
    }
    else if (IsRotated(180))
    {
        printf("Pattern %d was rotated 180 degrees.\n", case_id);
    }
    else if (IsRotated(270))
    {
        printf("Pattern %d was rotated 270 degrees.\n", case_id);
    }
    else if (IsReflectedThenRotated(0))
    {
        printf("Pattern %d was reflected vertically.\n", case_id);
    }
    else if (IsReflectedThenRotated(90))
    {
        printf("Pattern %d was reflected vertically and rotated 90 degrees.\n", case_id);
    }
    else if (IsReflectedThenRotated(180))
    {
        printf("Pattern %d was reflected vertically and rotated 180 degrees.\n", case_id);
    }
    else if (IsReflectedThenRotated(270))
    {
        printf("Pattern %d was reflected vertically and rotated 270 degrees.\n", case_id);
    }
    else
    {
        printf("Pattern %d was improperly transformed.\n", case_id);
    }
}

// -----------------------------------------------------------------------------

int main(int argc, char* argv[])
{
    int case_id = 1;
    std::string buffer;
    while (getline(std::cin, buffer))
    {
        N = to_type<int>(buffer);
        for (int i = 0; i < N; i++)
        {
            getline(std::cin, buffer);
            for (int j = 0; j < N; j++)
            {
                rotation[0][i][j] = buffer[j];
            }
            for (int j = 0; j < N; j++)
            {
                dest[i][j] = buffer[j+N+1];
            }
        }
        BuildRotation();
        BuildReflection();
        PrintSolution(case_id);
        case_id++;
    }
    return 0;
}