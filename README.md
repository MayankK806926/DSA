# Special and Interesting Problem Insights

This repository contains some unique and challenging problems that showcase interesting logic and efficient solutions.

## Key Concepts and Techniques

### 1. Digital Root Calculation
The **digital root** of a non-negative integer is the single-digit value obtained by repeatedly summing the digits until a single-digit number is reached.

---

### 2. Handling Odd and Even Numbers (int and float)
```cpp
int k = n / 2 + n % 2;
```

---

### 3. Simplifying Modulo Conditions
To avoid both n % m == 0 and m % n == 0, use:
```cpp
if (m > n) { 
    swap(s, t); 
    swap(n, m); 
}
```
---

### 4. Dynamic Input Handling for Unknown-Length Vector in C++
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ll t;
    cin >> t;
    cin.ignore();
    
    while (t--) {
        vector<int> v;
        string input;
        getline(cin, input);
        
        stringstream ss(input);
        int number;
        while (ss >> number) {
            v.push_back(number);
        }
    }
    return 0;
}
```
---

### 5. Subsequence and Subarray

Subarray/substring defines the contiguous part of array/strin.
Subsequence can be defined by deleting some or none of the elements without changing the order of the remaining elements.

---

### 6. Sort() in STL

The sort() function in STL has the nlog(n) Time Complexity.

---

### 7. To handle the condition of odd and even or the case of perfect division.

```cpp
int gap = len/2 + len%2;
```
---

### 8. getline() function

getline() is used for the input of a string only. If you are using getline() after using cin above, use cin.ignore(); to take all the inputs correctly.
```cpp
int t;
cin>>t;
cin.ignore();
string s;
getline(cin,s);
```
---

### 9. stringstream() function.

stringstream() function is used to iterate over each word of the string.
```cpp
string s;
getline(cin, s);
stringstream ss(s);
string word, result;
bool firstWord = true;
while (ss >> word) {
}
```
---

### 10. Modular Exponentiation by Squaring Method.

TC-> O(log exp) and SC-> O(1).
```cpp
ll mod_exp(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) { // If exp is odd
            result = (result * base) % mod;
        }
        base = (base * base) % mod; // Square the base
        exp /= 2; // Halve the exponent
    }
    return result;
}
```
---

### 11. Some common T.C.

The time complexity of initalizing a vector of size n with a value of x in C++ is O(n) and the space complexity is also O(n).

---

