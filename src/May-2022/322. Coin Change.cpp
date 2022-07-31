class Solution {
public:
    
    int coinChange(vector<int>& coins, int amt) {
        vector<int> dp(amt+1 , 10001);
        dp[0] = 0;
        for(int i = 1;i<=amt;i++){
            for(int j = 0;j<coins.size();j++){
                if(i>=coins[j])
                    dp[i] = min(dp[i],dp[i-coins[j]]+1);
            }
        }
        return dp[amt] == 10001? -1: dp[amt];
    }
};
