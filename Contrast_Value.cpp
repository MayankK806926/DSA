//This is true, we have to take the local extrema and edge elements only, as they disrectly make the sum equal to contrast value.
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;cin>>n;
        vector<ll> v(n);
        ll contrast=0;
        for(int i=0;i<n;++i){
            cin>>v[i];
            if(i>0) contrast+=abs(v[i]-v[i-1]);
        }
        v.resize(unique(v.begin(),v.end())-v.begin());
        n=v.size();
        int ans=0;
        for(auto& c:v) cout<<c<<" ";
        cout<<endl;
        for(int i=0;i<n;i++){
            if(i==0||i==n-1||(v[i]>v[i+1]&&v[i]>v[i-1])||(v[i]<v[i+1]&&v[i]<v[i-1]))
                ans+=1;
        }
        cout<<ans<<endl;
    }
}
