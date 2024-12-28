//MEMOIZATION(Top-Down) => Recursion to DP
//It is going from the required to the base case.
/*
Steps:
1.Initialize dp array to -1.
2.Store teh return values.
3.If dp[n]!=-1 return dp[n], else recurtive func.
*/
// TC-> O(n) & SC-> O(n) + O(n){recursion stack}

const long long int mod=1e9+7;
long long int f(int n, vector<long long int>& dp) {
    if(n==0 || n==1) return n;
    if (dp[n] != -1) return dp[n]; // Check memoization first
    return dp[n] = (f(n - 1, dp) + f(n - 2, dp))%mod;
}

long long int topDown(int n) {
    if (n <= 1) return n; // Base case for n <= 1
    vector<long long> dp(n + 1, -1);
    dp[0] = 0; dp[1] = 1; // Initialize base cases in dp
    return f(n, dp);
}


//TABULATION(Bottom-Up) =>Recursion to Table
//It is about going from base case to the required case.

//TC-> O(n) & SC-> O(n)
long long int bottomUp(int n) {
    vector<int> dp(n+1,-1);
    dp[0]=0;dp[1]=1;
    for(int i=2;i<=n;++i){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

//TC-> O(n) & SC-> O(1)
long long int bottomUp(int n) {
    if(n<=1) return n;
    long long int ans=0,prev1=0,prev2=1;
    for(int i=2;i<=n;++i){
        ans=(prev1+prev2)%mod;
        prev1=prev2;
        prev2=ans;
    }
    return ans;
}
