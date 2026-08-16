#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <stdexcept>

using namespace std;

// =====================================================
// STORY 1 — Core & Constructors
// =====================================================

class BigInt
{
    string number;
    bool isNegative;

    void removeLeadingZeros()
    {
        size_t count = 0;

        while (count < number.size() && number[count] == '0')
        {
            count++;
        }

        number.erase(0, count);

        if (number.empty())
        {
            number = "0";
        }

        if (number == "0")
        {
            isNegative = false;
        }
    }

    int compareMagnitude(const BigInt& other) const
    {
        if (number.size() > other.number.size())
        {
            return 1;
        }

        if (number.size() < other.number.size())
        {
            return -1;
        }

        if (number > other.number)
        {
            return 1;
        }

        if (number < other.number)
        {
            return -1;
        }

        return 0;
    }

public:
    // =====================================================
    // Constructors
    // =====================================================

    BigInt()
    {
        number = "0";
        isNegative = false;
    }

    BigInt(int64_t value)
    {
        if (value < 0)
        {
            isNegative = true;

            // Handle INT64_MIN safely
            if (value == INT64_MIN)
            {
                number = "9223372036854775808";
            }
            else
            {
                number = to_string(-value);
            }
        }
        else
        {
            isNegative = false;
            number = to_string(value);
        }
    }

    BigInt(const string& str)
    {
        if (str.empty())
        {
            number = "0";
            isNegative = false;
            return;
        }

        if (str[0] == '-')
        {
            isNegative = true;
            number = str.substr(1);
        }
        else
        {
            isNegative = false;
            number = str;
        }

        removeLeadingZeros();
    }

    BigInt(const BigInt& other)
    {
        number = other.number;
        isNegative = other.isNegative;
    }

    ~BigInt()
    {
    }

    BigInt& operator=(const BigInt& other)
    {
        if (this == &other)
        {
            return *this;
        }

        number = other.number;
        isNegative = other.isNegative;

        return *this;
    }

    // =====================================================
    // STORY 2 — Unary & Comparison
    // =====================================================

    BigInt operator-() const
    {
        BigInt result;

        result.number = number;
        result.isNegative = isNegative;

        if (result.number != "0")
        {
            result.isNegative = !result.isNegative;
        }

        return result;
    }

    BigInt operator+() const
    {
        BigInt result;

        result.number = number;
        result.isNegative = isNegative;

        return result;
    }

    // =====================================================
    // STORY 3 — Addition & Subtraction
    // =====================================================

    BigInt& operator+=(const BigInt& other)
    {
        if (isNegative == other.isNegative)
        {
            string result = "";
            int carry = 0;

            int i = static_cast<int>(number.length()) - 1;
            int j = static_cast<int>(other.number.length()) - 1;

            while (i >= 0 || j >= 0 || carry != 0)
            {
                int digit1 = 0;
                int digit2 = 0;

                if (i >= 0)
                {
                    digit1 = number[i] - '0';
                }

                if (j >= 0)
                {
                    digit2 = other.number[j] - '0';
                }

                int sum = digit1 + digit2 + carry;

                result = char('0' + (sum % 10)) + result;

                carry = sum / 10;

                i--;
                j--;
            }

            number = result;
        }
        else
        {
            int comparison = compareMagnitude(other);

            if (comparison == 0)
            {
                number = "0";
                isNegative = false;
            }
            else if (comparison > 0)
            {
                string result = "";
                int borrow = 0;

                int i = static_cast<int>(number.length()) - 1;
                int j = static_cast<int>(other.number.length()) - 1;

                while (i >= 0)
                {
                    int digit1 = number[i] - '0';
                    int digit2 = 0;

                    if (j >= 0)
                    {
                        digit2 = other.number[j] - '0';
                    }

                    int difference = digit1 - digit2 - borrow;

                    if (difference < 0)
                    {
                        difference += 10;
                        borrow = 1;
                    }
                    else
                    {
                        borrow = 0;
                    }

                    result = char('0' + difference) + result;

                    i--;
                    j--;
                }

                number = result;
            }
            else
            {
                string result = "";
                int borrow = 0;

                int i = static_cast<int>(other.number.length()) - 1;
                int j = static_cast<int>(number.length()) - 1;

                while (i >= 0)
                {
                    int digit1 = other.number[i] - '0';
                    int digit2 = 0;

                    if (j >= 0)
                    {
                        digit2 = number[j] - '0';
                    }

                    int difference = digit1 - digit2 - borrow;

                    if (difference < 0)
                    {
                        difference += 10;
                        borrow = 1;
                    }
                    else
                    {
                        borrow = 0;
                    }

                    result = char('0' + difference) + result;

                    i--;
                    j--;
                }

                number = result;
                isNegative = other.isNegative;
            }
        }

        removeLeadingZeros();

        return *this;
    }

