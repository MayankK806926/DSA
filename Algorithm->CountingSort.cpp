#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    string arr;cin>>arr;
    map<int,int> hsh;
    for(auto i:arr){
        hsh[i-'a']++;
    }
    int sum = 0;
    for (auto &p : hsh) {
        sum += p.second;
        p.second = sum;
    }
    map<int,int> temp=hsh;
    int prev_value=hsh[0];
    hsh[0]=0;
    auto it=temp.begin();
    for(auto& p:hsh){
        if(p.first==0) continue;
        p.second=prev_value;
        prev_value=temp[p.first];
    }
    string ans=arr;
    for(auto i:arr){
        ans[hsh[i-'a']]=i;
        hsh[i-'a']++;
    }
    cout<<ans<<endl;
}
