#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
bool f(int mid,vector<ll>& v,ll n,ll k){
    ll sum=0;
    for(int i=0;i<=mid;++i){
        sum+=(v[i+1]-v[i])*(n-i);
        if(sum>=k) return true;
    }
    return false;
}
 
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        vector<ll> v(n+1,0);
        for(int i=1;i<=n;++i){
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        int l=0,r=n-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            // cout<<l<<" "<<r<<" "<<mid<<endl;
            bool value=f(mid,v,n,k);
            if(value) r=mid-1;
            else l=mid+1;
        }
        cout<<k+l<<endl;
        // int x=0;
        // for(int i=0;i<n;++i){
        //     if(f(i,v,n,k)){
        //         x=i;break;
        //     }
        // }
        // cout<<k+x<<endl;
    }
}
