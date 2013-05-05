#include <iostream>
#include <stdio.h>

struct Matrix
{
    long long m[2][2];

    Matrix()
    {
        m[0][0] = 1;
        m[0][1] = 0;
        m[1][0] = 0;
        m[1][1] = 1;
    }

    Matrix(long long a, long long b, long long c, long long d)
    {
        m[0][0] = a;
        m[0][1] = b;
        m[1][0] = c;
        m[1][1] = d;  
    }

    Matrix multiply(const Matrix& other, long long mod)
    {
        Matrix rv;
        rv.m[0][0] = ((m[0][0] * other.m[0][0]) % mod + 
                      (m[0][1] * other.m[1][0]) % mod) % mod;
        rv.m[0][1] = ((m[0][0] * other.m[0][1]) % mod + 
                      (m[0][1] * other.m[1][1]) % mod) % mod;
        rv.m[1][0] = ((m[1][0] * other.m[0][0]) % mod + 
                      (m[1][1] * other.m[1][0]) % mod) % mod;
        rv.m[1][1] = ((m[1][0] * other.m[0][1]) % mod + 
                      (m[1][1] * other.m[1][1]) % mod) % mod;
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

long long get_modular_fibonacci(int n, int m)
{
    if (n == 0)
    {
        return 0LL;
    }
    Matrix a = Matrix(1, 1, 1, 0);
    Matrix a_power_n = a.pow(n - 1, 1 << m);
    return a_power_n.m[0][0] % (1 << m);
}

int main(int argc, char* argv[])
{
    int n;
    int m;
    while (std::cin >> n >> m)
    {
        std::cout << get_modular_fibonacci(n, m) << std::endl;
	}

	return 0;
}