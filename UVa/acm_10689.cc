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

long long get_modular_fibonacci(int a, int b, int n, int m)
{
    int module = 1;
    for (int i = 0; i < m; i++)
    {
        module *= 10;
    }

    Matrix initial_value = Matrix(b+a, b, b, a);
    if (n == 0)
    {
        return a % module;
    }
    else if (n == 1)
    {
        return b % module;
    }
    else if (n == 2)
    {
        return (a+b) % module;
    }
    Matrix characteristic_matrix = Matrix(1, 1, 1, 0);
    Matrix rv = characteristic_matrix.pow(n - 2, module);
    rv = rv.multiply(initial_value, module);
    return rv.m[0][0] % module;
}

int main(int argc, char* argv[])
{
    int testcase_count;
    std::cin >> testcase_count;

    for (int case_id = 0; case_id < testcase_count; case_id++)
    {
        int a;
        int b;
        int n;
        int m;
        std::cin >> a >> b >> n >> m;
        std::cout << get_modular_fibonacci(a, b, n, m) << std::endl;
    }

    return 0;
}