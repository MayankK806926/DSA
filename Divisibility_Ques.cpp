#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
     ll t;
     cin >> t;
     while (t--) {
          int n, d;
          cin >> n >> d;
          // 1 always
          cout << 1 << ' ';
          // 3
          if (d % 3 == 0 || n >= 3) {
               cout << 3 << ' ';
          }
          // 5
          if (d % 5 == 0) {
               cout << 5 << ' ';
          }
          // 7
          if (d % 7 == 0 || n >= 3) {
               cout << 7 << ' ';
          }
          // 9
          if (d % 9 == 0 || (n >= 6) || (n >= 3 && d % 3 == 0)) {
               cout << 9 << ' ';
          }
          cout << endl;
     }
}
