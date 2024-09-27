//Recursion to find subsequences whose sum is k

#include<bits/stdc++.h>
using namespace std;

void findCombination(int ind,int target,vector<int> &arr,vector<vector<int>> &ans,vector<int> &ds){
     if(target==0){
          ans.push_back(ds);
          return;
     }
     for(int i=ind;i<arr.size();++i){
          if(i>ind && arr[i]==arr[i-1]) continue;
          if(arr[i]>target) break;
          ds.push_back(arr[i]);
          findCombination(i+1,traget-arr[i],arr,ans,ds);
          ds.pop_back(arr[i]);
     }
}

int main(){
     int n,k;
     cin>>n>>k;
     vector<int> candidates(n);
     for(int i=0;i<n;++i){
          cin>>candidates[i];
     }
     vector<int> ds;
     vector<vector<int>> ans;
     findCombination(0,k,candidates,ans,ds);
     for(auto c:ans){
          for(auto a:c){
               cout<<a<<" ";
          }
          cout<<endl;
     }
}
