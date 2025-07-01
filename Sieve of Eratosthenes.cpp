// Time Complexity: O(n*log(log(n)))
// Auxiliary Space: O(n)
class Solution {
  public:
    vector<int> sieve(int n) {
        vector<bool> prime(n+1,true);
        for(int p=2;p*p<=n;++p){
            if(prime[p]){
                for(int i=p*p;i<=n;i+=p){
                    prime[i]=false;
                }
            }
        }
        
        vector<int> ans;
        for(int i=2;i<=n;++i){
            if(prime[i]) ans.push_back(i);
        }
        return ans;
    }
};
