#include <iostream>
#include <stdio.h>

int minimum(int a, int b)
{
    return (a < b) ? a : b;
}

struct Grade
{
    int term[2]; 
    int final;
    int attendance;  
    int class_test[3];

    int GetMinClassTest()
    {
        int rv = class_test[0];
        rv = minimum(rv, class_test[1]);
        rv = minimum(rv, class_test[2]);
        return rv;
    }

    char GetGrade()
    {
        int class_test_marks = 0;
        for (int i = 0; i < 3; i++)
        {
            class_test_marks += class_test[i];
        }
        class_test_marks -= GetMinClassTest();

        int marks = term[0] + term[1] + final + attendance + 
            class_test_marks / 2;

        if (marks >= 90)
        {
            return 'A';
        }
        if (marks >= 80)
        {
            return 'B';
        }
        if (marks >= 70)
        {
            return 'C';
        }
        if (marks >= 60)
        {
            return 'D';
        }
        return 'F';
    }
};

int main(int argc, char* argv[])
{
    int num_testcases;
    std::cin >> num_testcases;
    for (int case_id = 1; case_id <= num_testcases; case_id++)
    {
        Grade g;
        std::cin >> g.term[0] >> g.term[1] >> g.final >> g.attendance >> 
            g.class_test[0] >> g.class_test[1] >> g.class_test[2];

        printf("Case %d: %c\n", case_id, g.GetGrade());
    }
    return 0;
}