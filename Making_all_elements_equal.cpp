//Decrease ai−1 by 1, then increase ai+1 by 1.
//Decrease ai+1 by 1, then increase ai−1 by 1.
#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
     ll t;
     cin>>t;
     while(t--){
          int n;
          cin>>n;
          vector<ll> v(n);
          ll sum=0;
          for(int i=0;i<n;++i){
               cin>>v[i];
               sum+=v[i];
          }
          int num=sum/n;
          if(sum%n!=0){
               cout<<"NO"<<endl;
               continue;
          };
          for(int i=1;i<n-1;++i){
               if(v[i-1]>num){
                    v[i+1]+=(v[i-1]-num);
                    v[i-1]=num;
               }
               if(v[i-1]<num){
                    v[i+1]-=(num-v[i-1]);
                    v[i-1]=num;
               }
          }
          if(v[n-1]==num) cout<<"YES"<<endl;
          else cout<<"NO"<<endl;
     }
}
