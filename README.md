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

### 5.Subsequence & Subarray
Subarray/substring defines the contiguous part of array/strin.
Subsequence can be defined by deleting some or none of the elements without changing the order of the remaining elements.
---

