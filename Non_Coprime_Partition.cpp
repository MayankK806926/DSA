// Find out if it is possible to partition the first n positive integers into two non-empty disjoint sets S1 and S2 such that: gcd(sum(S1),sum(S2))>1
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n;cin>>n;
    if(n<3){
        cout<<"No"<<endl;
    }
    else{
        cout<<"Yes"<<endl;
        cout<<1<<" "<<n<<endl;
        cout<<n-1<<" ";
        for(int i=1;i<n;++i) cout<<i<<" ";
        cout<<endl;
    }
}
