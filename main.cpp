// =====================================================
// STORY 1 — Core & Constructors
// =====================================================

class BigInt {
    string number;
    bool isNegative;

    void removeLeadingZeros() {
        // TODO
    }

    int compareMagnitude(const BigInt& other) const {
        // TODO
        return 0;
    }

public:
    BigInt() {
        // TODO
    }

    BigInt(int64_t value) {
        // TODO
    }

    BigInt(const string& str) {
        // TODO
    }

    BigInt(const BigInt& other) {
        // TODO
    }

    ~BigInt() {
        // TODO
    }

    BigInt& operator=(const BigInt& other) {
        // TODO
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