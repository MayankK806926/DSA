#include<bits/stdc++.h>
using namespace std;

bool sol(long long n,long long m){
     if(n==m) return true;
     if(n%3) return false;
     return sol(n/3,m) || sol((2*n)/3,m);
}

int main(){
     int t;
     cin>>t;
     while(t--){
          long long n,m;
          cin>>n>>m;
          if(sol(n,m)) cout<<"YES"<<endl;
          else cout<<"NO"<<endl;
     }
}
