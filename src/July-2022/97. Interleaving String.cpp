class Solution {
private:
    
    int dp[105][105][205];
    
    bool isPossible(int i,int j,int k,string &s1, string &s2,string &s3)
    {
        if(k==s3.size())
        {
            if(i == s1.size() && j == s2.size()) return true;
            else return false;
        }
        if(i>s1.size() || j>s2.size()) return false;
        
        if(dp[i][j][k] != -1) return dp[i][j][k];

        bool flag = false;
        
        if(s1[i] == s3[k]){
            flag = flag || isPossible(i+1,j,k+1,s1,s2,s3);
        }
        if(s2[j] == s3[k])
        {
            flag = flag || isPossible(i,j+1,k+1,s1,s2,s3);
        }
        
        return dp[i][j][k] = flag;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        memset(dp,-1,sizeof(dp));
        if(n1 + n2 != n3) return false;

        return isPossible(0,0,0,s1,s2,s3); 
    }
};
