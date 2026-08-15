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
        if (isNegative == other.isNegative) {

            string result = "";
            int carry = 0;

            int i = number.length() - 1;
            int j = other.number.length() - 1;

            while (i >= 0 || j >= 0 || carry != 0) {

                int digit1 = 0;
                int digit2 = 0;

                if (i >= 0) {
                    digit1 = number[i] - '0';
                }

                if (j >= 0) {
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

        else {

            int comparison = compareMagnitude(other);

            
            if (comparison == 0) {

                number = "0";
                isNegative = false;
            }

            
            else if (comparison > 0) {

                string result = "";
                int borrow = 0;

                int i = number.length() - 1;
                int j = other.number.length() - 1;

                while (i >= 0) {

                    int digit1 = number[i] - '0';
                    int digit2 = 0;

                    if (j >= 0) {
                        digit2 = other.number[j] - '0';
                    }

                    int difference = digit1 - digit2 - borrow;

                    if (difference < 0) {
                        difference += 10;
                        borrow = 1;
                    }
                    else {
                        borrow = 0;
                    }

                    result = char('0' + difference) + result;

                    i--;
                    j--;
                }

                number = result;
            }
            else {

                string result = "";
                int borrow = 0;

                int i = other.number.length() - 1;
                int j = number.length() - 1;

                while (i >= 0) {

                    int digit1 = other.number[i] - '0';
                    int digit2 = 0;

                    if (j >= 0) {
                        digit2 = number[j] - '0';
                    }

                    int difference = digit1 - digit2 - borrow;

                    if (difference < 0) {
                        difference += 10;
                        borrow = 1;
                    }
                    else {
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

   
        BigInt& operator-=(const BigInt & other) {

            
            if (isNegative != other.isNegative) {

                BigInt temp = other;

                
                temp.isNegative = !temp.isNegative;

                *this += temp;

                return *this;
            }

            
            int comparison = compareMagnitude(other);

            
            if (comparison == 0) {

                number = "0";
                isNegative = false;

                return *this;
            }

            
            else if (comparison > 0) {

                string result = "";
                int borrow = 0;

                int i = number.length() - 1;
                int j = other.number.length() - 1;

                while (i >= 0) {

                    int digit1 = number[i] - '0';
                    int digit2 = 0;

                    if (j >= 0) {
                        digit2 = other.number[j] - '0';
                    }

                    int difference = digit1 - digit2 - borrow;

                    if (difference < 0) {
                        difference += 10;
                        borrow = 1;
                    }
                    else {
                        borrow = 0;
                    }

                    result = char('0' + difference) + result;

                    i--;
                    j--;
                }

                number = result;
            }

            
            else {

                string result = "";
                int borrow = 0;

                int i = other.number.length() - 1;
                int j = number.length() - 1;

                while (i >= 0) {

                    int digit1 = other.number[i] - '0';
                    int digit2 = 0;

                    if (j >= 0) {
                        digit2 = number[j] - '0';
                    }

                    int difference = digit1 - digit2 - borrow;

                    if (difference < 0) {
                        difference += 10;
                        borrow = 1;
                    }
                    else {
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
    lhs += rhs;
    result = lhs;
    return result;
}

BigInt operator-(BigInt lhs, const BigInt& rhs) {
    BigInt result;
    lhs -= rhs;
    result = lhs;
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