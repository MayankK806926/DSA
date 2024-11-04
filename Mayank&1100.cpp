//Here the use of bool won't works as we have to store the value where 1100 is present to solve the problem properly.
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        set<int> indices;
 
        for (int i = 0; i <= n - 4; ++i) {
            if (s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '0' && s[i + 3] == '0') {
                indices.insert(i);
            }
        }
 
        int q;
        cin >> q;
        while (q--) {
            int u;
            char v;
            cin >> u >> v;
            --u;
 
            s[u] = v;
 
            for (int i = max(0, u - 3); i <= min(n - 4, u); ++i) {
                if (s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '0' && s[i + 3] == '0') {
                    indices.insert(i);
                } else {
                    indices.erase(i);
                }
            }
 
            cout << (indices.empty() ? "NO" : "YES") << endl;
        }
    }
    return 0;
}
