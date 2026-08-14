#include <iostream>
#include <string>
#include<cstdint>
using namespace std;

// =====================================================
// STORY 1 — Core & Constructors
// =====================================================

class BigInt {
    string number;
    bool isNegative;

   void removeLeadingZeros() {
    size_t count = 0;
    while (count < number.size() && number[count] == '0') {
        count++;
    }
    number.erase(0, count);
    
    if (number.empty()) {
        number = "0";
    }
    
    if (number == "0") {
        isNegative = false;
    }
}

    int compareMagnitude(const BigInt& other) const {
    if (number.size() > other.number.size()) {
        return 1;
    }
    if (number.size() < other.number.size()) {
        return -1;
    }
    if (number > other.number) {
        return 1;
    }
    if (number < other.number) {
        return -1;
    }
    return 0;
}

public:
    BigInt() {
        number="0";
        isNegative=false;
    }

   BigInt(int64_t value) {
    if (value < 0) {
        isNegative = true;
        number = to_string(value * -1);
    } else {
        isNegative = false;
        number = to_string(value);
    }
}

    BigInt(const string& str) {
    if (str[0] == '-') {
        isNegative = true;
        number = str.substr(1);
    } else {
        isNegative = false;
        number = str;
    }
    removeLeadingZeros();
}

   BigInt(const BigInt& other) {
    number = other.number;
    isNegative = other.isNegative;
}

    ~BigInt() {
        
    }

   BigInt& operator=(const BigInt& other) {
    if (this == &other) return *this;
    
    number = other.number;
    isNegative = other.isNegative;
    
    return *this;
}


    // =====================================================
    // STORY 2 — Unary & Comparison
    // =====================================================

    BigInt operator-() const {
        BigInt result;
        // TODO
        return result;
    }

    BigInt operator+() const {
        BigInt result;
        // TODO
        return result;
    }


    // =====================================================
    // STORY 3 — Addition & Subtraction
    // =====================================================

    BigInt& operator+=(const BigInt& other) {
        // TODO
        return *this;
    }

    BigInt& operator-=(const BigInt& other) {
        // TODO
        return *this;
    }


    // =====================================================
    // STORY 4 — Multiplication
    // =====================================================

    BigInt& operator*=(const BigInt& other) {
        // TODO
        return *this;
    }


    // =====================================================
    // STORY 5 — Division & Modulus
    // =====================================================

    BigInt& operator/=(const BigInt& other) {
        // TODO
        return *this;
    }

    BigInt& operator%=(const BigInt& other) {
        // TODO
        return *this;
    }


    // =====================================================
    // STORY 6 — Increment, Decrement & I/O
    // =====================================================

    BigInt& operator++() {
        // TODO
        return *this;
    }

    BigInt operator++(int) {
        BigInt temp;
        // TODO
        return temp;
    }

    BigInt& operator--() {
        // TODO
        return *this;
    }

    BigInt operator--(int) {
        BigInt temp;
        // TODO
        return temp;
    }

    string toString() const {
        // TODO
        return "";
    }

    friend ostream& operator<<(ostream& os, const BigInt& num) {
        // TODO
        return os;
    }

    friend istream& operator>>(istream& is, BigInt& num) {
        // TODO
        return is;
    }

    friend bool operator==(const BigInt& lhs, const BigInt& rhs);
    friend bool operator<(const BigInt& lhs, const BigInt& rhs);
};


// =====================================================
// STORY 3 — Addition & Subtraction
// =====================================================

BigInt operator+(BigInt lhs, const BigInt& rhs) {
    BigInt result;
    // TODO
    return result;
}

BigInt operator-(BigInt lhs, const BigInt& rhs) {
    BigInt result;
    // TODO
    return result;
}


// =====================================================
// STORY 4 — Multiplication
// =====================================================

BigInt operator*(BigInt lhs, const BigInt& rhs) {
    BigInt result;
    // TODO
    return result;
}


// =====================================================
// STORY 5 — Division & Modulus
// =====================================================

BigInt operator/(BigInt lhs, const BigInt& rhs) {
    BigInt result;
    // TODO
    return result;
}

BigInt operator%(BigInt lhs, const BigInt& rhs) {
    BigInt result;
    // TODO
    return result;
}


// =====================================================
// STORY 2 — Unary & Comparison
// =====================================================

bool operator==(const BigInt& lhs, const BigInt& rhs) {
    // TODO
    return false;
}

bool operator!=(const BigInt& lhs, const BigInt& rhs) {
    // TODO
    return false;
}

bool operator<(const BigInt& lhs, const BigInt& rhs) {
    // TODO
    return false;
}

bool operator<=(const BigInt& lhs, const BigInt& rhs) {
    // TODO
    return false;
}

bool operator>(const BigInt& lhs, const BigInt& rhs) {
    // TODO
    return false;
}

bool operator>=(const BigInt& lhs, const BigInt& rhs) {
    // TODO
    return false;
}


int main() {
    // Tests
    return 0;
}