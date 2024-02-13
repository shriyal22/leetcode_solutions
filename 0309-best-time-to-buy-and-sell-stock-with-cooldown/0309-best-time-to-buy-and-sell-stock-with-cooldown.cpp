class Solution {
public:
    int maxProfit(vector<int>& values) {
        int n = values.size();
    vector<vector<long>> dp(n+2, vector<long>(2, 0));
    for (int i= n-1;i>=0; i--){
        dp[i][1]= max(-values[i] + dp[i+1][0], dp[i+1][1]);
        dp[i][0]= max(values[i] + dp[i+2][1], dp[i+1][0]);
            
    }
    return dp[0][1] ;
    }
};