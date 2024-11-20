// Your task is to find positive integers a, b and c such that x=max(a,b), y=max(a,c) and z=max(b,c), or determine that it is impossible to find such a, b and c.
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll t;
    cin>>t;
    while(t--){
        vector<int> v(3);
        cin>>v[0]>>v[1]>>v[2];
        sort(v.begin(),v.end());
        if(v[1]==v[2]){
            cout<<"YES"<<endl;
            cout<<v[0]<<" "<<v[0]<<" "<<v[2]<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}
