class Solution {
public:
    int t(int n,int x,int y,vector<int>& zero, vector<int>& one,vector<vector<vector<int>>>& dp){
        if(n<0) return 0;
        if(dp[n][x][y]!=-1) return dp[n][x][y];
        if(one[n]<=x and zero[n]<=y){  
            return dp[n][x][y]=max(
                t(n-1,x-one[n],y-zero[n],zero,one,dp)+1,  
                t(n-1,x,y,zero,one,dp)
                );
        }
        return dp[n][x][y]=t(n-1,x,y,zero,one,dp);  
    }
    int findMaxForm(vector<string>& s, int y, int x) {
        int n=s.size();
        vector<int> zero(n),one(n);
        for(int i=0;i<n;i++){
            int cnt=0;
            for(auto x:s[i])
                if(x=='0') cnt++;
            zero[i]=cnt;
            one[i]=s[i].size()-cnt;
        }
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (x+1,vector<int> (y+1,-1)));
        return t(n-1,x,y,zero,one,dp);
    }
};
