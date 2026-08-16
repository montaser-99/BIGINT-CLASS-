# BigInt Class

A custom C++ `BigInt` class for handling arbitrarily large integers using string-based arithmetic and operator overloading.

## Project Overview

The `BigInt` class represents integers that can exceed the limits of built-in C++ integer types such as `int`, `long`, and `long long`.

Numbers are stored internally as strings, and arithmetic operations are performed digit-by-digit.

This project was implemented as part of a C++ Operator Overloading training module.

## Features

- Construction from `int64_t`
- Construction from strings
- Copy constructor
- Assignment operator
- Addition
- Subtraction
- Multiplication
- Division
- Modulus
- Unary `+`
- Unary `-`
- Pre-increment `++x`
- Post-increment `x++`
- Pre-decrement `--x`
- Post-decrement `x--`
- Equality comparison `==`
- Inequality comparison `!=`
- Less than `<`
- Less than or equal `<=`
- Greater than `>`
- Greater than or equal `>=`
- Input using `cin`
- Output using `cout`
- Negative number handling
- Leading zero removal
- Division-by-zero handling
- Very large integer arithmetic

## Technologies

- C++
- Visual Studio
- Standard C++ Library
- Operator Overloading
- String-based Arithmetic
- Object-Oriented Programming

## Project Structure

```text
BIGINT-CLASS-/
├── ConsoleApplication1/
│   └── ConsoleApplication1.cpp
├── ConsoleApplication1.slnx
├── .gitignore
└── README.md
Internal Representation

The BigInt class stores the number using two private members:

string number;
bool isNegative;

For example:

-12345

is internally represented as:

number     = "12345"
isNegative = true

Zero is always stored as:

number     = "0"
isNegative = false

Therefore, negative zero is not allowed.

Constructors
Default Constructor
BigInt a;

Creates:

0
Integer Constructor
BigInt a(12345);
BigInt b(-67890);
String Constructor
BigInt a("12345678901234567890");
BigInt b("-67890");
BigInt c("000123");

Leading zeros are automatically removed.

Copy Constructor
BigInt a(12345);
BigInt b(a);
Arithmetic Operations
Addition
BigInt a("12345");
BigInt b("-67890");


cout << a + b << endl;

Output:

-55545
Subtraction
BigInt a(12345);
BigInt b("-67890");


cout << a - b << endl;

Output:

80235
Multiplication
BigInt a("12345");
BigInt b("-67890");


cout << a * b << endl;

Output:

-838102050
Division
BigInt a("-67890");
BigInt b(12345);


cout << a / b << endl;

Output:

-5

Division is truncated toward zero.

Modulus
BigInt a(12345);


cout << a % BigInt(100) << endl;

Output:

45

The remainder follows the sign of the dividend.

-10 % 3  = -1
 10 % -3 =  1
 10 % 3  =  1
Division by Zero

Division by zero throws:

runtime_error("Division by zero")

Example:

try
{
    BigInt x(10);
    BigInt zero(0);


    cout << x / zero << endl;
}
catch (const runtime_error& e)
{
    cout << e.what() << endl;
}

Output:

Division by zero
Unary Operators
Unary Minus
BigInt a(5);


cout << -a << endl;

Output:

-5
Unary Plus
BigInt a(12345);


cout << +a << endl;

Output:

12345

Zero always remains positive.

Increment and Decrement

The class supports:

++x
x++
--x
x--

Example:

BigInt a(12345);


cout << ++a << endl;
cout << a-- << endl;
cout << a << endl;

Output:

12346
12346
12345
Comparison Operators

All standard comparison operators are supported:

==
!=
<
<=
>
>=

Example:

BigInt a(12345);
BigInt b(67890);


cout << (a < b) << endl;
cout << (a > b) << endl;

Output:

1
0

The comparison logic correctly handles positive and negative numbers.

Input and Output
Output
BigInt a("-123456789");


cout << a << endl;

Output:

-123456789
Input
BigInt a;


cin >> a;

The input can contain positive or negative integers.

Large Number Operations

The main purpose of the class is to support integers larger than built-in C++ integer types.

Large Addition
BigInt large1("12345678901234567890");
BigInt large2("98765432109876543210");


cout << large1 + large2 << endl;

Output:

111111111011111111100
Large Multiplication
BigInt large3("12345678901234567890");
BigInt large4("98765432109876543210");


cout << large3 * large4 << endl;

Output:

1219326311370217952237463801111263526900
Test Results

The implementation was tested using the required SRS test cases.

Constructors
a (from int): 12345
b (from string): -67890
c (zero): 0
d (copy of a): 12345
Arithmetic
a + b = -55545
a - b = 80235
a * b = -838102050
b / a = -5
a % 100 = 45
Relational Operators
a == d: 1
a != b: 1
a < b: 0
a > b: 1
c == 0: 1
Unary and Increment/Decrement
-a: -12345
++a: 12346
a--: 12346
a after decrement: 12345
Large Numbers
Very large addition: 111111111011111111100
Very large multiplication: 1219326311370217952237463801111263526900
Edge Cases
Division by zero correctly threw error: Division by zero
Multiplication by zero: 0
Negative multiplication: -15
Negative division: -3
Negative modulus: -1
Algorithms Used
Addition

Digit-by-digit addition from right to left with carry handling.

Subtraction

Digit-by-digit subtraction from right to left with borrowing.

Multiplication

Standard long multiplication using a result array.

Division

Long division using repeated subtraction for each digit.

Modulus

Calculates the remainder of division while preserving the sign of the dividend.

Edge Case Handling

The implementation handles:

Zero
Negative numbers
Negative zero
Leading zeros
Addition with different signs
Subtraction with different signs
Multiplication by zero
Division by zero
Modulus by zero
Numbers larger than long long
Incrementing and decrementing negative values
How to Run
Using Visual Studio
Clone the repository:
git clone https://github.com/montaser-99/BIGINT-CLASS-.git
Open the project directory.
Open:
ConsoleApplication1.slnx
Build the project.
Run the application.
Learning Objectives

This project demonstrates practical knowledge of:

C++ Object-Oriented Programming
Classes and Objects
Encapsulation
Constructors
Copy Constructor
Destructor
Assignment Operator
Operator Overloading
Friend Functions
Stream Operators
String Manipulation
Manual Arithmetic Algorithms
Signed Integer Arithmetic
Exception Handling
Leading Zero Normalization
Big Integer Arithmetic
