#include <iostream>
#include <stdio.h>

class SimpleFraction 
{
public:
    long long numerator() { return m_; }
    long long denominator() { return n_; }

    SimpleFraction() : m_(0), n_(1) { }
    SimpleFraction(long long numerator, long long denominator) 
        : m_(numerator), n_(denominator) { }

    void Inverse() {
        long long t = m_;
        m_ = n_;
        n_ = t;
    }

    void Multiply(long long factor) {
        // Afraid of overflow
        long long gcd = GreatestCommonDivisor(factor, n_);
        m_ *= (factor / gcd);
        n_ /= gcd;
    }

    void Add(long long numerator, long long denominator) {
        long long gcd = GreatestCommonDivisor(n_, denominator);
        // Afraid of overflow
        m_ = denominator/gcd * m_ + n_/gcd * numerator;
        n_ = (n_ > denominator) ? n_/gcd * denominator : denominator/gcd * n_;
        Normalize();
    }

private:
    void Normalize() {
        long long gcd = GreatestCommonDivisor(m_, n_);
        m_ /= gcd;
        n_ /= gcd;
    }

    // Euclidean Algorithm
    static long long GreatestCommonDivisor(long long a, long long b) {
        while (b) {
            long long t = b;
            b = a % t;
            a = t;
        }
        return a;
    }

    long long m_;
    long long n_;
};

int main(int argc, char* argv[])
{
    int num_testcases; 
    std::cin >> num_testcases;
    getchar();
    for (int case_id = 1; case_id <= num_testcases; case_id++)
    {
        int N;
        std::cin >> N;

        SimpleFraction rv;
        for (int i = 0; i < N; i++)
        {
            long long a;
            std::cin >> a;
            rv.Add(1, a);
        }
        rv.Inverse();
        rv.Multiply(N);

        printf("Case %d: %lld/%lld\n", 
            case_id, rv.numerator(), rv.denominator());
    }
    return 0;
}