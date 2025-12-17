#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;cin>>n;
        ll cnt = 1;
        while(n > 0){
            ll d = n % 10;
            n /= 10;
            ll mul = 0;
            for(ll i=0;i<=d;++i){
                for(ll j=0;j<=d;++j){
                    if(d-i-j >= 0) mul++;
                }
            }
            cnt *= mul;
        }
        cout<<cnt<<endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
/*
Here is a complete, structured explanation of the logic behind your method, formatted in Markdown. You can copy-paste this directly into your GitHub `README.md` or a solution file.

---

# Solution Logic: Good Triples

## 1. Core Mathematical Insight: The "No-Carry" Property

The problem asks us to find the number of triples (a, b, c) such that:

1. a + b + c = n
2. \text{digsum}(a) + \text{digsum}(b) + \text{digsum}(c) = \text{digsum}(n)

In standard addition, whenever a "carry" occurs (e.g., 5+5=10), the sum of digits decreases. Specifically, a carry of 1 reduces the digit sum by 9 (10 \rightarrow 1+0=1).
Therefore, for the sum of the digits of the parts to exactly equal the sum of the digits of n, **the addition must occur without any carries at any position.**

## 2. Independence of Digits

Because carries are forbidden, the choice of numbers for one digit position (e.g., the ones place) does not affect the next position (e.g., the tens place).
This allows us to break the problem down:

* We can analyze each digit of n individually.
* Calculate the number of ways to split that specific digit d into 3 parts (i, j, k).
* Multiply the results for all digits to get the total count (Rule of Product).

## 3. Algorithm: Step-by-Step

The solution processes the input number n digit by digit (from right to left).

### Step A: Extract Current Digit

We use a loop `while(n > 0)` to extract the last digit d:

```cpp
ll d = n % 10;
n /= 10;

```

### Step B: Brute-Force Local Combinations

For the current digit d, we need to find how many non-negative integer triples (i, j, k) satisfy:


Since d is small (0 \le d \le 9), we can use a brute-force approach with nested loops:

1. **Loop `i` from 0 to d:** Represents the digit contribution from number a.
2. **Loop `j` from 0 to d:** Represents the digit contribution from number b.
3. **Check `k`:** The third digit is determined by k = d - i - j. If k \ge 0, this is a valid combination.

```cpp
ll mul = 0;
for(ll i=0; i<=d; ++i){
    for(ll j=0; j<=d; ++j){
        if(d-i-j >= 0) mul++;
    }
}

```

*The variable `mul` now stores the number of valid splits for this specific digit.*

### Step C: Aggregate the Result

Since the choices for each digit position are independent events, we multiply the count of ways for the current digit (`mul`) into our running total (`cnt`).

```cpp
cnt *= mul;

```
## 4. Complexity Analysis
* **Time Complexity:** O(\log_{10} n).
* The outer loop runs once for each digit of n (up to 8 times for n \le 10^7).
* The inner loops run at most 10 \times 10 = 100 times (since max digit is 9).
* This is effectively constant time per test case.


* **Space Complexity:** O(1). We only use a few variables for storage.
*/

// OR 


#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;

        ll cnt = 1;
        while(n > 0){
            ll d = n % 10;
            n /= 10;
            ll combinations = (d + 1) * (d + 2) / 2;
            cnt *= combinations;
        }
        cout << cnt << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
