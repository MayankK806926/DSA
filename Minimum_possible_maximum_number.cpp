#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t;cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll ans=0;
        if(n==1) ans=k;
        else if(n==k) ans=1;
        else if(n>k){
            if(n%k) ans=2;
            else ans=1;
        }
        else{
            if(k%n) ans=(k/n)+1;
            else ans=k/n;
        }
        cout<<ans<<endl;
    }
}
