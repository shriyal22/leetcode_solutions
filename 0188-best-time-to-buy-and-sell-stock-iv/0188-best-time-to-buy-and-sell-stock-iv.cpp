class Solution {
private:
    int f(int i, int t, vector<int> prices, int n, int k, vector<vector<int>> &dp){
        if(i==n || t==2*k) return 0;

        if(dp[i][t] != -1) return dp[i][t];

        if(t%2 == 0) return dp[i][t] =  max(-prices[i] + 
        f(i+1, t+1, prices, n, k, dp), f(i+1, t, prices, n, k, dp));
        else return dp[i][t] = max(prices[i] + f(i+1, t+1, prices, n, k, dp),
        f(i+1, t, prices, n, k, dp));
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> ahead (2*k+1, 0);
        // vector<int> curr (2*k+1, 0); 
        for(int i=n-1;i>=0;i--){
            for(int t=2*k-1;t>=0;t--){
                if(t%2 == 0) ahead[t] =  max(-prices[i] + ahead[t+1], 
                ahead[t]);
                else ahead[t] = max(prices[i] + ahead[t+1], ahead[t]);
            }
            // ahead = curr;
        }

        return ahead[0];
    }
};