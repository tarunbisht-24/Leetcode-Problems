class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(m+1,-1)));
        int res = f(0,0,0,houses,cost,m,n,target,dp);
        if(res >= 1e8)
            return -1;
        return res;
	}

	int f(int i, int prevcol, int count, 
          vector<int>& houses, vector<vector<int>>& cost, int& m, int& n, 
          int& target, vector<vector<vector<int>>>& dp){
        if(count == target && i == m)
            return 0;
        if(i == m && count != target)
            return 1e8;
        if(dp[i][prevcol][count] != -1)
            return dp[i][prevcol][count];
        
        if(houses[i] != 0){
            if(prevcol != houses[i])
                return dp[i][prevcol][count] = f(i+1,houses[i],count+1,houses,cost,m,n,target,dp);
            else
                return dp[i][prevcol][count] = f(i+1,houses[i],count,houses,cost,m,n,target,dp);
        }
          
        int val = 1e8;
        for(int h = 0; h < n; h++){
            if(h+1 != prevcol)
                val = min(val,cost[i][h] + f(i+1,h+1,count+1,houses,cost,m,n,target,dp));
            else
                val = min(val,cost[i][h] + f(i+1,h+1,count,houses,cost,m,n,target,dp));
            dp[i][prevcol][count] = val;
        }
        
        return dp[i][prevcol][count];
    }
};
