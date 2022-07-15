class Solution {
public:

int dfs(int r, int c,vector<vector<int>>&grid){
    if(r<0||r>=grid.size() ||c<0||c>=grid[0].size()|| !grid[r][c])
        return 0;
    grid[r][c]=0;
    return (1+dfs(r+1,c,grid)+dfs(r,c+1,grid)+dfs(r,c-1,grid)+dfs(r-1,c,grid));
}
int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res=0;
    
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++)
            res=max(res,dfs(i,j,grid));
    }
    return res;
}
};
