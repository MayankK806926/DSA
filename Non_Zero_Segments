#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    unordered_set<long long> s;
    s.insert(0);
    long long c = 0;
    long long a1 = 0;
    for (int i = 0; i < n; ++i){
        c += a[i];
        if (s.find(c) != s.end()){
            a1++;
            s.clear();
            s.insert(0);
            c = a[i];
        }
        s.insert(c);
    }
    cout << a1 << endl;
}
