class Solution {
public:
    
    int dp[101][101];
    
    int paths(vector<vector<int>>& grid, int m, int n, int i, int j)
    {
        if(i == m && j == n)
        {
            if(grid[i][j] == 1) return 0;
            return 1;
        }
        
        if(dp[i][j] != INT_MAX-99) return dp[i][j];
        
        if(grid[i][j] == 1) return 0;
        
        int down = 0;
        int right = 0;
        
        if(i < m) down = paths(grid, m, n, i+1, j);
        if(j < n) right = paths(grid, m, n, i, j+1);
        
        return dp[i][j] = down + right;
        
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = 0, n = 0;
        
        for(int i=0; i<101; i++)
        {
            n = 0;
            for(int j=0; j<101; j++)
            {
                dp[i][j] = INT_MAX-99;
            }
        }
        
        return paths(grid, grid.size()-1, grid[0].size()-1, 0, 0);
    }
};
