// =====================================================
// STORY 1 — Core & Constructors
// =====================================================
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

using namespace std;

class BigInt
{
    string number;
    bool isNegative;

    void removeLeadingZeros()
    {
        // TODO
    }

    int compareMagnitude(const BigInt &other) const
    {
        // TOD
        return 0;
    }

public:
    BigInt()
    {
        // TODO
    }

    BigInt(int64_t value)
    {
        // TODO
    }

    BigInt(const string &str)
    {
        // TODO
    }

    BigInt(const BigInt &other)
    {
        // TODO
    }

    ~BigInt()
    {
        // TODO
    }

    BigInt &operator=(const BigInt &other)
    {
        // TODO
        return *this;
    }

    // =====================================================
    // STORY 2 — Unary & Comparison
    // =====================================================

    BigInt operator-() const
    {
        BigInt result;
        // TODO
        return result;
    }

    BigInt operator+() const
    {
        BigInt result;
        // TODO
        return result;
    }

    // =====================================================
    // STORY 3 — Addition & Subtraction
    // =====================================================

    BigInt &operator+=(const BigInt &other)
    {
        // TODO
        return *this;
    }

    BigInt &operator-=(const BigInt &other)
    {
        // TODO
        return *this;
    }

    // =====================================================
    // STORY 4 — Multiplication
    // =====================================================

    BigInt &operator*=(const BigInt &other)
    {

        if (number == "0" || other.number == "0")
        {
            number = "0";
            isNegative = false;
            return *this;
        }

        int n = number.size();
        int m = other.number.size();

        vector<int> result(n + m, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {

                int digit1 = number[i] - '0';
                int digit2 = other.number[j] - '0';

                result[i + j + 1] += digit1 * digit2;
            }
        }

        for (int i = n + m - 1; i > 0; i--)
        {
            result[i - 1] += result[i] / 10;
            result[i] %= 10;
        }

        string newNumber;
        int start = 0;

        while (start < n + m - 1 && result[start] == 0)
        {
            start++;
        }

        for (int i = start; i < n + m; i++)
        {
            newNumber += char(result[i] + '0');
        }

        number = newNumber;

        isNegative = isNegative != other.isNegative;

        if (number == "0")
        {
            isNegative = false;
        }

        return *this;
    }

    // =====================================================
    // STORY 5 — Division & Modulus
    // =====================================================

    BigInt &operator/=(const BigInt &other)
    {
        // TODO
        return *this;
    }

    BigInt &operator%=(const BigInt &other)
    {
        // TODO
        return *this;
    }

    // =====================================================
    // STORY 6 — Increment, Decrement & I/O
    // =====================================================

    BigInt &operator++()
    {
        // TODO
        return *this;
    }

    BigInt operator++(int)
    {
        BigInt temp;
        // TODO
        return temp;
    }

    BigInt &operator--()
    {
        // TODO
        return *this;
    }

    BigInt operator--(int)
    {
        BigInt temp;
        // TODO
        return temp;
    }

    string toString() const
    {
        // TODO
        return "";
    }

    friend ostream &operator<<(ostream &os, const BigInt &num)
    {
        // TODO
        return os;
    }

    friend istream &operator>>(istream &is, BigInt &num)
    {
        // TODO
        return is;
    }

    friend bool operator==(const BigInt &lhs, const BigInt &rhs);
    friend bool operator<(const BigInt &lhs, const BigInt &rhs);
};

// =====================================================
// STORY 3 — Addition & Subtraction
// =====================================================

BigInt operator+(BigInt lhs, const BigInt &rhs)
{
    BigInt result;
    // TODO
    return result;
}

BigInt operator-(BigInt lhs, const BigInt &rhs)
{
    BigInt result;
    // TODO
    return result;
}

// =====================================================
// STORY 4 — Multiplication
// =====================================================

BigInt operator*(BigInt lhs, const BigInt &rhs)
{
    lhs *= rhs;
    return lhs;
}
// =====================================================
// STORY 5 — Division & Modulus
// =====================================================

BigInt operator/(BigInt lhs, const BigInt &rhs)
{
    BigInt result;
    // TODO
    return result;
}

BigInt operator%(BigInt lhs, const BigInt &rhs)
{
    BigInt result;
    // TODO
    return result;
}

// =====================================================
// STORY 2 — Unary & Comparison
// =====================================================

bool operator==(const BigInt &lhs, const BigInt &rhs)
{
    // TODO
    return false;
}

bool operator!=(const BigInt &lhs, const BigInt &rhs)
{
    // TODO
    return false;
}

bool operator<(const BigInt &lhs, const BigInt &rhs)
{
    // TODO
    return false;
}

bool operator<=(const BigInt &lhs, const BigInt &rhs)
{
    // TODO
    return false;
}

bool operator>(const BigInt &lhs, const BigInt &rhs)
{
    // TODO
    return false;
}

bool operator>=(const BigInt &lhs, const BigInt &rhs)
{
    // TODO
    return false;
}

int main()
{
    // Tests
    return 0;
}