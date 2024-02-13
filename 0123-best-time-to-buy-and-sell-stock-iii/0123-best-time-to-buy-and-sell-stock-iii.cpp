class Solution {
private: 
    int f(int i, int buy, int t, vector<int> prices, int n, vector<vector<vector<int>>> &dp){
        if(i==n) return 0;
        if(t==0) return 0;

        if(dp[i][buy][t] != -1) return dp[i][buy][t];

        int profit = 0;
        if(buy){
            profit = max(-prices[i] + f(i+1, 0, t, prices, n, dp),
            f(i+1, 1, t, prices, n, dp));
        }
        else profit = max(prices[i] + f(i+1, 1, t-1, prices, n, dp), 
        f(i+1, 0, t, prices, n, dp));

        return dp[i][buy][t] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        vector<vector<int>> ahead (2, vector<int>(3, 0));
        // vector<vector<int>> curr (2, vector<int>(3, 0));

        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int t=1;t<=2;t++){
                    if(buy) ahead[buy][t] = max(-prices[i] + ahead[0][t], ahead[1][t]);
                    else ahead[buy][t] = max(prices[i] + ahead[1][t-1], ahead[0][t]);
                }
                // ahead = curr;
            }
        }

        return ahead[1][2];
    }
};