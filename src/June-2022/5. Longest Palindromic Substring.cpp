class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        
        for(int i=0;i<n;i++){
            dp[i][i]=1;
        }
        int l=0,h=1;
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=1;l=i;h=2;
            }
                
        }
        for(int j=2;j<n;j++){
            for(int i=0;i<n-j;i++){
                int st=i,e=i+j;
                if(dp[st+1][e-1]==1 && s[st]==s[e]){
                    dp[st][e]=1; l=i; h=j+1;
                }
            }
        }
        return s.substr(l,h);
        
    }
};
