//TC-> O(n*log(sum-max))
#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool f(ll mid,vector<int>& v,int n,int m){
    ll last=0;int cnt=1;
    for(int i=0;i<n;++i){
        if(last+v[i]<=mid){
            last+=v[i];
        }
        else{
            last=v[i];cnt++;
        }
    }
    if(cnt>m) return true;
    return false;
}

int main(){
    int n,m;cin>>n>>m;
    vector<int> v(n);
    for(int i=0;i<n;++i){
        cin>>v[i];
    }
    if(m>n){
        cout<<-1<<endl;
        return 0;
    }
    ll l=*max_element(v.begin(),v.end());
    ll r=accumulate(v.begin(),v.end(),0LL);
    while(l<=r){
        ll mid=l+(r-l)/2;
        bool value=f(mid,v,n,m);
        if(value) l=mid+1;
        else r=mid-1;
    }
    cout<<l<<endl;
}