    BigInt& operator-=(const BigInt& other)
    {
        if (isNegative != other.isNegative)
        {
            BigInt temp = other;

            temp.isNegative = !temp.isNegative;

            *this += temp;

            return *this;
        }

        int comparison = compareMagnitude(other);

        if (comparison == 0)
        {
            number = "0";
            isNegative = false;

            return *this;
        }
        else if (comparison > 0)
        {
            string result = "";
            int borrow = 0;

            int i = static_cast<int>(number.length()) - 1;
            int j = static_cast<int>(other.number.length()) - 1;

            while (i >= 0)
            {
                int digit1 = number[i] - '0';
                int digit2 = 0;

                if (j >= 0)
                {
                    digit2 = other.number[j] - '0';
                }

                int difference = digit1 - digit2 - borrow;

                if (difference < 0)
                {
                    difference += 10;
                    borrow = 1;
                }
                else
                {
                    borrow = 0;
                }

                result = char('0' + difference) + result;

                i--;
                j--;
            }

            number = result;
        }
        else
        {
            string result = "";
            int borrow = 0;

            int i = static_cast<int>(other.number.length()) - 1;
            int j = static_cast<int>(number.length()) - 1;

            while (i >= 0)
            {
                int digit1 = other.number[i] - '0';
                int digit2 = 0;

                if (j >= 0)
                {
                    digit2 = number[j] - '0';
                }

                int difference = digit1 - digit2 - borrow;

                if (difference < 0)
                {
                    difference += 10;
                    borrow = 1;
                }
                else
                {
                    borrow = 0;
                }

                result = char('0' + difference) + result;

                i--;
                j--;
            }

            number = result;
            isNegative = !isNegative;
        }

        removeLeadingZeros();

        return *this;
    }

    // =====================================================
    // STORY 4 — Multiplication
    // =====================================================

    BigInt& operator*=(const BigInt& other)
    {
        if (number == "0" || other.number == "0")
        {
            number = "0";
            isNegative = false;

            return *this;
        }

        int n = static_cast<int>(number.size());
        int m = static_cast<int>(other.number.size());

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

        removeLeadingZeros();

        return *this;
    }

    // =====================================================
    // STORY 5 — Division & Modulus
    // =====================================================

    BigInt& operator/=(const BigInt& other)
    {
        if (other.number == "0")
        {
            throw runtime_error("Division by zero");
        }

        if (number == "0")
        {
            return *this;
        }

        bool resultNegative = (isNegative != other.isNegative);

        BigInt dividend(*this);
        BigInt divisor(other);

        dividend.isNegative = false;
        divisor.isNegative = false;

        if (dividend.compareMagnitude(divisor) < 0)
        {
            number = "0";
            isNegative = false;

            return *this;
        }

        BigInt quotient(0);
        BigInt current(0);

        for (size_t i = 0; i < dividend.number.size(); i++)
        {
            current.number += dividend.number[i];
            current.removeLeadingZeros();

            int digit = 0;

            while (current.compareMagnitude(divisor) >= 0)
            {
                current -= divisor;
                digit++;
            }

            quotient.number += char('0' + digit);
        }

        quotient.removeLeadingZeros();

        quotient.isNegative = resultNegative;

        if (quotient.number == "0")
        {
            quotient.isNegative = false;
        }

        *this = quotient;

        return *this;
    }

    BigInt& operator%=(const BigInt& other)
    {
        if (other.number == "0")
        {
            throw runtime_error("Division by zero");
        }

        if (number == "0")
        {
            return *this;
        }

        bool originalSign = isNegative;

        BigInt dividend(*this);
        BigInt divisor(other);

        dividend.isNegative = false;
        divisor.isNegative = false;

        if (dividend.compareMagnitude(divisor) < 0)
        {
            // Magnitude is already the remainder.
            // Keep the sign of the dividend.
            isNegative = originalSign;

            removeLeadingZeros();

            return *this;
        }

        BigInt current(0);

        for (size_t i = 0; i < dividend.number.size(); i++)
        {
            current.number += dividend.number[i];
            current.removeLeadingZeros();

            while (current.compareMagnitude(divisor) >= 0)
            {
                current -= divisor;
            }
        }

        current.removeLeadingZeros();

        current.isNegative = originalSign;

        if (current.number == "0")
        {
            current.isNegative = false;
        }

        *this = current;

        return *this;
    }

    // =====================================================
    // STORY 6 — Increment, Decrement & I/O
    // =====================================================

    BigInt& operator++()
    {
        *this += BigInt(1);

        return *this;
    }

    BigInt operator++(int)
    {
        BigInt temp = *this;

        ++(*this);

        return temp;
    }

    BigInt& operator--()
    {
        *this -= BigInt(1);

        return *this;
    }

    BigInt operator--(int)
    {
        BigInt temp = *this;

        --(*this);

        return temp;
    }

    string toString() const
    {
        if (isNegative && number != "0")
        {
            return "-" + number;
        }

        return number;
    }

    friend ostream& operator<<(ostream& os, const BigInt& num)
    {
        os << num.toString();

        return os;
    }

