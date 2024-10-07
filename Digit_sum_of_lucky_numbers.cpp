//To construct a number of only 4 and 7 and sum of digits is n

#include<bits/stdc++.h>
using namespace std;

int main(){
     int n;
     cin>>n;
     for(int f=0;f<=(n/4);++f){
          int left_sum=n-(f*4);
          int s=0;
          if(left_sum%7==0){
               s+=left_sum/7;
               for(int i=0;i<f;++i) cout<<'4';
               for(int j=0;j<s;++j) cout<<'7';
               return 0;
          }
     }
     cout<<-1<<endl;;
}
