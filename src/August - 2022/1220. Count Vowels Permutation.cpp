class Solution {
public:
    int countVowelPermutation(int n)
    {
        int m=1e9+7;
        int j;
        long ans=0;
        long dp[5][n+1];
        
        dp[0][1]=1,dp[1][1]=1,dp[2][1]=1,dp[3][1]=1,dp[4][1]=1;
        
        for(j=2;j<=n;j++)
        {
            dp[0][j]=(dp[1][j-1]+dp[2][j-1]+dp[4][j-1])%m;
            dp[1][j]=(dp[0][j-1]+dp[2][j-1])%m;
            dp[2][j]=(dp[1][j-1]+dp[3][j-1])%m;
            dp[3][j]=dp[2][j-1]%m;
            dp[4][j]=(dp[2][j-1]+dp[3][j-1])%m;
        }
        
        for(j=0;j<5;j++)
            ans=(ans+dp[j][n])%m;
        
        return ans;
    }
};
