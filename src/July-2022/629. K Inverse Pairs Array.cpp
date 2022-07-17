class Solution {
public:
    int dp[1001][1001];
    int mod = 1e9+7;
     int helper(int n, int k){
         if(k<=0) return !k;
         if(n<=0) return 0;
         if (dp[n][k] != -1) return dp[n][k];
         
         dp[n][k] = (helper(n-1,k) + helper(n,k-1))%mod;
         return dp[n][k] = (dp[n][k] - helper(n-1, k-n) + mod)%mod;
     }
    
    int kInversePairs(int n, int k) {
        memset(dp, -1, sizeof(dp));
        return helper(n,k);
    }
};
