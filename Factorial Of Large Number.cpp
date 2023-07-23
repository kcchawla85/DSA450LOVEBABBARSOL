#include <bits/stdc++.h>

string multiplyStrings(const string& num1, const string& num2) {
    int len1 = num1.length();
    int len2 = num2.length();
    std::vector<int> result(len1 + len2, 0);

    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + result[i + j + 1];

            result[i + j] += sum / 10;
            result[i + j + 1] = sum % 10;
        }
    }

    string product;
    bool leadingZero = true;
    for (int digit : result) {
        if (digit != 0)
            leadingZero = false;

        if (!leadingZero)
            product.push_back(digit + '0');
    }

    return product.empty() ? "0" : product;
}

string calculateFactorial(int n) {
   

    string factorial = "1";
    for (int i = 2; i <= n; i++) {
        factorial = multiplyStrings(factorial, to_string(i));
    }

    return factorial;
}
/*
Algorithm: Factorial Calculation

1.  with a function multiplyStrings(num1, num2) to multiply two strings representing integers.
2. Initialize an empty string variable factorial to store the result.
3. Initialize factorial to "1" since the factorial of 0 is 1.
4. For each number i from 2 to n inclusive, do the following:
  .Convert i to a string and call it num_str.
  .Multiply the current factorial with num_str using the multiplyStrings function and update factorial with the result.
5. After the loop, factorial will contain the factorial of n as a string.
6. Return the factorial string as the final result.

Pseudo :
function multiplyStrings(num1, num2):
    result = array of zeros of size len(num1) + len(num2)

    for i from len(num1) - 1 to 0:
        for j from len(num2) - 1 to 0:
            mul = (num1[i] - '0') * (num2[j] - '0')
            sum = mul + result[i + j + 1]

            result[i + j] += sum / 10
            result[i + j + 1] = sum % 10

    product = empty string
    leadingZero = true
    for digit in result:
        if digit != 0:
            leadingZero = false

        if not leadingZero:
            append (digit + '0') to product

    return product if product is not empty else "0"


function calculateFactorial(n):
    if n < 0:
        return "Invalid input"

    factorial = "1"
    for i from 2 to n:
        num_str = convert i to a string
        factorial = multiplyStrings(factorial, num_str)

    return factorial

*/