    friend istream& operator>>(istream& is, BigInt& num)
    {
        string token;

        if (is >> token)
        {
            BigInt temp(token);

            num = temp;
        }

        return is;
    }

    friend bool operator==(const BigInt& lhs, const BigInt& rhs);
    friend bool operator<(const BigInt& lhs, const BigInt& rhs);
};

// =====================================================
// STORY 3 — Addition & Subtraction
// =====================================================

BigInt operator+(BigInt lhs, const BigInt& rhs)
{
    lhs += rhs;

    return lhs;
}

BigInt operator-(BigInt lhs, const BigInt& rhs)
{
    lhs -= rhs;

    return lhs;
}

// =====================================================
// STORY 4 — Multiplication
// =====================================================

BigInt operator*(BigInt lhs, const BigInt& rhs)
{
    lhs *= rhs;

    return lhs;
}

// =====================================================
// STORY 5 — Division & Modulus
// =====================================================

BigInt operator/(BigInt lhs, const BigInt& rhs)
{
    lhs /= rhs;

    return lhs;
}

BigInt operator%(BigInt lhs, const BigInt& rhs)
{
    lhs %= rhs;

    return lhs;
}

// =====================================================
// STORY 2 — Unary & Comparison
// =====================================================

bool operator==(const BigInt& lhs, const BigInt& rhs)
{
    if (lhs.isNegative != rhs.isNegative)
    {
        return false;
    }

    return lhs.number == rhs.number;
}

bool operator!=(const BigInt& lhs, const BigInt& rhs)
{
    return !(lhs == rhs);
}

bool operator<(const BigInt& lhs, const BigInt& rhs)
{
    // Negative < Positive
    if (lhs.isNegative && !rhs.isNegative)
    {
        return true;
    }

    // Positive > Negative
    if (!lhs.isNegative && rhs.isNegative)
    {
        return false;
    }

    // Both positive
    if (!lhs.isNegative && !rhs.isNegative)
    {
        return lhs.compareMagnitude(rhs) < 0;
    }

    // Both negative:
    // Larger magnitude means smaller value.
    return lhs.compareMagnitude(rhs) > 0;
}

bool operator<=(const BigInt& lhs, const BigInt& rhs)
{
    return (lhs < rhs) || (lhs == rhs);
}

bool operator>(const BigInt& lhs, const BigInt& rhs)
{
    return !(lhs <= rhs);
}

bool operator>=(const BigInt& lhs, const BigInt& rhs)
{
    return !(lhs < rhs);
}

// =====================================================
// MAIN — SRS TESTS
// =====================================================

int main()
{
    // =====================================================
    // TEST 1 — Constructors and Output
    // =====================================================

    BigInt a(12345);
    BigInt b("-67890");
    BigInt c(0);
    BigInt d(a);

    cout << "a (from int): " << a << endl;
    cout << "b (from string): " << b << endl;
    cout << "c (zero): " << c << endl;
    cout << "d (copy of a): " << d << endl;

    cout << endl;

    // =====================================================
    // TEST 2 — Arithmetic Operations
    // =====================================================

    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * b = " << a * b << endl;
    cout << "b / a = " << b / a << endl;
    cout << "a % 100 = " << a % BigInt(100) << endl;

    cout << endl;

    // =====================================================
    // TEST 3 — Relational Operators
    // =====================================================

    cout << "a == d: " << (a == d) << endl;
    cout << "a != b: " << (a != b) << endl;
    cout << "a < b: " << (a < b) << endl;
    cout << "a > b: " << (a > b) << endl;
    cout << "c == 0: " << (c == BigInt(0)) << endl;

    cout << endl;

    // =====================================================
    // TEST 4 — Unary and Increment/Decrement
    // =====================================================

    cout << "-a: " << -a << endl;

    ++a;
    cout << "++a: " << a << endl;

    cout << "a--: " << a-- << endl;
    cout << "a after decrement: " << a << endl;

    cout << endl;

    // =====================================================
    // TEST 5 — Large Number Operations
    // =====================================================
    BigInt large1("12345678901234567890");
    BigInt large2("98765432109876543210");

    cout << "Very large addition: "
        << large1 + large2 << endl;

    cout << "Very large multiplication: "
        << large1 * large2 << endl;

    cout << endl;

    // =====================================================
    // TEST 6 — Edge Cases
    // =====================================================

    try
    {
        BigInt x(10);
        BigInt zero(0);

        cout << x / zero << endl;
    }
    catch (const runtime_error& e)
    {
        cout << "Division by zero correctly threw error: "
            << e.what() << endl;
    }

    cout << "Multiplication by zero: "
        << BigInt(123456) * BigInt(0) << endl;

    cout << "Negative multiplication: "
        << BigInt(-3) * BigInt(5) << endl;

    cout << "Negative division: "
        << BigInt(-10) / BigInt(3) << endl;

    cout << "Negative modulus: "
        << BigInt(-10) % BigInt(3) << endl;

    return 0;
}