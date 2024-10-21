//Here sum of half array of even numbers is equal to sum of half array of odd numbers.

#include<bits/stdc++.h>
using namespace std;

int main(){
     int t;
     cin>>t;
     while(t--){
          int n;
          cin>>n;
          if(n%4!=0){
               cout<<"NO"<<endl;
               continue;
          }
          vector<int> v;
          int sum_even=0;
          for(int i=1;i<=n/2;++i){
               v.push_back(i*2);
               sum_even+=(i*2);
          }
          int sum_odd=0;
          for(int i=1;i<n/2;++i){
               v.push_back(2*i-1);
               sum_odd+=(2*i-1);
          }
          v.push_back(sum_even-sum_odd);
          cout<<"YES"<<endl;
          for(auto c:v) cout<<c<<" ";
          cout<<endl;
     }
}
