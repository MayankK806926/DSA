vector<int> LIS(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return {};
    vector<int> dp(n, 1), hash(n);        
    for (int i = 0; i < n; ++i) hash[i] = i;
    int mx = 1, mx_ind = 0;
    for (int ind = 0; ind < n; ++ind) {
        for (int prev = 0; prev < ind; ++prev) {
            if (nums[ind] > nums[prev] && dp[prev] + 1 > dp[ind]) {
                dp[ind] = dp[prev] + 1;
                hash[ind] = prev;
            }
        }
        if (dp[ind] > mx) {
            mx = dp[ind];
            mx_ind = ind;
        }
    }
    vector<int> ans;
    while (hash[mx_ind] != mx_ind) {
        ans.push_back(nums[mx_ind]);
        mx_ind = hash[mx_ind];
    }
    ans.push_back(nums[mx_ind]);
    reverse(ans.begin(), ans.end());
    return ans;
}
