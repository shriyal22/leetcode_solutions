class Solution {
public:
    int solve(int len, int len_to_copy, int count, int n,  vector<vector<int>> &dp){
        if(len==n) return count;
        if(len > n || len + len_to_copy > n) return INT_MAX;
        if(dp[len][len_to_copy] != -1) return dp[len][len_to_copy];

        int copy = INT_MAX;
        int paste = INT_MAX;
        if(len_to_copy < len) copy = solve(len, len, count+1, n, dp);
        if(len_to_copy > 0) paste = solve(len+len_to_copy, len_to_copy, count+1, n, dp);

        return dp[len][len_to_copy] = min(copy, paste);
    }
    
    int minSteps(int n) {
        if(n==1) return 0;
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(1, 0, 0, n, dp);
    }
};