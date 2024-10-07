//You are given three positive integers n, a and b. You have to construct a string s of length n consisting of lowercase Latin letters such that each substring of length a has exactly b distinct letters. 
//It is guaranteed that the answer exists.You have to answer t independent test cases.
//Recall that the substring s[l…r] is the string sl,sl+1,…,sr and its length is r−l+1. In this problem you are only interested in substrings of length a.


#include<bits/stdc++.h>
using namespace std;

int main(){
     int t;
     cin>>t;
     while(t--){
          int n,a,b;
          cin>>n>>a>>b;
          string s(n,'a');
          size_t s_size = (int) s.length();
          int ctr_substr = 1;
          int ctr_dist = 1;
          for (int i = 1; i < s_size; i++) {
               if (ctr_substr >= a) {
                    ctr_substr = 1;
                    ctr_dist = 1;
                    continue;
               }
               if (ctr_dist == b) {
                    ctr_substr++;
                    continue;
               }
               s.replace(i, 1, 1, (s[i - 1] + 1));
               ctr_substr++;
               ctr_dist++;
          }
          cout << s << endl;
     }
}
