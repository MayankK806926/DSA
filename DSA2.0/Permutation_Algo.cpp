#include <bits/stdc++.h>
using namespace std;
#define ll long long

void rec(vector<int> v,vector<bool> flag,int n,vector<vector<int>>& ans){
    if(v.size() == n){
        ans.push_back(v);
        return;
    }
    else{
        for(int i=0;i<n;++i){
            if(flag[i]) continue;

            flag[i] = true;
            v.push_back(i+1);
            rec(v,flag,n,ans);
            flag[i] = false;
            v.pop_back();
        }
    }
}

void solve() {
    int n;cin>>n;
    vector<vector<int>> ans;
    vector<int> v;
    vector<bool> flag(n,false);
    rec(v,flag,n,ans);

    for(auto& it:ans){
        cout<<"( ";
        for(auto& i:it) cout<<i<<" ";
        cout<<")\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
