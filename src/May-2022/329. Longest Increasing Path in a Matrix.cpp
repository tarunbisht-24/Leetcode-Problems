class Solution {
public:
    
    int solve(vector<vector<int>>& matrix, int m, int n, vector<vector<int>>& memo, int prev, int i, int j){
        if(i<0 or i>=m or j<0 or j>=n or matrix[i][j]<=prev){
            return 0;
        }
        if(memo[i][j] != -1){
            return memo[i][j];
        }
        
        int l1 = solve(matrix, m, n, memo, matrix[i][j], i+1, j);
        int l2 = solve(matrix, m, n, memo, matrix[i][j], i, j+1);
        int l3 = solve(matrix, m, n, memo, matrix[i][j], i-1, j);
        int l4 = solve(matrix, m, n, memo, matrix[i][j], i, j-1);
        
        return memo[i][j] = 1 + max({ l1, l2, l3, l4 });
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        int result = 0;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                result = max(result, solve(matrix, m, n, memo, INT_MIN, i, j));
            }
        }        
        
        return result;
    }
};
