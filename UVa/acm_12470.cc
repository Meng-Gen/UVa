// Wiki: http://en.wikipedia.org/wiki/Recurrence_relation
// Also http://en.wikipedia.org/wiki/Companion_matrix
// It is an elegant application of linear algebra.

#include <iostream>
#include <stdio.h>
#include <string.h>

struct Matrix
{
    long long m[3][3];

    Matrix()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                m[i][j] = (i == j) ? 1 : 0;
            }
        }
    }

    Matrix
    (
        long long a, long long b, long long c, 
        long long d, long long e, long long f,
        long long g, long long h, long long i
    )
    {
        m[0][0] = a;
        m[0][1] = b;
        m[0][2] = c;
        m[1][0] = d;
        m[1][1] = e;
        m[1][2] = f;
        m[2][0] = g;
        m[2][1] = h;
        m[2][2] = i;
    }

    Matrix multiply(const Matrix& other, long long mod)
    {
        Matrix rv;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                rv.m[i][j] = 0;
                for (int k = 0; k < 3; k++)
                {
                    rv.m[i][j] += ((m[i][k] * other.m[k][j]) % mod);
                    rv.m[i][j] %= mod;
                }
            }
        }
        return rv;
    }

    Matrix pow(long long n, long long mod)
    {
        Matrix rv;
        Matrix temp = *this;

        for (; n > 0; n >>= 1)
        {
            if (n & 1)
            {
                rv = rv.multiply(temp, mod);
            }
            temp = temp.multiply(temp, mod);
        }

        return rv;
    }
};

long long get_modular_fibonacci(long long n, long long m)
{
    if (n == 1) 
    {
        return 0;
    }
    else if (n == 2)
    {
        return 1;
    }
    else if (n == 3)
    {
        return 2;
    }
    Matrix characteristic_matrix = Matrix(1, 1, 1, 1, 0, 0, 0, 1, 0);
    Matrix rv = characteristic_matrix.pow(n - 3, m);
    return ((2 * rv.m[0][0]) % m + rv.m[0][1]) % m;    
}

int main(int argc, char* argv[])
{
    long long n;
    while (std::cin >> n && n)
    {
        std::cout << get_modular_fibonacci(n, 1000000009) << std::endl;
    }

    return 0;
}